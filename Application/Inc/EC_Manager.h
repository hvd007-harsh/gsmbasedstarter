/*=============================================================================
 * @file    EC_Manager.h
 * @brief   Brief description of this module.
 * @author  Harsh Vardhan Dixit
 * @date    2025-10-23
 *============================================================================*/
#ifndef EC_MANAGER_H
#define EC_MANAGER_H
#include "main.h"

typedef enum {
	POWER_OFF,
	ATCOMMAND,
	MODULE_INFO,
	FUNCTIONALITY,
	SIM_STATUS,
	NETWORK_REG,
	SIGNAL_QUALITY,
    TOTAL_COMMAND,
} Commands_t;

extern uint8_t buff[100];
extern uint8_t Response_Index;

void EC_Manager_Proceeder(_Bool Acknowledged, uint16_t Timeout);
void EC_Manager_Handler(_Bool Acknowledged);

#endif /* EC Manager.h */
