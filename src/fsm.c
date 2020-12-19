/*
*		文件编码格式为 UTF-8
*		不要在MDK中进行编辑！！！！！
*       
*
*/
#include "fsm.h"
#include "stdio.h"
/*创建一个状态机*/
FSM* CreateFsmMachine(void)
{
    FSM *fsm;
    fsm = NULL;
    fsm = zg_Malloc(sizeof(FSM));
    printf("fsm = 0x%x\r\n",fsm);
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


