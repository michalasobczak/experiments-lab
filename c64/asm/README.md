# c64

Commodore C64 research and development using assembly language. 

To run assembly procedure you need to obtain DASM macro assembler and type the following:

```
dasm main.asm -v3
```

The last parameter tell how verbose assembler should be. We will then see various useful information such as number of passes, segment and symbols details. The easiest way to run the generated binary is to launch it thru VICE emulator. If possible you can run it also on real hardware.

Launch VICE and go to File, Autostart disk / tape image... and select application binary file. After C64 boot procedure finishes and BASIC prompt is available, type the following:

```
SYS 4096
```

This indicates from which part of memory the computer will start execution.
