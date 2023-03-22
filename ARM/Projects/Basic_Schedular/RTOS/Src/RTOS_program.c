#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"STK_interface.h"
#include	"RTOS_interface.h"
#include	"RTOS_private.h"
#include	"RTOS_config.h"


#ifndef		NULL
#define		NULL	(void *)0
#endif

static Task_TCB Tasks[NUM_OF_TASKS];
static u16 Ticks = 0 ;
void	RTOS_voidInit(void)
{
	/*	Tick Time = 1 msec				*/
	/*	SysTick Init, SysTick = 1usec	*/
	STK_voidInit();
	/*	SysTick call 1000usec = 1msec	*/
	STK_voidSetIntervalPeriodic(1000,RTOS_voidScheduler);
}
void	RTOS_voidCreatTask(u8 priority ,u16 frist_delay , u16 period, void (*ptr_f)(void))
{
	if((priority < NUM_OF_TASKS) && (ptr_f != NULL))
	{
		Tasks[priority].u16_Periodicity = 	period;
		Tasks[priority].u16_FD 			= 	frist_delay;
		Tasks[priority].pf 				= 	ptr_f;
		Tasks[priority].enu_State 		= 	RUNNING;
	}
}
void	RTOS_voidSuspendTask(u8 priority)
{
	if(priority < NUM_OF_TASKS)
	{
		Tasks[priority].enu_State 		= 	SUSPENDED;
	}
}
void	RTOS_voidResumeTask(u8 priority)
{
	if(priority < NUM_OF_TASKS)
	{
		Tasks[priority].enu_State 		= 	RUNNING;
	}
}
void	RTOS_voidDeleteTask(u8 priority)
{
	if(priority < NUM_OF_TASKS)
	{
		Tasks[priority].pf 		= 	NULL;
	}
}

/*
 * 			Method -> 1
static void RTOS_voidScheduler(void)
{
	for(u8 i = 0 ; i < NUM_OF_TASKS ; i++)
	{
		if(Tasks[i].pf != NULL)
		{
			if(((Ticks % Tasks[i].u16_Periodicity) == 0) && (Tasks[i].u16_FD == 0) && (Tasks[i].enu_State == RUNNING))
			{
				Tasks[i].pf();
			}
			else
			{
				// DO NOTHING
			}

			if(Tasks[i].u16_FD > 0)
			{
				Tasks[i].u16_FD--;
			}
			else
			{
				// DO NOTHING
			}
		}
		else
		{
			// DO NOTHING
		}
	}
	Ticks++;
}
*/

//  * 			Method -> 2
static void RTOS_voidScheduler(void)
{
	for(u8 i = 0 ; i < NUM_OF_TASKS ; i++)
	{
		if(Tasks[i].pf != NULL)
		{
			if((Tasks[i].u16_FD == 0) && (Tasks[i].enu_State == RUNNING))
			{
				Tasks[i].pf();
				Tasks[i].u16_FD = Tasks[i].u16_Periodicity - 1;
			}
			else
			{
				Tasks[i].u16_FD--;
			}
		}
		else
		{
			// DO NOTHING
		}
	}
}
