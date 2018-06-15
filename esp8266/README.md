# esp8266

Espressif-made microchip based on L106 32-bit RISC Tensilica Xtensa microprocessor. Having 32-64 KB of instruction RAM and 80 KB of data RAM running at 80 or 160 MHz. Harvard type architecture.


## Firmware

The best available option is to  get NodeMCU firmware with Lua support. In order to build firmware with the selected modules only, go for NodeMCU custom builds online service. To upload firmware, use ```nodemcu-flasher```. Please note that you can choose between integer or float based firmware. Main file should point to ```0x00000```. Moreover you need ```esp_init_data_default.bin``` empty file starting from ```0xfc000```. Default baudrate is set to ```115200```.

Initial run will yield the following:

```Formatting file system. Please wait...```


## Runtime

In order to upload source code to hardware you can use ESPlorer. In case of uploading sources that blocks hardware you can use the following command to erase flash:

```python esptool.py -p COM3 -b 115200 erase_flash```

Script can be found in nodemcu-firmware repository. After this you need to put firmware once again on hardware.


## Performance
At ```80 MHz``` clock speed it reaches 300 vertices per second. Changing CPU clock speed to ```160 MHz``` it yields 600 vertices per second. Program starts from ```41424 KB``` of free heap space and ends with ```24792 KB```.


## Objectives

3D environment calculations to compare performance across various devices.
