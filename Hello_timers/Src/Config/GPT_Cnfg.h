/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_Cnfg_H
#define GPT_Cnfg_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

typedef enum{
	GPT_PREDEF_TIMER_CONFIG_100US_32BIT = 0 ,
	GPT_PREDEF_TIMER_CONFIG_1US_16BIT = 1 ,
	GPT_PREDEF_TIMER_CONFIG_1US_24BIT = 2 ,
	GPT_PREDEF_TIMER_CONFIG_1US_32BIT = 3 ,
	GPT_PREDEF_TIMER_CONFIG_disabled = 4
}GPT_PREDEF_TIMER_CONFIG;



#define NUMBER_OF_ENABELED_TIMERS			((u8)2)

#define TIMER0_PREDEF_SETTING				4


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef   void (*GptNotification)(void);

typedef enum {
	TIMER_CHANNEL_0 = 0 ,
	TIMER_CHANNEL_1 = 1 ,
	TIMER_CHANNEL_2 = 2 ,
	TIMER_CHANNEL_3 = 3 ,
	TIMER_CHANNEL_4 = 4 ,
	TIMER_CHANNEL_5 = 5 ,
	TIMER_CHANNEL_6 =	6 ,
	TIMER_CHANNEL_7 = 7 ,
	TIMER_CHANNEL_8 = 8 ,
	TIMER_CHANNEL_9 = 9 ,
	TIMER_CHANNEL_10 = 10 ,
	TIMER_CHANNEL_11= 11 
}TIMER_CHANNEL;



typedef enum{
	GPT_MODE_ONE_SHOT = 0 ,
	GPT_MODE_PERIODIC = 1 
}GPT_MODE;

typedef struct {
	TIMER_CHANNEL ChannelId ;
	u8  GptChannelTickFrequency;
	u32 GptChannelTickValueMax ;
	GPT_MODE GptMode;
	GptNotification callback ;
}GPT_CONFIG_TYPE;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/