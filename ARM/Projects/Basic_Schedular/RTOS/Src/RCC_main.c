//#include	"STD_TYPES.h"
//#include	"BIT_MATH.h"
//
//#include	"RCC_interface.h"
//
//#define		GPIOC_CRH		*((u32 *)(0x40011000 + 0x04)) //DDR
//#define		GPIOC_ODR		*((u32 *)(0x40011000 + 0x0C))	//PORT
//
//void	Delay(void)
//{
//	for(u32 i = 0; i < 500000 ; i++)
//	{
//		asm("NOP");
//	}
//}
//
//
//int	main(void)
//{
//	/*	Initialization Part		*/
//
//	/*	System Clk init			*/
//	MRCC_voidSysClkInit();
//
//	/*	Toggle Led C13	GPIOC	*/
//	/*	1- Enable Per Clk "RCC" */
//	MRCC_voidEnablePerClk(RCC_APB2,4);
//
//	/*	Direction for C13 is output */
//	GPIOC_CRH = 0x00300000;
//	while(1)
//	{
//		/*	Toggle led */
//		SET_BIT(GPIOC_ODR,13);
//		Delay();
//		CLR_BIT(GPIOC_ODR,13);
//		Delay();
//	}
//	return 0;
//}
