#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"

/*
 * tickCounter.h
 *
 *  Created on: Jan 8, 2016
 *      Author: akbkuku
 */

#ifndef TICKCOUNTER_H_
#define TICKCOUNTER_H_

#ifdef __cplusplus
extern "C" {
#endif
void TickCounter(void);
void TickCounterInit(void);
uint32_t millis();

#ifdef __cplusplus
}
#endif

#endif /* TICKCOUNTER_H_ */
