/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

extern TIM_HandleTypeDef htim14;

extern UART_HandleTypeDef huart2;

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EC_TX_Pin GPIO_PIN_2
#define EC_TX_GPIO_Port GPIOA
#define EC_RX_Pin GPIO_PIN_3
#define EC_RX_GPIO_Port GPIOA
#define EC_RST_Pin GPIO_PIN_0
#define EC_RST_GPIO_Port GPIOD
#define EC_PWR_Pin GPIO_PIN_1
#define EC_PWR_GPIO_Port GPIOD


#define __POWER_ON__ HAL_GPIO_WritePin(EC_PWR_GPIO_Port, EC_PWR_Pin, SET)
#define __POWER_OFF__ HAL_GPIO_WritePin(EC_PWR_GPIO_Port, EC_PWR_Pin, RESET)


#define __RESET_ON__  HAL_GPIO_WritePin(EC_RST_GPIO_Port, EC_RST_Pin, SET)
#define __RESET_OFF__  HAL_GPIO_WritePin(EC_RST_GPIO_Port, EC_RST_Pin, RESET)

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
