#include "iccard.h"

void IC_card_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	//EN//PA2
	GPIO_InitStructure.Pin = ICEN_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(ICEN_PORT, &GPIO_InitStructure);
	
	HAL_GPIO_WritePin(ICEN_PORT,ICEN_PIN,GPIO_PIN_RESET);
}

void IC_card_Enable()
{HAL_GPIO_WritePin(ICEN_PORT,ICEN_PIN,GPIO_PIN_SET);}

void IC_card_Disable()
{HAL_GPIO_WritePin(ICEN_PORT,ICEN_PIN,GPIO_PIN_RESET);}