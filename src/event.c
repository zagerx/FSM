/*
*    主程序创建事件列表     然后轮询    事件列表不为空，从表上获取事件开始执行      获取到KEY事件  创建事件状态机并且执行       执行完成之后根据需要是否注销状态机和事件
*                                                                                           是否需要重新创建状态        不需要则直接执行状态机
*
*           事件应该具有优先级  事件列表根据事件优先级排序
*           
*软件流程:
*               1、创建事件列表  
*
*   事件API:    
*               1、创建事件列表
*               2、添加事件
*               3、删除事件
*               4、事件执行
*
*/



#include "event.h"

/*事件列表用数组来代替*/

Event* gEventlist[4];

ROOT_NODE *pEventListRoot;
ROOT_NODE* CreateEventList(void)
{
    /*
        伪代码创建成功
        生成一个事件链表的头指针
    
        永不被删除
    */
   pEventListRoot = CreateList();
   return pEventListRoot;
}

/*添加事件      推入事件列表*/
void Push_eventList(Event *e)
{
    // gEventlist[0] = e;
    LIST_NODE *pNode;
    pNode = zg_Malloc(sizeof(LIST_NODE));
    pNode->pData = (void *)e;
    pNode->Priority = e->priority;
    InsertNodeToListHead(pEventListRoot,pNode);
} 


/*获取事件      从事件列表中*/
Event* GetEventFromEventList(void)
{
    // return gEventlist[0];
    LIST_NODE *pNode;
    Event *e;
    pNode = GetNodeFromList(pEventListRoot,1);//获取首个节点事件
    e = (Event *)pNode->pData;
    return e;
}

/*执行事件      */











