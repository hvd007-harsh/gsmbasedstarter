/*=============================================================================
 * @file    EC_Comm.h
 * @brief   Brief description of this module.
 * @author  Harsh Vardhan Dixit
 * @date    2025-10-23
 *============================================================================*/
#ifndef EC_COMM_H
#define EC_COMM_H

#define RESPONSE_BYTES 100

extern char byte;
extern char Response[RESPONSE_BYTES];



void EC_Comm_Send(char * buffer);



#endif /* EC_COMM_H */
