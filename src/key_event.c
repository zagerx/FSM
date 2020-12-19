#include "key_event.h"

#include "stdio.h"

static void keyaction(void);
Event* creatKeyEvent(void)
{
    Event *pkeyevent;
    pkeyevent = (Event *)zg_Malloc(sizeof(Event));
    printf("pkeyevent = 0x%x\r\n",pkeyevent);
    pkeyevent->priority = 4;
    pkeyevent->action = keyaction;

    /*创建按键状态机*/
    creatKeyfsm();
    return pkeyevent;
}

static void keyaction(void)
{
    printf("he\r\n");
    /*执行状态机调度*/
    keyfsmDispatch();
}



