#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/mman.h> // for mmap
#include <fcntl.h> // for file open flags
#include <unistd.h> // for getting the page size
#include <ctype.h> // for argument parsing
#include <signal.h> // for terminating program with CTRL-C
#include <string.h> // for string copying

// devmem function to write to registers
void devmem(uint32_t address, uint32_t value)
{
    //devmem components
    const size_t PAGE_SIZE = sysconf(_SC_PAGE_SIZE);
    const uint32_t ADDRESS = address;
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    uint32_t page_aligned_addr = ADDRESS & ~(PAGE_SIZE - 1);
    uint32_t *page_virtual_addr = (uint32_t *)mmap(NULL, PAGE_SIZE,
    PROT_READ | PROT_WRITE, MAP_SHARED, fd, page_aligned_addr);
    uint32_t offset_in_page = ADDRESS & (PAGE_SIZE - 1);
    volatile uint32_t *target_virtual_addr = page_virtual_addr + offset_in_page/sizeof(uint32_t*);
    const uint32_t VALUE = value;
    *target_virtual_addr = VALUE;
}

// Print usage commands for the help message
void help()
{
    printf("Usage: led-patterns [OPTION] ... ([PATTERN] [TIME]) OR ... ([FILE])\n\n");
    printf("-h, help      Print usage syntax and possible commands.\n");
    printf("-v, verbose   Print binary string of LED patterns and display duration.\n");
    printf("-p, pattern   Input hexidecimal patterns and display durations from the command line.\n");
    printf("-f, file      Input a filename with hexidecimal patterns and durations.\n\n");
}

