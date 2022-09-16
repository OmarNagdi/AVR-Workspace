/*
 * GIE_Program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: OmarNagdy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"




#define GIE_SREG_REG	*((volatile u8 *)0x5F)




void MGIE_voidGIEEnable(void)
{
	SET_BIT(GIE_SREG_REG,7);
}
void MGIE_voidGIEDisable(void)
{
	CLR_BIT(GIE_SREG_REG,7);
}

