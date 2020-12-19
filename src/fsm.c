/*
*		文件编码格式为 UTF-8
*		不要在MDK中进行编辑！！！！！
*       
*
*/
#include "fsm.h"

/*创建一个状态机*/
FSM* CreateFsmMachine(void)
{
    FSM *fsm;
    fsm = NULL;
    fsm = zg_Malloc(sizeof(FSM));
    return fsm;
}

/*初始化一个状态机*/
void InitFsmMachine(FSM *state)
{
    // state->
}

/*删除一个状态机*/
void DestroyFsmMachine(FSM *state)
{
    zg_Free(state);
}


