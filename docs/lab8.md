# Lab 8: Creating LED Patterns with a C Program

## Overview
In lab 8, an led-patterns.c file was created that could be called on the FPGA through a UART terminal and could write patterns to the LEDs. The program included a help menu, alongside functionality to read directly from the command line as well as from a text file. A verbose command could also be called that printed the patterns and the duration of the patterns as they were written to the registers.

## Deliverables

A README.md file was created for the led-patterns.c program and can be found in the link below.

[Link to README.md](../sw/led-patterns/README.md)

## Calculating Addresses of Registers
In the led-patterns.c file, the address of the hps_led_control register as well as the led_reg register were hard coded. Each register is 32 bits, or 4 bytes, long. The HPS-to-FPGA bridge has a base address of 0xFF20_0000, meaning the location of the registers in the hardware control code are relative to this base address. In my led_patterns_avalon VHDL code, the led_reg register was in the second memory slot and the hps_led_control register was in the third memory slot. Since each register is 4 bytes long, this would place their addresses at 0xFF20_0004 and 0xFF20_0008 respectively.