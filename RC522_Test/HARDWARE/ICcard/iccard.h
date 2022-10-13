#ifndef __ICCARD_H__
#define __ICCARD_H__

#include "stm32g4xx.h"

#define ICEN_PORT											GPIOA
#define ICEN_PIN											GPIO_PIN_2

void IC_card_Init();
void IC_card_Enable();
void IC_card_Disable();

#endif