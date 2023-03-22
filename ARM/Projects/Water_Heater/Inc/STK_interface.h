#ifndef		STK_INTERFACE_H
#define		STK_INTERFACE_H


void	STK_voidInit(void);
void	STK_voidBusyWait(u32 Ticks);
void	STK_voidSetIntervalSingle(u32 Ticks,void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32 Ticks,void (*Pf)(void));
void	STK_voidStopInterval(void);
u32		STK_u32GetElapsedTime(void);
u32		STK_u32GetRemainingTime(void);


#endif