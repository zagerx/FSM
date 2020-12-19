#ifndef _EVENT_H
#define _EVENT_H

#include "stdint.h"
#include "fsm.h"
#include "zg_heap.h"
#include "zg_list.h"


typedef void (*fpExcute)(void);//事件的执行不通过状态机完成
typedef void (*fpEXcuteFSM)(FsmState *_state,FSMsingle sig);//事件执行通过状态机完成
struct _event{
    uint8_t     priority;       //事件优先级
    fpExcute    action;         //事件动作 
    fpEXcuteFSM fsmaction;      //通过状态机完成事件动作 
};

typedef struct _event   Event;




ROOT_NODE* CreateEventList(void);
void Push_eventList(Event *e);
Event* GetEventFromEventList(void);
#endif // !_EVENT_H

