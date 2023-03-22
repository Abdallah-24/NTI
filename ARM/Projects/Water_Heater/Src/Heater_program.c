#include	"STD_Types.h"
#include	"BIT_Math.h"
#include 	"DIO_interface.h"

#include	"HEATER_private.h"
#include	"HEATER_config.h"
#include	"HEATER_interface.h"



void H_HEATER_void_init(void)
{
	M_DIO_void_setPinDir(HEAT_PORT,HEAT_PIN,OUT_2MHZ_PP);
}

void H_HEATER_void_start(void)
{
	M_DIO_void_setPinVal(HEAT_PORT,HEAT_PIN,DIO_HIGH);
}

void H_HEATER_void_stop(void)
{
	M_DIO_void_setPinVal(HEAT_PORT,HEAT_PIN,DIO_LOW);
}


