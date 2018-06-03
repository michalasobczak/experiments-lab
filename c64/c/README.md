# c

The C language for Commodore 64 made possible by using cc65 package which includes compiler, assembler and linker.

To compile, run the following command:

```cl65 -O main.c -t c64```

cl65 is a utility which combines all necessary steps for producing valid binary application for C64 hardware (as well as other 6502). Effectively you will get a ```test``` file which can be loaded to VICE emulator. Because cl65 generates BASIC compatible header, it is enough just to do regular ```Autostart disk/tape image...``` option from ```File``` menu.

One may notice that binary code generated with this tool is way bigger comparing to similar things made in plain assembly. Further research will be made regarding this issue. 
