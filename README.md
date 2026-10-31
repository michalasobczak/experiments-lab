# retro-lab

Hobby experiments from 2005–2019: retro computers, bare-metal x86, a hand-made 3D engine and a microcontroller.
They share one idea — take the same simple 3D math (rotation matrices, a camera, perspective division) and see how far it goes on very different hardware, from a phone browser to a 1 MHz 8-bit computer.
All of it was written by hand, without AI. Each folder used to be a separate repository; its full commit history is kept here.

## [js3d-engine](js3d-engine) — a 3D engine in JavaScript (2013)

A small 3D engine written from scratch for Android and Windows Phone browsers, with no WebGL and no 3D library: everything is plain JavaScript drawing on a 2D canvas. It loads OBJ models into a world made of square tiles, textures faces from a BMP file, sorts models by distance (painter's algorithm instead of a z-buffer), shades faces by their distance from the camera and checks simple collisions. Rotation matrices and trigonometry are cached, because on a 2013 phone even colour conversion was expensive.
This engine is the reference implementation for every port below. On an Intel Atom tablet it projects 5,000–10,000 vertices per second.
→ [Write-up](https://michalasobczak.pl/posts/generic-3d-engine-in-javascript-ported-to-esp8266.html)

## [c64](c64) — Commodore 64: restoration and 3D in three languages (2018)

A boxed Commodore 64, taken apart, cleaned and restored (photo log in [restoration](c64/restoration)), then programmed to render the same rotating 3D wireframe three times:
- **BASIC 2.0** — the projection math alone, timed in ticks, to see how expensive it is before drawing anything; plus entering bitmap mode with two `POKE`s,
- **C with cc65** — a cube of vertices and faces, redrawn on key press, with cc65's slow TGI library replaced by direct VIC-II and CIA register access,
- **6502 assembly with DASM** — the fastest of the three.

Developed in the VICE emulator and checked on the real machine through S-Video and a USB frame grabber.
→ [Write-up](https://michalasobczak.pl/posts/commodore-64-restoration-and-3d-in-basic-c-and-assembly.html)

## [x86-bootloader](x86-bootloader) — graphics with no operating system (2005, 2018)

Two programs that run straight on the CPU after the BIOS hands over control: no OS, no libc, no drivers — just NASM assembly, BIOS interrupts and video memory at `0xA0000`. Both boot from a floppy image in Bochs or on real hardware.
- **protected-mode-2d** (written around 2005) — a boot sector that loads the program from disk, sets up a minimal GDT and switches to 32-bit protected mode; the program then draws animated shapes, lines and a logo with PC-speaker sound, double-buffered and copied to the screen with MMX registers, 64 bytes per loop.
- **real-mode-3d** — Bresenham lines and a 3D-to-2D projection squeezed into a single 512-byte boot sector.

→ [Write-up](https://michalasobczak.pl/posts/x86-bootloader-2d-and-3d-graphics-in-nasm.html)

## [esp8266](esp8266) — 3D math on a microcontroller (2018)

The projection part of js3d-engine rewritten in Lua for the NodeMCU firmware on an ESP8266 — a Wi-Fi chip with a 32-bit Tensilica core and 80 KB of data RAM. There is no display: the chip computes projected vertices and reports them over the serial console, with free heap measured before and after. It uses fixed-point integers, so it runs on both integer and float firmware builds. Result: 300 vertices per second at 80 MHz, 600 at 160 MHz. The folder also documents building, flashing and recovering the firmware.

## License

[MIT](LICENSE)
