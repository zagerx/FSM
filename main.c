#include "stdio.h"
#include "event.h"
#include "key_event.h"

int main(void)
{
    static unsigned char cnt;
    Event *pevent;
    Event *p2 = NULL;
    CreateEventList();
    pevent = creatKeyEvent();
    printf("pevent = 0x%x\r\n",pevent);
    // printf("add list =%d\r\n",pevent->priority);
    Push_eventList(pevent);
    while(1)
    {
        p2 = GetEventFromEventList();
        printf("ssss");
        if(p2 != NULL)
        {
            p2->action();
        }
        if(cnt++ > 1)
        {
            break;
        }
    }
    
    return 0;
}




