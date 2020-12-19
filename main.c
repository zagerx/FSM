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
    Push_eventList(pevent);
    while(1)
    {
        p2 = GetEventFromEventList();
        if(p2 != NULL)
        {
            p2->action();
        }
        if(cnt++ > 1)
        {
            break;
        }
    }
    printf("hello world\r\n");
    return 0;
}




