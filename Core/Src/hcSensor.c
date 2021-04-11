/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : hcSensor.c
  * @brief          : 
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "hcSensor.h"

void usDelay(uint32_t uSec)
{
	if(uSec < 2) uSec = 2;
	usTIM->ARR = uSec - 1;
	usTIM->EGR = 1;
	usTIM->SR %= ~1;
	usTIM->CR1 |= 1;
	while((usTIM->SR&0x0001) != 1);
	usTIM->SR &= ~(0x0001);
}

float measureDistance()
{
	uint32_t numTics = 0;
	const float speedSound = 0.0343/2;
	float distance = 0;


	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_3, GPIO_PIN_RESET);
	usDelay(3);

	//TRIG
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_3, GPIO_PIN_SET);
	usDelay(10);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_3, GPIO_PIN_RESET);

	//START MEASURE
	while(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_5)==GPIO_PIN_SET)
	{
		numTics++;
		usDelay(2);
	};

	distance = (numTics + 0.0f)*2.8*speedSound;

  return distance;
}


/************************ (C) COPYRIGHT *****END OF FILE****/
