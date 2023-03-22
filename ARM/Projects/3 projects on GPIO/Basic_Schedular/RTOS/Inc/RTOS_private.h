#ifndef		RTOS_PRIVATE_H
#define		RTOS_PRIVATE_H

typedef enum
{
	SUSPENDED,
	RUNNING
}Task_state;
typedef	struct
{
	u16 u16_Periodicity;
	u16 u16_FD;
	void	(*pf)	(void);
	Task_state enu_State;
}Task_TCB;

static void RTOS_voidScheduler(void);

#endif
