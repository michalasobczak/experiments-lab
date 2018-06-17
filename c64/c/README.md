# c

The C language for Commodore 64 made possible by using cc65 package which includes compiler, assembler and linker.

## Introduction

To compile, run the following command:

```cl65 -r -O main.c -t c64```

cl65 is a utility which combines all necessary steps for producing valid binary application for C64 hardware (as well as other 6502). Effectively you will get a ```main``` file which can be loaded to VICE emulator. Because cl65 generates BASIC compatible header, it is enough just to do regular ```Autostart disk/tape image...``` option from ```File``` menu.

```r``` argument allows ```register``` variable storage class to be used in program. It is said that up to 6 register variables can be defined in single function.

One may notice that binary code generated with this tool is way bigger comparing to similar things made in plain assembly. Further research will be made regarding this matter.

## Importing Blender-made model

To import custom OBJ model file made in Blender you need to run as follows:

```
cd models
ruby 0_parsed.rb your_file.obj 
```

Output from this command should include vertices list, vertices count and faces list. Need to copy and paste into ```main.c``` file in the ```Data->Model``` section. Please note that having lot of vertices gives C64 hardware will take time to compute. Drawing part is reasonable fast comparing to computational one.

## Environment

```generic``` based perspective projection and completely new ortographic projection.

## Roadmap

Next thing worth considering is to modify current vertices connection drawing to make it more like faces drawing so vertices will be grouped just as in the OBJ file. This would be a great preparation for further coloring and maybe even texturing.
