#ifndef		RTOS_INTERFACE_H
#define		RTOS_INTERFACE_H


void	RTOS_voidInit(void);
void	RTOS_voidCreatTask(u8 priority ,u16 frist_delay , u16 period, void (*ptr_f)(void));
void	RTOS_voidSuspendTask(u8 priority);
void	RTOS_voidResumeTask(u8 priority);
void	RTOS_voidDeleteTask(u8 priority);

#endif
