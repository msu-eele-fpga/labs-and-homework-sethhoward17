# Lab 10: Device Trees

## Overview
In this lab, a device tree was used to describe the hardware that we wanted to use upon booting te FPGA. An LED patterns device tree was created and compiled in the linux kernel created in homework 8. The hps LED on the FPGA could then be controlled from the command line in PuTTY. Finally, the configuration of the kernel was reconfugred to trigger the hps LED in a heartbeat fashion upon boot. The kernel was recompiled and the new zImage was copied onto the tftp server. The heartbeat trigger was then demonstarted upon booting the FPGA.

## Deliverables

> What is the purpose of a device tree?

Device trees are useful for describing the devices in a system without hard coding the details of every device. The structure of a device tree has nodes that can describe the characteristics of each piece of hardware being included in the system. This helps us inform Linux about the custom hardware components we would like to include and how to interact with them.