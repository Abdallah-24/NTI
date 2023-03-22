#include	"STD_Types.h"
#include	"BIT_Math.h"
#include 	"DIO_interface.h"

#include	"COOLER_private.h"
#include	"COOLER_config.h"
#include	"COOLER_interface.h"



void H_COOLER_void_init(void)
{
	M_DIO_void_setPinDir(COOLER_PORT,COOLER_PIN,OUT_2MHZ_PP);
}

void H_COOLER_void_start(void)
{
	M_DIO_void_setPinVal(COOLER_PORT,COOLER_PIN,DIO_HIGH);
}

void H_COOLER_void_stop(void)
{
	M_DIO_void_setPinVal(COOLER_PORT,COOLER_PIN,DIO_LOW);
}


