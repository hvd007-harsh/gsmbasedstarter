/*=============================================================================
 * @file    my_module.h
 * @brief   Brief description of this module.
 * @author  Your Name
 * @date    2025-10-23
 *============================================================================*/

#include "Master.h"

char Response[RESPONSE_BYTES];
uint8_t Response_index = 0;
_Bool Response_Acknowledged =0;
uint8_t Response_Timer=0;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart2)
	{
		Response[Response_index++] = byte;
		Response_Acknowledged = 1;
	}
	HAL_UART_Receive_IT(&huart2, &byte, 1);
}




void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim == &htim14)
  {
   if(Response_Acknowledged == 1)
   {
	   if(Response_Timer++ >= RESPONSE_BYTES)
	   {
		   Response_Timer = 0;
		   EC_Manager_Handler(Response_Acknowledged);
		   Response_Acknowledged = 0 ;
		   Response_index =0;
		   memset(Response,'\0',sizeof(Response)/sizeof(uint8_t));
	   }
   }
   else
   {
	   Response_Timer =0;
	   EC_Manager_Handler(Response_Acknowledged);
   }
  }
}



uint8_t Txdata[100];
uint8_t snd_cmd[] = {0x0d, 0x0a};

void EC_Comm_Send( char * buffer)
{
   memcpy(Txdata,buffer,sizeof(Txdata)/sizeof(uint8_t));
   HAL_UART_Transmit(&huart2,buffer, sizeof(buffer)/sizeof(char), 0xFFFF);
 //  HAL_UART_Transmit(&huart2,snd_cmd, sizeof(snd_cmd)/sizeof(uint8_t), 0xFFFF);
}


