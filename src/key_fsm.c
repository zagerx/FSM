#include "key_fsm.h"

#include "stdio.h"
FSM *KeyfsmHandle;
static void KeyfsmInitsta(FSM *fsm,FSMsingle single);
FSM* creatKeyfsm(void)
{
   KeyfsmHandle = CreateFsmMachine();
    printf("KeyfsmHandle = 0x%x\r\n",KeyfsmHandle);
   KeyfsmHandle->_State = KeyfsmInitsta;
   KeyfsmHandle->sig = FSM_ENTER_SIG;
   return KeyfsmHandle;
}

void keyfsmDispatch(void)
{
    FsmDispatch(KeyfsmHandle,KeyfsmHandle->sig);
}


static void KeyfsmInitsta(FSM *fsm,FSMsingle single)
{
    switch (single)
    {
    case FSM_ENTER_SIG:
        printf("first key fsm normal\r\n");
        /* code */
        break;
    
    default:
        break;
    }
}

