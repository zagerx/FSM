#include "key_event.h"

#include "stdio.h"

static void keyaction(void);
Event* creatKeyEvent(void)
{
    Event *pkeyevent;
    pkeyevent = zg_Malloc(sizeof(Event));

    pkeyevent->priority = 1;
    pkeyevent->action = keyaction;
}


static void keyaction(void)
{
    printf("he\r\n");
}