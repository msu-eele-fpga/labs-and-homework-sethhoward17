# LED-Patterns Usage and Building

## Usage
`$./led-patterns [OPTION] ... [PATTERN][TIME] OR [FILE]`

> :memo: **-h** Help: Print usage syntax and possible commands.  

> :memo: **-v** Verbose: Print binary string of LED patterns and display duration.  

> :memo: **-p** Pattern: Input hexidecimal patterns and display duration in miliseconds from the command line.  

> :memo: **-f** File: Input a filename with hexidecimal patterns and durations.

### Examples
`$./led-patterns -f file.txt`

`$./led-patterns -v -p 0xFF 500 0xF0 1000 0x0F 500` 

## Building

### Compiling
To compile the led-patterns.c file and run it on the de10nano FPGA, it must be cros-compiled in a virtual machine. With a virtual machine window open and the led-patterns.c file available, the following command will cross-compile the code.

`$arm-linux-gnueabihf-gcc -o led-patterns -Wall -static led-pattenrs.c`

This will create a linux executable that can be called on the FPGA. This executable can be copied onto the SD card of the FPGA from the virtual machine.

### Running led-patterns
The program assumes the FPGA has been programmed with the hardware control code. To ensure this is the case, a raw binary file (.rbf) can be created in Quartus and copied onto the FAT32 partition of the FPGA's SD card. By naming the .rbf file "soc_system.rbf", the FPGA will program itself with the led-pattern bitstream from the VHDL code written for the hardware control. The led-patterns.c code can then be called and the registers will be written to successfully.