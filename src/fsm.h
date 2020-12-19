/*
*		文件编码格式为 UTF-8
*		不要在MDK中进行编辑！！！！！
*/



#ifndef _FSM_H
#define _FSM_H
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

#include "zg_heap.h"

/* */
enum {
    FSM_NULL_SIG = 0,
    FSM_INIT_SIG,
    FSM_IDLE_SIG,
    FSM_ENTER_SIG,
    FSM_EXIT_SIG,
    FSM_USER_SIG_START = 32
};


typedef uint32_t    FSMsingle;
typedef struct  fsm FSM;

typedef void(*FsmState)(FSM *fsm,FSMsingle single);


struct  fsm{
    FsmState     _State; 
    FSMsingle   sig;                                                                                                                                                
    bool        running;
};

//状态调度
#define FsmDispatch(me_, e_) ((me_)->_State)((me_), (e_))
/*状态迁移*/
#define QFSM_TRAN(me, target_)          do{\
                                            { \
                                            FSMsingle sig; \
                                            sig = FSM_EXIT_SIG; \
                                            (*(me)->_State)((me), (sig)); \
                                            ((FSM *)me)->_State = (FsmState)(target_); \
                                            sig = FSM_ENTER_SIG; \
                                            (*(me)->_State)((me), (sig)); \
                                            }\
                                        }while(0)
FSM* CreateFsmMachine(void);
#endif // !_FSM_H
