/*
 * MIT License
 * Copyright (c) from 2017, Michal Kozakiewicz, github.com/michal037
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "tsimple.h"

void init_GPIO(uint8 gpioNumber)
{
	char stringBufer[34];

	sprintf(stringBufer, "echo %d > /sys/class/gpio/export", gpioNumber);

	if(system(stringBufer))
	{
		fprintf(stderr, "GPIO %d was initialized.\n", gpioNumber);
	} else
	{
		fprintf(stdout, "GPIO %d properly initialised.\n", gpioNumber);
	}
} /* init_GPIO */

void UNinit_GPIO(uint8 gpioNumber)
{
	char stringBufer[36];

	sprintf(stringBufer, "echo %d > /sys/class/gpio/unexport", gpioNumber);

	if(system(stringBufer))
	{
		fprintf(stderr, "GPIO %d was disabled.\n", gpioNumber);
	} else
	{
		fprintf(stdout, "GPIO %d off.\n", gpioNumber);
	}
} /* init_GPIO */

void gpioMode(uint8 gpioNumber, uint8 mode)
{
	char stringBufer[45];

	sprintf(stringBufer, "echo %s > /sys/class/gpio/gpio%d/direction", (mode?"in":"out"), gpioNumber);
	system(stringBufer);
} /* pinMode */

void gpioWrite(uint8 gpioNumber, uint8 state)
{
	char stringBufer[39];

	sprintf(stringBufer, "echo %d > /sys/class/gpio/gpio%d/value", (state?1:0), gpioNumber);
	system(stringBufer);
} /* gpioWrite */

uint8 gpioRead(uint8 gpioNumber)
{
	FILE *gpioFILE;
	char stringBufer[62];
	char readBufer[2];

	system("mkdir -p /tmp/tempgpioread");
	sprintf(stringBufer, "cat /sys/class/gpio/gpio%d/value > /tmp/tempgpioread/gpio%d", gpioNumber, gpioNumber);
	system(stringBufer);

	sprintf(stringBufer, "/tmp/tempgpioread/gpio%d", gpioNumber);

	if((gpioFILE = fopen(stringBufer, "rb")) == NULL)
	{
		fprintf(stderr, "GPIO %d fail on opening file for read\n", gpioNumber);
		return 0;
	}

	fread(readBufer, 1, 1, gpioFILE);

	if(fclose(gpioFILE) == EOF)
	{
		fprintf(stderr, "GPIO %d fail on closing file for read\n", gpioNumber);
		return 0;
	}

	return (readBufer[0] == '1') ? 1 : 0;
} /* gpioRead */