// Print LED Pattern as a binary string and display duration for the verbose message
void verbose(uint32_t p, uint32_t t)
{
    switch (p) 
    {    
        case 0x00:
            printf("LED Pattern = 00000000  Display time = %u ms\n", t);
            break;
        case 0x01:
            printf("LED Pattern = 00000001  Display time = %u ms\n", t);
            break;
        case 0x02:
            printf("LED Pattern = 00000010  Display time = %u ms\n", t);
            break;
        case 0x03:
            printf("LED Pattern = 00000011  Display time = %u ms\n", t);
            break;
        case 0x04:
            printf("LED Pattern = 00000100  Display time = %u ms\n", t);
            break;
        case 0x05:
            printf("LED Pattern = 00000101  Display time = %u ms\n", t);
            break;
        case 0x06:
            printf("LED Pattern = 00000110  Display time = %u ms\n", t);
            break;
        case 0x07:
            printf("LED Pattern = 00000111  Display time = %u ms\n", t);
            break;
        case 0x08:
            printf("LED Pattern = 00001000  Display time = %u ms\n", t);
            break;
        case 0x09:
            printf("LED Pattern = 00001001  Display time = %u ms\n", t);
            break;
        case 0x0A:
            printf("LED Pattern = 00001010  Display time = %u ms\n", t);
            break;
        case 0x0B:
            printf("LED Pattern = 00001011  Display time = %u ms\n", t);
            break;
        case 0x0C:
            printf("LED Pattern = 00001100  Display time = %u ms\n", t);
            break;
        case 0x0D:
            printf("LED Pattern = 00001101  Display time = %u ms\n", t);
            break;
        case 0x0E:
            printf("LED Pattern = 00001110  Display time = %u ms\n", t);
            break;
        case 0x0F:
            printf("LED Pattern = 00001111  Display time = %u ms\n", t);
            break;
        case 0x10:
            printf("LED Pattern = 00010000  Display time = %u ms\n", t);
            break;
        case 0x11:
            printf("LED Pattern = 00010001  Display time = %u ms\n", t);
            break;
        case 0x12:
            printf("LED Pattern = 00010010  Display time = %u ms\n", t);
            break;
        case 0x13:
            printf("LED Pattern = 00010011  Display time = %u ms\n", t);
            break;
        case 0x14:
            printf("LED Pattern = 00010100  Display time = %u ms\n", t);
            break;
        case 0x15:
            printf("LED Pattern = 00010101  Display time = %u ms\n", t);
            break;
        case 0x16:
            printf("LED Pattern = 00010110  Display time = %u ms\n", t);
            break;
        case 0x17:
            printf("LED Pattern = 00010111  Display time = %u ms\n", t);
            break;
        case 0x18:
            printf("LED Pattern = 00011000  Display time = %u ms\n", t);
            break;
        case 0x19:
            printf("LED Pattern = 00011001  Display time = %u ms\n", t);
            break;
        case 0x1A:
            printf("LED Pattern = 00011010  Display time = %u ms\n", t);
            break;
        case 0x1B:
            printf("LED Pattern = 00011011  Display time = %u ms\n", t);
            break;
        case 0x1C:
            printf("LED Pattern = 00011100  Display time = %u ms\n", t);
            break;
        case 0x1D:
            printf("LED Pattern = 00011101  Display time = %u ms\n", t);
            break;
        case 0x1E:
            printf("LED Pattern = 00011110  Display time = %u ms\n", t);
            break;
        case 0x1F:
            printf("LED Pattern = 00011111  Display time = %u ms\n", t);
            break;
        case 0x20:
            printf("LED Pattern = 00100000  Display time = %u ms\n", t);
            break;
        case 0x21:
            printf("LED Pattern = 00100001  Display time = %u ms\n", t);
            break;
        case 0x22:
            printf("LED Pattern = 00100010  Display time = %u ms\n", t);
            break;
        case 0x23:
            printf("LED Pattern = 00100011  Display time = %u ms\n", t);
            break;
        case 0x24:
            printf("LED Pattern = 00100100  Display time = %u ms\n", t);
            break;
        case 0x25:
            printf("LED Pattern = 00100101  Display time = %u ms\n", t);
            break;
        case 0x26:
            printf("LED Pattern = 00100110  Display time = %u ms\n", t);
            break;
        case 0x27:
            printf("LED Pattern = 00100111  Display time = %u ms\n", t);
            break;
        case 0x28:
            printf("LED Pattern = 00101000  Display time = %u ms\n", t);
            break;
        case 0x29:
            printf("LED Pattern = 00101001  Display time = %u ms\n", t);
            break;
        case 0x2A:
            printf("LED Pattern = 00101010  Display time = %u ms\n", t);
            break;
        case 0x2B:
            printf("LED Pattern = 00101011  Display time = %u ms\n", t);
            break;
        case 0x2C:
            printf("LED Pattern = 00101100  Display time = %u ms\n", t);
            break;
        case 0x2D:
            printf("LED Pattern = 00101101  Display time = %u ms\n", t);
            break;
        case 0x2E:
            printf("LED Pattern = 00101110  Display time = %u ms\n", t);
            break;
        case 0x2F:
            printf("LED Pattern = 00101111  Display time = %u ms\n", t);
            break;
        case 0x30:
            printf("LED Pattern = 00110000  Display time = %u ms\n", t);
            break;
        case 0x31:
            printf("LED Pattern = 00110001  Display time = %u ms\n", t);
            break;
        case 0x32:
            printf("LED Pattern = 00110010  Display time = %u ms\n", t);
            break;
        case 0x33:
            printf("LED Pattern = 00110011  Display time = %u ms\n", t);
            break;
        case 0x34:
            printf("LED Pattern = 00110100  Display time = %u ms\n", t);
            break;
        case 0x35:
            printf("LED Pattern = 00110101  Display time = %u ms\n", t);
            break;
        case 0x36:
            printf("LED Pattern = 00110110  Display time = %u ms\n", t);
            break;
        case 0x37:
            printf("LED Pattern = 00110111  Display time = %u ms\n", t);
            break;
        case 0x38:
            printf("LED Pattern = 00111000  Display time = %u ms\n", t);
            break;
        case 0x39:
            printf("LED Pattern = 00111001  Display time = %u ms\n", t);
            break;
        case 0x3A:
            printf("LED Pattern = 00111010  Display time = %u ms\n", t);
            break;
        case 0x3B:
            printf("LED Pattern = 00111011  Display time = %u ms\n", t);
            break;
        case 0x3C:
            printf("LED Pattern = 00111100  Display time = %u ms\n", t);
            break;
        case 0x3D:
            printf("LED Pattern = 00111101  Display time = %u ms\n", t);
            break;
        case 0x3E:
            printf("LED Pattern = 00111110  Display time = %u ms\n", t);
            break;
        case 0x3F:
            printf("LED Pattern = 00111111  Display time = %u ms\n", t);
            break;
        case 0x40:
            printf("LED Pattern = 01000000  Display time = %u ms\n", t);
            break;
        case 0x41:
            printf("LED Pattern = 01000001  Display time = %u ms\n", t);
            break;
        case 0x42:
            printf("LED Pattern = 01000010  Display time = %u ms\n", t);
            break;
        case 0x43:
            printf("LED Pattern = 01000011  Display time = %u ms\n", t);
            break;
        case 0x44:
            printf("LED Pattern = 01000100  Display time = %u ms\n", t);
            break;
        case 0x45:
            printf("LED Pattern = 01000101  Display time = %u ms\n", t);
            break;
        case 0x46:
            printf("LED Pattern = 01000110  Display time = %u ms\n", t);
            break;
        case 0x47:
            printf("LED Pattern = 01000111  Display time = %u ms\n", t);
            break;
        case 0x48:
            printf("LED Pattern = 01001000  Display time = %u ms\n", t);
            break;
        case 0x49:
            printf("LED Pattern = 01001001  Display time = %u ms\n", t);
            break;
        case 0x4A:
            printf("LED Pattern = 01001010  Display time = %u ms\n", t);
            break;
        case 0x4B:
            printf("LED Pattern = 01001011  Display time = %u ms\n", t);
            break;
        case 0x4C:
            printf("LED Pattern = 01001100  Display time = %u ms\n", t);
            break;
        case 0x4D:
            printf("LED Pattern = 01001101  Display time = %u ms\n", t);
            break;
        case 0x4E:
            printf("LED Pattern = 01001110  Display time = %u ms\n", t);
            break;
        case 0x4F:
            printf("LED Pattern = 01001111  Display time = %u ms\n", t);
            break;
        case 0x50:
            printf("LED Pattern = 01010000  Display time = %u ms\n", t);
            break;
        case 0x51:
            printf("LED Pattern = 01010001  Display time = %u ms\n", t);
            break;
        case 0x52:
            printf("LED Pattern = 01010010  Display time = %u ms\n", t);
            break;
        case 0x53:
            printf("LED Pattern = 01010011  Display time = %u ms\n", t);
            break;
        case 0x54:
            printf("LED Pattern = 01010100  Display time = %u ms\n", t);
            break;
        case 0x55:
            printf("LED Pattern = 01010101  Display time = %u ms\n", t);
            break;
        case 0x56:
            printf("LED Pattern = 01010110  Display time = %u ms\n", t);
            break;
        case 0x57:
            printf("LED Pattern = 01010111  Display time = %u ms\n", t);
            break;
        case 0x58:
            printf("LED Pattern = 01011000  Display time = %u ms\n", t);
            break;
        case 0x59:
            printf("LED Pattern = 01011001  Display time = %u ms\n", t);
            break;
        case 0x5A:
            printf("LED Pattern = 01011010  Display time = %u ms\n", t);
            break;
        case 0x5B:
            printf("LED Pattern = 01011011  Display time = %u ms\n", t);
            break;
        case 0x5C:
            printf("LED Pattern = 01011100  Display time = %u ms\n", t);
            break;
        case 0x5D:
            printf("LED Pattern = 01011101  Display time = %u ms\n", t);
            break;
        case 0x5E:
            printf("LED Pattern = 01011110  Display time = %u ms\n", t);
            break;
        case 0x5F:
            printf("LED Pattern = 01011111  Display time = %u ms\n", t);
            break;
        case 0x60:
            printf("LED Pattern = 01100000  Display time = %u ms\n", t);
            break;
        case 0x61:
            printf("LED Pattern = 01100001  Display time = %u ms\n", t);
            break;
        case 0x62:
            printf("LED Pattern = 01100010  Display time = %u ms\n", t);
            break;
        case 0x63:
            printf("LED Pattern = 01100011  Display time = %u ms\n", t);
            break;
        case 0x64:
            printf("LED Pattern = 01100100  Display time = %u ms\n", t);
            break;
        case 0x65:
            printf("LED Pattern = 01100101  Display time = %u ms\n", t);
            break;
        case 0x66:
            printf("LED Pattern = 01100110  Display time = %u ms\n", t);
            break;
        case 0x67:
            printf("LED Pattern = 01100111  Display time = %u ms\n", t);
            break;
        case 0x68:
            printf("LED Pattern = 01101000  Display time = %u ms\n", t);
            break;
        case 0x69:
            printf("LED Pattern = 01101001  Display time = %u ms\n", t);
            break;
        case 0x6A:
            printf("LED Pattern = 01101010  Display time = %u ms\n", t);
            break;
        case 0x6B:
            printf("LED Pattern = 01101011  Display time = %u ms\n", t);
            break;
        case 0x6C:
            printf("LED Pattern = 01101100  Display time = %u ms\n", t);
            break;
        case 0x6D:
            printf("LED Pattern = 01101101  Display time = %u ms\n", t);
            break;
        case 0x6E:
            printf("LED Pattern = 01101110  Display time = %u ms\n", t);
            break;
        case 0x6F:
            printf("LED Pattern = 01101111  Display time = %u ms\n", t);
            break;
        case 0x70:
            printf("LED Pattern = 01110000  Display time = %u ms\n", t);
            break;
        case 0x71:
            printf("LED Pattern = 01110001  Display time = %u ms\n", t);
            break;
        case 0x72:
            printf("LED Pattern = 01110010  Display time = %u ms\n", t);
            break;
        case 0x73:
            printf("LED Pattern = 01110011  Display time = %u ms\n", t);
            break;
        case 0x74:
            printf("LED Pattern = 01110100  Display time = %u ms\n", t);
            break;
        case 0x75:
            printf("LED Pattern = 01110101  Display time = %u ms\n", t);
            break;
        case 0x76:
            printf("LED Pattern = 01110110  Display time = %u ms\n", t);
            break;
        case 0x77:
            printf("LED Pattern = 01110111  Display time = %u ms\n", t);
            break;
        case 0x78:
            printf("LED Pattern = 01111000  Display time = %u ms\n", t);
            break;
        case 0x79:
            printf("LED Pattern = 01111001  Display time = %u ms\n", t);
            break;
        case 0x7A:
            printf("LED Pattern = 01111010  Display time = %u ms\n", t);
            break;
        case 0x7B:
            printf("LED Pattern = 01111011  Display time = %u ms\n", t);
            break;
        case 0x7C:
            printf("LED Pattern = 01111100  Display time = %u ms\n", t);
            break;
        case 0x7D:
            printf("LED Pattern = 01111101  Display time = %u ms\n", t);
            break;
        case 0x7E:
            printf("LED Pattern = 01111110  Display time = %u ms\n", t);
            break;
        case 0x7F:
            printf("LED Pattern = 01111111  Display time = %u ms\n", t);
            break;
        case 0x80:
            printf("LED Pattern = 10000000  Display time = %u ms\n", t);
            break;
        case 0x81:
            printf("LED Pattern = 10000001  Display time = %u ms\n", t);
            break;
        case 0x82:
            printf("LED Pattern = 10000010  Display time = %u ms\n", t);
            break;
        case 0x83:
            printf("LED Pattern = 10000011  Display time = %u ms\n", t);
            break;
        case 0x84:
            printf("LED Pattern = 10000100  Display time = %u ms\n", t);
            break;
        case 0x85:
            printf("LED Pattern = 10000101  Display time = %u ms\n", t);
            break;
        case 0x86:
            printf("LED Pattern = 10000110  Display time = %u ms\n", t);
            break;
        case 0x87:
            printf("LED Pattern = 10000111  Display time = %u ms\n", t);
            break;
        case 0x88:
            printf("LED Pattern = 10001000  Display time = %u ms\n", t);
            break;
        case 0x89:
            printf("LED Pattern = 10001001  Display time = %u ms\n", t);
            break;
        case 0x8A:
            printf("LED Pattern = 10001010  Display time = %u ms\n", t);
            break;
        case 0x8B:
            printf("LED Pattern = 10001011  Display time = %u ms\n", t);
            break;
        case 0x8C:
            printf("LED Pattern = 10001100  Display time = %u ms\n", t);
            break;
        case 0x8D:
            printf("LED Pattern = 10001101  Display time = %u ms\n", t);
            break;
        case 0x8E:
            printf("LED Pattern = 10001110  Display time = %u ms\n", t);
            break;
        case 0x8F:
            printf("LED Pattern = 10001111  Display time = %u ms\n", t);
            break;
        case 0x90:
            printf("LED Pattern = 10010000  Display time = %u ms\n", t);
            break;
        case 0x91:
            printf("LED Pattern = 10010001  Display time = %u ms\n", t);
            break;
        case 0x92:
            printf("LED Pattern = 10010010  Display time = %u ms\n", t);
            break;
        case 0x93:
            printf("LED Pattern = 10010011  Display time = %u ms\n", t);
            break;
        case 0x94:
            printf("LED Pattern = 10010100  Display time = %u ms\n", t);
            break;
        case 0x95:
            printf("LED Pattern = 10010101  Display time = %u ms\n", t);
            break;
        case 0x96:
            printf("LED Pattern = 10010110  Display time = %u ms\n", t);
            break;
        case 0x97:
            printf("LED Pattern = 10010111  Display time = %u ms\n", t);
            break;
        case 0x98:
            printf("LED Pattern = 10011000  Display time = %u ms\n", t);
            break;
        case 0x99:
            printf("LED Pattern = 10011001  Display time = %u ms\n", t);
            break;
        case 0x9A:
            printf("LED Pattern = 10011010  Display time = %u ms\n", t);
            break;
        case 0x9B:
            printf("LED Pattern = 10011011  Display time = %u ms\n", t);
            break;
        case 0x9C:
            printf("LED Pattern = 10011100  Display time = %u ms\n", t);
            break;
        case 0x9D:
            printf("LED Pattern = 10011101  Display time = %u ms\n", t);
            break;
        case 0x9E:
            printf("LED Pattern = 10011110  Display time = %u ms\n", t);
            break;
        case 0x9F:
            printf("LED Pattern = 10011111  Display time = %u ms\n", t);
            break;
        case 0xA0:
            printf("LED Pattern = 10100000  Display time = %u ms\n", t);
            break;
        case 0xA1:
            printf("LED Pattern = 10100001  Display time = %u ms\n", t);
            break;
        case 0xA2:
            printf("LED Pattern = 10100010  Display time = %u ms\n", t);
            break;
        case 0xA3:
            printf("LED Pattern = 10100011  Display time = %u ms\n", t);
            break;
        case 0xA4:
            printf("LED Pattern = 10100100  Display time = %u ms\n", t);
            break;
        case 0xA5:
            printf("LED Pattern = 10100101  Display time = %u ms\n", t);
            break;
        case 0xA6:
            printf("LED Pattern = 10100110  Display time = %u ms\n", t);
            break;
        case 0xA7:
            printf("LED Pattern = 10100111  Display time = %u ms\n", t);
            break;
        case 0xA8:
            printf("LED Pattern = 10101000  Display time = %u ms\n", t);
            break;
        case 0xA9:
            printf("LED Pattern = 10101001  Display time = %u ms\n", t);
            break;
        case 0xAA:
            printf("LED Pattern = 10101010  Display time = %u ms\n", t);
            break;
        case 0xAB:
            printf("LED Pattern = 10101011  Display time = %u ms\n", t);
            break;
        case 0xAC:
            printf("LED Pattern = 10101100  Display time = %u ms\n", t);
            break;
        case 0xAD:
            printf("LED Pattern = 10101101  Display time = %u ms\n", t);
            break;
        case 0xAE:
            printf("LED Pattern = 10101110  Display time = %u ms\n", t);
            break;
        case 0xAF:
            printf("LED Pattern = 10101111  Display time = %u ms\n", t);
            break;
        case 0xB0:
            printf("LED Pattern = 10110000  Display time = %u ms\n", t);
            break;
        case 0xB1:
            printf("LED Pattern = 10110001  Display time = %u ms\n", t);
            break;
        case 0xB2:
            printf("LED Pattern = 10110010  Display time = %u ms\n", t);
            break;
        case 0xB3:
            printf("LED Pattern = 10110011  Display time = %u ms\n", t);
            break;
        case 0xB4:
            printf("LED Pattern = 10110100  Display time = %u ms\n", t);
            break;
        case 0xB5:
            printf("LED Pattern = 10110101  Display time = %u ms\n", t);
            break;
        case 0xB6:
            printf("LED Pattern = 10110110  Display time = %u ms\n", t);
            break;
        case 0xB7:
            printf("LED Pattern = 10110111  Display time = %u ms\n", t);
            break;
        case 0xB8:
            printf("LED Pattern = 10111000  Display time = %u ms\n", t);
            break;
        case 0xB9:
            printf("LED Pattern = 10111001  Display time = %u ms\n", t);
            break;
        case 0xBA:
            printf("LED Pattern = 10111010  Display time = %u ms\n", t);
            break;
        case 0xBB:
            printf("LED Pattern = 10111011  Display time = %u ms\n", t);
            break;
        case 0xBC:
            printf("LED Pattern = 10111100  Display time = %u ms\n", t);
            break;
        case 0xBD:
            printf("LED Pattern = 10111101  Display time = %u ms\n", t);
            break;
        case 0xBE:
            printf("LED Pattern = 10111110  Display time = %u ms\n", t);
            break;
        case 0xBF:
            printf("LED Pattern = 10111111  Display time = %u ms\n", t);
            break;
        case 0xC0:
            printf("LED Pattern = 11000000  Display time = %u ms\n", t);
            break;
        case 0xC1:
            printf("LED Pattern = 11000001  Display time = %u ms\n", t);
            break;
        case 0xC2:
            printf("LED Pattern = 11000010  Display time = %u ms\n", t);
            break;
        case 0xC3:
            printf("LED Pattern = 11000011  Display time = %u ms\n", t);
            break;
        case 0xC4:
            printf("LED Pattern = 11000100  Display time = %u ms\n", t);
            break;
        case 0xC5:
            printf("LED Pattern = 11000101  Display time = %u ms\n", t);
            break;
        case 0xC6:
            printf("LED Pattern = 11000110  Display time = %u ms\n", t);
            break;
        case 0xC7:
            printf("LED Pattern = 11000111  Display time = %u ms\n", t);
            break;
        case 0xC8:
            printf("LED Pattern = 11001000  Display time = %u ms\n", t);
            break;
        case 0xC9:
            printf("LED Pattern = 11001001  Display time = %u ms\n", t);
            break;
        case 0xCA:
            printf("LED Pattern = 11001010  Display time = %u ms\n", t);
            break;
        case 0xCB:
            printf("LED Pattern = 11001011  Display time = %u ms\n", t);
            break;
        case 0xCC:
            printf("LED Pattern = 11001100  Display time = %u ms\n", t);
            break;
        case 0xCD:
            printf("LED Pattern = 11001101  Display time = %u ms\n", t);
            break;
        case 0xCE:
            printf("LED Pattern = 11001110  Display time = %u ms\n", t);
            break;
        case 0xCF:
            printf("LED Pattern = 11001111  Display time = %u ms\n", t);
            break;
        case 0xD0:
            printf("LED Pattern = 11010000  Display time = %u ms\n", t);
            break;
        case 0xD1:
            printf("LED Pattern = 11010001  Display time = %u ms\n", t);
            break;
        case 0xD2:
            printf("LED Pattern = 11010010  Display time = %u ms\n", t);
            break;
        case 0xD3:
            printf("LED Pattern = 11010011  Display time = %u ms\n", t);
            break;
        case 0xD4:
            printf("LED Pattern = 11010100  Display time = %u ms\n", t);
            break;
        case 0xD5:
            printf("LED Pattern = 11010101  Display time = %u ms\n", t);
            break;
        case 0xD6:
            printf("LED Pattern = 11010110  Display time = %u ms\n", t);
            break;
        case 0xD7:
            printf("LED Pattern = 11010111  Display time = %u ms\n", t);
            break;
        case 0xD8:
            printf("LED Pattern = 11011000  Display time = %u ms\n", t);
            break;
        case 0xD9:
            printf("LED Pattern = 11011001  Display time = %u ms\n", t);
            break;
        case 0xDA:
            printf("LED Pattern = 11011010  Display time = %u ms\n", t);
            break;
        case 0xDB:
            printf("LED Pattern = 11011011  Display time = %u ms\n", t);
            break;
        case 0xDC:
            printf("LED Pattern = 11011100  Display time = %u ms\n", t);
            break;
        case 0xDD:
            printf("LED Pattern = 11011101  Display time = %u ms\n", t);
            break;
        case 0xDE:
            printf("LED Pattern = 11011110  Display time = %u ms\n", t);
            break;
        case 0xDF:
            printf("LED Pattern = 11011111  Display time = %u ms\n", t);
            break;
        case 0xE0:
            printf("LED Pattern = 11100000  Display time = %u ms\n", t);
            break;
        case 0xE1:
            printf("LED Pattern = 11100001  Display time = %u ms\n", t);
            break;
        case 0xE2:
            printf("LED Pattern = 11100010  Display time = %u ms\n", t);
            break;
        case 0xE3:
            printf("LED Pattern = 11100011  Display time = %u ms\n", t);
            break;
        case 0xE4:
            printf("LED Pattern = 11100100  Display time = %u ms\n", t);
            break;
        case 0xE5:
            printf("LED Pattern = 11100101  Display time = %u ms\n", t);
            break;
        case 0xE6:
            printf("LED Pattern = 11100110  Display time = %u ms\n", t);
            break;
        case 0xE7:
            printf("LED Pattern = 11100111  Display time = %u ms\n", t);
            break;
        case 0xE8:
            printf("LED Pattern = 11101000  Display time = %u ms\n", t);
            break;
        case 0xE9:
            printf("LED Pattern = 11101001  Display time = %u ms\n", t);
            break;
        case 0xEA:
            printf("LED Pattern = 11101010  Display time = %u ms\n", t);
            break;
        case 0xEB:
            printf("LED Pattern = 11101011  Display time = %u ms\n", t);
            break;
        case 0xEC:
            printf("LED Pattern = 11101100  Display time = %u ms\n", t);
            break;
        case 0xED:
            printf("LED Pattern = 11101101  Display time = %u ms\n", t);
            break;
        case 0xEE:
            printf("LED Pattern = 11101110  Display time = %u ms\n", t);
            break;
        case 0xEF:
            printf("LED Pattern = 11101111  Display time = %u ms\n", t);
            break;
        case 0xF0:
            printf("LED Pattern = 11110000  Display time = %u ms\n", t);
            break;
        case 0xF1:
            printf("LED Pattern = 11110001  Display time = %u ms\n", t);
            break;
        case 0xF2:
            printf("LED Pattern = 11110010  Display time = %u ms\n", t);
            break;
        case 0xF3:
            printf("LED Pattern = 11110011  Display time = %u ms\n", t);
            break;
        case 0xF4:
            printf("LED Pattern = 11110100  Display time = %u ms\n", t);
            break;
        case 0xF5:
            printf("LED Pattern = 11110101  Display time = %u ms\n", t);
            break;
        case 0xF6:
            printf("LED Pattern = 11110110  Display time = %u ms\n", t);
            break;
        case 0xF7:
            printf("LED Pattern = 11110111  Display time = %u ms\n", t);
            break;
        case 0xF8:
            printf("LED Pattern = 11111000  Display time = %u ms\n", t);
            break;
        case 0xF9:
            printf("LED Pattern = 11111001  Display time = %u ms\n", t);
            break;
        case 0xFA:
            printf("LED Pattern = 11111010  Display time = %u ms\n", t);
            break;
        case 0xFB:
            printf("LED Pattern = 11111011  Display time = %u ms\n", t);
            break;
        case 0xFC:
            printf("LED Pattern = 11111100  Display time = %u ms\n", t);
            break;
        case 0xFD:
            printf("LED Pattern = 11111101  Display time = %u ms\n", t);
            break;
        case 0xFE:
            printf("LED Pattern = 11111110  Display time = %u ms\n", t);
            break;
        case 0xFF:
            printf("LED Pattern = 11111111  Display time = %u ms\n", t);
            break;
        default:
            printf("Pattern not recognized");
            break;
    }
}

