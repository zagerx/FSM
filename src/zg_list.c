
/**
 * *
 * *    创建链表
 * *    初始化链表
 *      添加节点    从头插入    从尾部插入
 *      删除节点
 *      从尾部获取
 *      获取指定节点
 *      获取链表节点个数
 * 
 * 
 *      节点内容    指向前一个节点指针
 *                  指向后一个节点指针
 *                  节点优先级
 *                  节点个数            
 * 
 * 
*/

#include "zg_list.h"


ROOT_NODE* CreateList(void)
{
    ROOT_NODE *proot = NULL;
    proot = zg_Malloc(sizeof(ROOT_NODE));
    return proot;
}

void InitList(ROOT_NODE *plist)
{
    plist->FirstNode = NULL;
    plist->EndNote = NULL;
    plist->NodeNum = 0;
}

/*按节点优先级插入节点      升序排列*/
void InsertNodeToListHead(ROOT_NODE *plist,LIST_NODE *newnode)
{
    LIST_NODE *pcmnode;//待比较的节点
    /*判断链表内是否有节点*/
    if(!plist->FirstNode)//无节点情况
    {
        plist->FirstNode = newnode;
        newnode->pPreNode = NULL;
        newnode->pNextNode = NULL;
        plist->EndNote = newnode;
        plist->NodeNum++;
    }else{
        /*首先获取链表上的第二个节点*/
        pcmnode = plist->FirstNode->pNextNode;        
        for(unsigned char i = 0;i < plist->NodeNum;i++)
        {
            if(newnode->Priority <= plist->FirstNode->Priority)
            {
                newnode->pNextNode = plist->FirstNode;
                newnode->pPreNode = NULL;
                plist->FirstNode->pPreNode = newnode;
                plist->FirstNode = newnode;
                break;
            }else if (newnode->Priority >= plist->EndNote->Priority)
            {
                /* code */
                newnode->pNextNode = NULL;
                newnode->pPreNode = plist->EndNote;
                plist->EndNote->pNextNode = newnode;
                plist->EndNote = newnode;
                break;
            }else{
                if(newnode->Priority <= pcmnode->Priority)
                {
                    newnode->pNextNode = pcmnode;
                    newnode->pPreNode = pcmnode->pPreNode;
                    pcmnode->pPreNode->pNextNode = newnode;
                    break;
                }
                pcmnode = pcmnode->pNextNode;
            }
        }
        plist->NodeNum++;
    }
}

/*true 不为空*/
bool ListIsEmpty(ROOT_NODE *plist)
{
    if(plist->NodeNum > 0)
    {
        return true;
    }
    return false;
}
/*从尾部获取节点    并且从链表移除该节点*/
LIST_NODE *GetNodeFromListTail(ROOT_NODE *Plist)
{
    LIST_NODE *pNode1;
    LIST_NODE *pNode2;
    if(!ListIsEmpty(Plist))
    {
        printf("list empty\r\n");
        return NULL;
    }
    pNode1 = Plist->EndNote;

    pNode2 = Plist->EndNote->pPreNode;//倒数第二个
    pNode2->pNextNode = NULL;
    Plist->EndNote = pNode2;
    Plist->NodeNum--;


    return pNode1;
}

/*
*   获取指定位置的节点  不删除
*   num = 0代表第一个节点
**/
LIST_NODE *GetNodeFromList(ROOT_NODE *Plist,uint8_t num)
{
    if(num >= Plist->NodeNum)
    {
        printf("ddd\r\n");
        return NULL;
    }

    /*获取首个节点*/
    LIST_NODE *pnode;
    pnode = Plist->FirstNode;
    for(unsigned char i = 0;i < num;i++)
    {
        pnode = pnode->pNextNode;
    }

    return pnode;
}


void list_test(void)
{
    static ROOT_NODE* A_list;
    A_list = CreateList();
    if(A_list == NULL)
    {
        printf("list create fail\r\n");
        while(1);
    }

    InitList(A_list);

    for(unsigned char i = 1;i<10;i++)
    {
        LIST_NODE *pNode;
        pNode = zg_Malloc(sizeof(LIST_NODE));
        pNode->Priority = i;
        InsertNodeToListHead(A_list,pNode);
    }

    {
        LIST_NODE  *pNodex;
        pNodex = A_list->FirstNode;
        for(unsigned char i = 1;i<10;i++)
        {
            printf("priority = %d\r\n",pNodex->Priority);
            pNodex = pNodex->pNextNode;
        }   
        printf("num = %d\r\n",A_list->NodeNum);        
    }    

    printf("*************************************\r\n");


    {
        LIST_NODE *pNode;
        pNode = zg_Malloc(sizeof(LIST_NODE));
        pNode->Priority = 0;
        InsertNodeToListHead(A_list,pNode);  
    } 
    {
        LIST_NODE *pNode;
        pNode = zg_Malloc(sizeof(LIST_NODE));
        pNode->Priority = 5;
        InsertNodeToListHead(A_list,pNode);  
    } 
    {
        LIST_NODE *pNode;
        pNode = zg_Malloc(sizeof(LIST_NODE));
        pNode->Priority = 7;
        InsertNodeToListHead(A_list,pNode);  
    } 
    {
        LIST_NODE *pNode;
        pNode = zg_Malloc(sizeof(LIST_NODE));
        pNode->Priority = 15;
        InsertNodeToListHead(A_list,pNode);  
    }    
    {
        LIST_NODE  *pNodex;
        pNodex = A_list->FirstNode;
        for(unsigned char i = 1;i<14;i++)
        {
            printf("priority = %d\r\n",pNodex->Priority);
            pNodex = pNodex->pNextNode;
        }   
        printf("num = %d\r\n",A_list->NodeNum);        
    }   

    printf("get last node = %d\r\n",GetNodeFromListTail(A_list)->Priority);


    /*获取指定位置的节点  不移除*/
    for(unsigned char i = 0;i<A_list->NodeNum;i++)
    {
        printf("get %d node = %d\r\n",i,GetNodeFromList(A_list,i)->Priority);
    }
    
    while(1);
}








