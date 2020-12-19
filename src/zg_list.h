#ifndef _ZG_LIST_H
#define _ZG_LIST_H

#include "zg_heap.h"
#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
/*节点类型*/
typedef struct list_node  LIST_NODE;

struct list_node
{
    /* data */
    LIST_NODE *pPreNode;
    LIST_NODE *pNextNode;    
    
    void    *pData;

    uint8_t Priority;
};

/*根节点类型*/
typedef struct root_node   ROOT_NODE;

struct root_node
{
    /* data */
    LIST_NODE *FirstNode;
    LIST_NODE *EndNote;
    uint8_t NodeNum;
};


void list_test(void);
ROOT_NODE* CreateList(void);
void InitList(ROOT_NODE *plist);
void InsertNodeToListHead(ROOT_NODE *plist,LIST_NODE *newnode);
bool ListIsEmpty(ROOT_NODE *plist);
LIST_NODE *GetNodeFromList(ROOT_NODE *Plist,uint8_t num);



#endif
