# Lab 7: System Console and /dev/mem

## Overview
For Lab 7, the functionality of my custom component was tested in a variety of ways. First, the System Console debugging tool in Quartus was used to read and write to the registers of the Avalon component. After confirming proper operation of the registers, the component was tested again though the UART port on the FPGA and a PuTTY terminal. The existing devmem command was used first, then I created my own devmem.c executable in Ubuntu VM. This file was moved onto the SD card and tested via the FPGA UART port and a PuTTY terminal again. In each case, the commands read and wrote to the registers successfully.

## Questions
>What hex value did you write to base_period to have a 0.125 second base period?

A hex value of 0x2 was written to base_period to set a base period of 0.125 seconds.

>What hex value did you write to base_period to have a 0.5625 second base period?

A hex value of 0x9 was written to base period to set a base period of 0.5625 seconds.