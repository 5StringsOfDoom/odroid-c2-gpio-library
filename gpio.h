/*
 * MIT License
 * Copyright (c) from 2017, Michal Kozakiewicz, github.com/michal037
 *
 */

#include "tsimple.h"

#ifndef __CUSTOM_ODROIDC2_GPIO__
#define __CUSTOM_ODROIDC2_GPIO__

/* GPIO's from 40-GPIO Header, rev 0.2 20160226 */
#define GPIO_03 205
#define GPIO_05 206
#define GPIO_11 247
#define GPIO_12 238
#define GPIO_13 239
#define GPIO_15 237
#define GPIO_16 236
#define GPIO_18 233
#define GPIO_22 231
#define GPIO_26 225
#define GPIO_27 207
#define GPIO_28 208
#define GPIO_29 228
#define GPIO_31 219
#define GPIO_32 224
#define GPIO_33 234
#define GPIO_35 214
#define GPIO_36 218

/* GPIO's from 7-GPIO Header, WiringPi can't handle these GPIO */
// PIN 41 : Ground
#define GPIO_44 130
#define GPIO_45 132
#define GPIO_46 131
#define GPIO_47 133

/*
 * For there, use WiringPi
 *
 * NAME------PHYSICAL---------WPi
 * GPIO.249 - 07/40 - WiringPi.07
 * GPIO.240 - 08/40 - WiringPi.15
 * GPIO.241 - 10/40 - WiringPi.16
 * GPIO.235 - 19/40 - WiringPi.12
 * GPIO.232 - 21/40 - WiringPi.13
 * GPIO.230 - 23/40 - WiringPi.14
 * GPIO.229 - 24/40 - WiringPi.10
 *
 * AIN.1    - 37/40 - WiringPi.25
 * AIN.0    - 40/40 - WiringPi.29
 */

/* GPIO MODE */
#define GPIO_INPUT 1
#define GPIO_OUTPUT 0

/* GPIO STATE*/
#define GPIO_HIGH 1
#define GPIO_LOW 0

/* ----- ----- ----- FUNCTIONS ----- ----- ----- */
/*
 * Initialize GPIO for use.
 */
void init_GPIO(uint8 gpioNumber);

/*
 * Disable GPIO.
 */
void UNinit_GPIO(uint8 gpioNumber);

/*
 * Set GPIO mode INPUT/OUTPUT
 */
void gpioMode(uint8 gpioNumber, uint8 mode);

/*
 * Write data to GPIO.
 */
void gpioWrite(uint8 gpioNumber, uint8 state);

/*
 * Read data from GPIO.
 */
uint8 gpioRead(uint8 gpioNumber);

#endif
