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

typedef enum 
{
  PASSED=1,
  FAILED =0
}service_t;

Commands_t Command_Stat =POWER_OFF;
_Bool sent_command =0;
uint8_t Retry=0;
service_t Iscommandpass = FAILED;

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
    else
    {
      if(Acknowledged == 0)
      {
        if(Timer_Delay++ > Timeout)
        {
          if(Retry++ >= 3 )
          {
            sent_command = 0;
            Iscommandpass = FAILED;
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
        Iscommandpass = PASSED;
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
   EC_Manager_Proceeder(Acknowledged,4000);
	   __POWER_ON__;
	   if(Timer_Delay++ > 5000)
	   {
		   __POWER_OFF__;
////		   __RESET_ON__;
		   Timer_Delay = 0;
      
		    Command_Stat = ATCOMMAND;

//		    EC_Manager_Proceeder(Acknowledged,4000);
	   }

   break;
   case ATCOMMAND:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = POWER_OFF;
      }
   break;
   case MODULE_INFO:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = ATCOMMAND;
      }
   break;
   case FUNCTIONALITY:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = MODULE_INFO;
      }
   break;
   case SIM_STATUS:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = FUNCTIONALITY;
      }
   break;
   case SIGNAL_QUALITY:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = SIM_STATUS;
      }
   break;
   case NETWORK_REG:
      if(Iscommandpass == PASSED)
      {
        EC_Manager_Proceeder(Acknowledged,1000);
      }
      else if(Iscommandpass == FAILED)
      {
       Command_Stat = SIGNAL_QUALITY;
      }
   break;
   }
}
