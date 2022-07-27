/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Systick_Lcnfg_H
#define Systick_Lcnfg_H

/*Oscillator source is either "Perscion_Internal_OSC"=0 or "Main_OSC"=1*/
#define OSC_SRC_IS		0

/*from 3 to 16 */
#define OSC_FREQ_DIV_BY		3
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*#define OSC_SRC_IS		"Perscion_Internal_OSC"*/
#if OSC_SRC_IS==1 
#define OSCRC_SET_MSK		0
#elif OSC_SRC_IS==0 
#define OSCRC_SET_MSK		1
#endif



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


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