// Check for CTRL-C command from user
static volatile int keepRunning = 1;
void programRunner(int dummy)
{
        devmem(0xFF200008, 0x0);
        keepRunning= 0;
}

int main(int argc, char **argv)
{

    signal(SIGINT, programRunner);

    int vflag = 0;
    int pflag = 0;
    int fflag = 0;
    char filename[100];
    char line[256];
    int c;

    int odd_arg_flag = 0;
    int command_count;

    uint32_t patterns[30];
    uint32_t times[30];

    // Argument parsing from the command line
    opterr = 0;
    while ((c = getopt (argc, argv, "hvp:f:")) != -1)
        switch (c)
        {
            case 'h':
                help();
                exit(0);
                break;
            case 'v':
                vflag = 1;
                break;
            case 'p':
                pflag = 1;
                command_count = (argc - (optind-1)) / 2;
                if ((argc - optind) % 2 == 0)
                {
                    odd_arg_flag = 1;
                }

                for(int i=optind-1; i < argc; i=i+2)
                {
                    patterns[((i - optind + 1)/2)] = strtoul(argv[i], NULL, 0);
                }

                for(int j=optind; j<argc; j=j+2)
                {
                    times[(j-optind)/2] = (uint32_t)strtoul(argv[j], NULL, 0);            
                }
                break;
            case 'f':
                fflag = 1;
                strcpy(filename, optarg);
                break;
            case '?':
                if ((optopt == 'f') | (optopt == 'p'))
                {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                    exit(0);
                }
                else if (isprint (optopt))
                {
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                    exit(0);
                }
                else
                {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                    exit(0);
                }
                break;
            default:
                abort();
        }

    // If no arguments were given in the command, print the help statement
    if (argc == 1)
    {
        help();
        devmem(0xFF200008, 0x0);
        exit(0);
    }

    // If -f and -p are both called, print an error and quit
    if ((fflag == 1) & (pflag ==1))
    {
        fprintf(stderr, "Cannot call -f and -p at once. Choose one and try again.\n");
        exit(0);
    }

    // If an odd number of arguments follow -p, print an error and quit
    if (odd_arg_flag == 1)
    {
        fprintf(stderr, "Each pattern value should be followed by a time value.\n");
        exit(0);
    }

    //If -p was called, write the pattern and time values to registers
    if (pflag == 1)
    {
        while (keepRunning)
        {
        for (int i = 0; i < command_count; i++)
        {
            devmem(0xFF200008, 0x1);
            devmem(0xFF200004, patterns[i]);
            // If -v was also called, print the patterns and times to the console as they are written
            if (vflag == 1)
            {
                verbose(patterns[i], times[i]);
            }
            usleep(times[i]*1000);
        }
        }
        devmem(0xFF200008, 0x0);
        exit(0);
    }
    // If -f was called, read the provided file and execute patterns
    if (fflag == 1)
    {
        FILE *file = fopen(filename, "r"); 

        int index = 0;
        while (fgets(line, sizeof(line), file))
        {
            char *token = strtok(line, " ");
            if (token != NULL)
            {
                token = strtok(NULL, " ");
            }
            times[index] = strtoul(token, NULL, 0);
            patterns[index] = strtoul(line, NULL, 0);

            index = index+1;
        }
        fclose(file);
        command_count = index;

        for (int i = 0; i < command_count; i++)
        {
            devmem(0xFF200008, 0x1);
            devmem(0xFF200004, patterns[i]);
            // If -v was also called, print the patterns and times to the console as they are written
            if (vflag == 1)
            {
                verbose(patterns[i], times[i]);
            }
            usleep(times[i]*1000);
        }
        devmem(0xFF200008, 0x0);
        exit(0);
    }
    return 0;
}
