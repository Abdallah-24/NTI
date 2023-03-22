//#include	"STD_Types.h"
//#include	"BIT_Math.h"
//
//#include	"RCC_interface.h"
//#include	"DIO_interface.h"
//
//
//void	Delay(void)
//{
//	for(u32 i = 0; i < 500000 ; i++)
//	{
//		asm("NOP");
//	}
//}
//
//int	main(void)
//{
//	/*	Initialization Part		*/
//
//	/*	System Clk init			*/
//	MRCC_voidSysClkInit();
//
//	/*	Toggle Led C13	GPIOC	*/
//	/*	1- Enable Per Clk "RCC" Port C		*/
//	MRCC_voidEnablePerClk(RCC_APB2,2);
//
//	/*	Direction for C13 is output Push Pull */
//	M_DIO_void_setPinDir(PORTA, PIN0, OUT_2MHZ_PP);
//
//
//	while(1)
//	{
//		/*	Toggle led */
//		M_DIO_void_setPinVal(PORTA, PIN0, DIO_LOW);
//		Delay();
//		M_DIO_void_setPinVal(PORTA, PIN0, DIO_HIGH);
//		Delay();
//	}
//	return 0;
//}
