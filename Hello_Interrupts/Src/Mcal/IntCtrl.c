/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "IntCtrl.h"
#include "Reg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
extern struct Interrupts INTS [NUM_OF_INTS];
void IntCrtl_Init(void)
{
	u8 i;
	u8 IntId ,IntPri;
	u32 temp=0;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
  temp = (0xFA050000)|((u8)PRIGROUP_SETTING<<8);
	APINT_REG = temp;
	for(i=0 ;i<NUM_OF_INTS;i++){
		IntId = INTS[i].IntNum;
		IntPri= INTS[i].IntPri;
		/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
		u8 a =PRI_REG_OFFSET(IntId);
		u8 b= PRI_BIT_SHIFT(IntId);
		temp = *(PRI0_REG_ADDR+(PRI_REG_OFFSET(IntId)));
		temp |= (IntPri << (PRI_BIT_SHIFT(IntId)));
		*(PRI0_REG_ADDR+(PRI_REG_OFFSET(IntId))) = temp ;
		/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		a=INT_EN_REG_OFFSET(IntId);
		b= INT_EN_BIT_NUM (IntId);
		temp = *(EN0_REG_ADDR+(INT_EN_REG_OFFSET(IntId)));
		temp |= (1<<(INT_EN_BIT_NUM (IntId)));
		*(EN0_REG_ADDR+(INT_EN_REG_OFFSET(IntId))) = temp ;
	}
	
	/**/
	*(volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)= (0X9A<<11) ;

	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/