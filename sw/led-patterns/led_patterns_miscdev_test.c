#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h> // for terminating program with CTRL-C

// TODO: update these offsets if your address are different
#define HPS_LED_CONTROL_OFFSET 0x8
#define BASE_PERIOD_OFFSET 0x0
#define LED_REG_OFFSET 0x4

// Check for CTRL-C command from user
static volatile int keepRunning = 1;
void programRunner(int dummy)
{
        keepRunning= 0;
}

int main () {

	signal(SIGINT, programRunner);

	FILE *file;
	size_t ret;	
	uint32_t val;

	file = fopen("/dev/led_patterns", "rb+");
	if (file == NULL) {
		printf("failed to open file\n");
		exit(1);
	}
	
	// Test reading the registers sequentially
	printf("\n************************************\n*");
	printf("* read initial register values\n");
	printf("************************************\n\n");

	ret = fread(&val, 4, 1, file);
	printf("HPS_LED_control = 0x%x\n", val);

	ret = fread(&val, 4, 1, file);
	printf("base period = 0x%x\n", val);

	ret = fread(&val, 4, 1, file);
	printf("LED_reg = 0x%x\n", val);

	// Reset file position to 0
	ret = fseek(file, 0, SEEK_SET);
	printf("fseek ret = %d\n", ret);
	printf("errno =%s\n", strerror(errno));


	printf("\n************************************\n*");
	printf("* write values\n");
	printf("************************************\n\n");

	// Turn on software-control mode
	val = 0x01;
    ret = fseek(file, HPS_LED_CONTROL_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	// We need to "flush" so the OS finishes writing to the file before our code continues.
	fflush(file);

	printf("Software Control Mode: Running Custom Pattern\n");
	while(keepRunning)
	{
	val = 0x08;
	ret = fseek(file, LED_REG_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	usleep(3e5);

	val = 0x14;
	ret = fseek(file, LED_REG_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	usleep(3e5);

	val = 0x22;
	ret = fseek(file, LED_REG_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	usleep(3e5);

	val = 0x41;
	ret = fseek(file, LED_REG_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	usleep(3e5);
	}

	// Turn on hardware-control mode
	printf("back to hardware-control mode....\n");
	val = 0x00;
    ret = fseek(file, HPS_LED_CONTROL_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	val = 0x12;
    ret = fseek(file, BASE_PERIOD_OFFSET, SEEK_SET);
	ret = fwrite(&val, 4, 1, file);
	fflush(file);

	fclose(file);
	return 0;
}