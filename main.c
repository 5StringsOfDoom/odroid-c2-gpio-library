/*
 * MIT License
 * Copyright (c) from 2017, Michal Kozakiewicz, github.com/michal037
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"

int main(int argc, char *argv[])
{
	init_GPIO(GPIO_33);
	gpioMode(GPIO_33, GPIO_INPUT);
	printf("result: %d\n", gpioRead(GPIO_33));

	init_GPIO(GPIO_22);
	gpioMode(GPIO_22, GPIO_OUTPUT);
	gpioWrite(GPIO_22, GPIO_HIGH);

	return 0;
} /* main */
