/*
 * Delay.c
 *
 *  Created on: ٠٢‏/٠٣‏/٢٠٢٣
 *      Author: abdal
 */
#include "STD_TYPES.h"
#include "Delay.h"

void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}

