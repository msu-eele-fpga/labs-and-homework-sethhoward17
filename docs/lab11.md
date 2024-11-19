# Lab 11: Platform Device Driver

## Overview
In Lab 11, we created a linux platform device driver for our LED patterns that allowed us to read and write to the registers from PuTTY in different ways. We first created a miscdev C program to recreate our custom LED pattern from earlier in the semester. We then added sysfs show and store functions that allowed us to echo to the registers from the command line. Finally, we created bash scripts to write to the registers that could be executed from the command line.

## Deliverables

> What is the purpose of platform bus?

The platform bus informs the operating system about connected hardware that is not automatically discoverable. Busses like USB and PCI are discovered automatically while our LED Patterns component is not. The platform bus allows the OS to be aware of our component and what resources we want to have available for it.

> Why is the device driver's compatible property important?

The compatible property in the device driver is what tells the kernel to bound the driver to the correct device. The device tree subsystem informs the kernel that there is an LED Patterns device in existence, and the kernel can then match the device tree node to the device driver if the compatible strings match.

> What does the probe function do?

When a device is bound to the driver, the probe function gets called. This function should hold the functionality that you want executed when you load the driver.

> How does your driver know what memory addresses are associated with your device?

The base address of our component was written in the device tree node, and the offset for each register was declared at the beginning of the device driver program. The span of the memory was also declared in the device driver.

> What are the two ways we can write to our device's registers? In other words, what subsystems do we use to write to our registers?

We can write to the registers through file operations or through exported attribute files. By defining read/write file operations, values can be written to the registers by pointing to the memory location in the device driver. With exported attribute files, the registers appear as files in the user space and values can be echoed into the files.

> What is the purpose of our `struct led_patterns_dev` state container?

This structure holds the state of our device, including the addresses and values in the registers. Any information we want to keep track of is decaled in the state container. The state can then be passed to any function that needs to read or modify the state of the device.
