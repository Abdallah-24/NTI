#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"
#include	"RTOS_interface.h"

void	Task1(void);
void	Task2(void);
void	Task3(void);

int	main(void)
{
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port A		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);
	
	/*	Direction for C13 is output Push Pull */
	M_DIO_void_setPinDir(PORTA, PIN0, OUT_2MHZ_PP);
	M_DIO_void_setPinDir(PORTA, PIN1, OUT_2MHZ_PP);
	M_DIO_void_setPinDir(PORTA, PIN2, OUT_2MHZ_PP);
	
	RTOS_voidCreatTask(0,1000,1000,Task1);
	RTOS_voidCreatTask(1,0	 ,2000,Task2);
//	RTOS_voidCreatTask(2,0   ,3000,Task3);
	/*	RTOS initilaization	*/
	RTOS_voidInit();
	
	while(1)
	{

	}
	return 0;
}


void	Task1(void)
{
	static u8	flag1 = 0;
	if(flag1 == 0)
	{
		M_DIO_void_setPinVal(PORTA, PIN0, DIO_HIGH);
		flag1 = 1;
	}else
	{
		M_DIO_void_setPinVal(PORTA, PIN0, DIO_LOW);
		flag1 = 0;
	}
}

void	Task2(void)
{
	static u8	flag2 = 0;
	if(flag2 == 0)
	{
		M_DIO_void_setPinVal(PORTA, PIN1, DIO_HIGH);
		flag2 = 1;
	}else
	{
		M_DIO_void_setPinVal(PORTA, PIN1, DIO_LOW);
		flag2 = 0;
	}
}

void	Task3(void)
{
	static u8	flag3 = 0;
	if(flag3 == 0)
	{
		M_DIO_void_setPinVal(PORTA, PIN2, DIO_HIGH);
		flag3 = 1;
	}else
	{
		M_DIO_void_setPinVal(PORTA, PIN2, DIO_LOW);
		flag3 = 0;
	}
}
