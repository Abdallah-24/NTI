#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H


#define		RCC_AHB			0
#define		RCC_APB1		1
#define		RCC_APB2		2
// for ADC prescaler
#define		RCC_ADC_PRE_2			0
#define		RCC_ADC_PRE_4			1
#define		RCC_ADC_PRE_6			2
#define		RCC_ADC_PRE_8			3

void	MRCC_voidSysClkInit(void);
void	MRCC_voidEnablePerClk(u8 PerBus,u8 PerNum);
void	MRCC_voidDisablePerClk(u8 PerBus,u8 PerNum);
void	MRCC_voidSetADCPre(u8 Copy_u8Pre);

#endif
