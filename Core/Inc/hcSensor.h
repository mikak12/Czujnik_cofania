/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : hcSensor.h
  * @brief          : Header for hcSensor.c file.
  *                   Function for hcSensor
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HCSENSOR_H
#define __HCSENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "cmsis_os.h"


#define usTIM TIM4

void usDelay(uint32_t uSec);
float measureDistance();

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
