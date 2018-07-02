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

## Memory map
Starting from ```0x0400 (1024d)``` which is ```text screen``` we have probably until ```0x7FF (2047d)```. Then we have ```0x800 (2048d)``` where our ```program``` begins. Somewhere beetwen ```0x22E9 (8937d)``` and
```0xCFFF (53247d)``` there is ```empty space``` which should be further allocatable. 

```Stack``` grows downwards from ```0xCFFF (53247d)```. Over there we have automatic variables and calling information stored. It adjoins ```heap``` space which grows upwards in memory and stores all the dynamic memory allocations. 

Starting from ```0xD000 (53248d) we have ```VIC-II configuration``` which lasts at ```0xD3FF (54271d)```.

Enabled by default:

```
  I/O:
    $DE00-$DEFF, 56832-57087
    $DF00-$DFFF, 57088-57343
  KERNAL ROM:
    $E000-$FFFF, 57344-65535
```

Unsure about the following:

```
  SID:
    $D400-$D7FF, 54272-55295
  CIA: 
    $DC00-$DCFF, 56320-56575
    $DD00-$DDFF, 56576-56831
```    
    

## Environment

```generic``` based perspective projection and completely new ortographic projection.

## Roadmap

Next thing worth considering is to modify current vertices connection drawing to make it more like faces drawing so vertices will be grouped just as in the OBJ file. This would be a great preparation for further coloring and maybe even texturing.
