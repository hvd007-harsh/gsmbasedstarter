/*=============================================================================
 * @file    my_module.h
 * @brief   Brief description of this module.
 * @author  Your Name
 * @date    2025-10-23
 *============================================================================*/
#include "Master.h"

const char* Request_Commands[]=
{
		"POWER",
		"AT\r\n",
		"ATI\r\n",
		"AT+CFUN?\r\n",
		"AT+CPIN?\r\n",
		"AT+CSQ?\r\n",
		"AT+CREG?\r\n",
};

const char * Response_Commands[]={
	    "RDY",           // Response for your custom POWER check
	    "OK",              // Response for AT
	    "Quectel",         // ATI response contains module name
	    "+CFUN: 1",            // CFUN full functionality done (URC)
	    "+CPIN: READY",    // SIM ready
	    "+CSQ",            // Signal quality (contains +CSQ: <rssi>,<ber>)
	    "+CREG"            // Network registration info
};



Commands_t Command_Stat =POWER_OFF;
_Bool sent_command =0;
uint8_t Retry=0;

void EC_Manager_Proceeder(_Bool Acknowledged, uint16_t Timeout)
{
	static uint16_t Timer_Delay =0;
    if(sent_command ==0)
    {
      if(Request_Commands[Command_Stat] != "POWER")
      {
       EC_Comm_Send(Request_Commands[Command_Stat]);
       sent_command=1;
      }
    }
    else{
      if(Acknowledged == 0)
      {
   	 if(Timer_Delay++ > Timeout)
   	 {
   		if(Retry++ >= 3 )
   		{
   			Command_Stat--;
   			sent_command = 0;
   			Retry = 0;
   		}
   		Timer_Delay = 0;
   	 }
      }
    }
  if(Acknowledged == 1)
  {
      Retry = 0;
    if(strstr(Response,Response_Commands[Command_Stat]))
    {
      /* It is present in Response */
        sent_command = 0;
        Command_Stat++;
        Timer_Delay = 0;

    }
    else
    {
   	 Retry = 0 ;
    }
  }
}
void EC_Manager_Handler(_Bool Acknowledged)
{
	static uint16_t Timer_Delay =0;
   switch(Command_Stat)
   {
   case POWER_OFF:
//	   __POWER_ON__;
	   if(Timer_Delay++ > 5000)
	   {
//		   __POWER_OFF__;
////		   __RESET_ON__;
//		   Timer_Delay = 0;
		   Command_Stat = ATCOMMAND;
//		   EC_Manager_Proceeder(Acknowledged,4000);
	   }

   break;
   case ATCOMMAND:
	   EC_Manager_Proceeder(Acknowledged,1000);
   break;
   case MODULE_INFO:
	   EC_Manager_Proceeder(Acknowledged, 2000);
   break;
   case FUNCTIONALITY:
	   EC_Manager_Proceeder(Acknowledged,6000);
   break;
   case SIM_STATUS:
	   EC_Manager_Proceeder(Acknowledged,6000);
   break;
   case SIGNAL_QUALITY:
	   EC_Manager_Proceeder(Acknowledged,6000);
   break;
   case NETWORK_REG:
	   EC_Manager_Proceeder(Acknowledged,6000);
   break;
   }
}
