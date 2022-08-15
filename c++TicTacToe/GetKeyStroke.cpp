#include <iostream>
#include <windows.h>


bool getconchar(KEY_EVENT_RECORD& krec)
{
    DWORD cc;
    INPUT_RECORD irec;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    if (h == NULL)
    {
        return false; // console not found
    }

    for (; ; )
    {
        ReadConsoleInput(h, &irec, 1, &cc);
        if (irec.EventType == KEY_EVENT
            && ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
            )//&& ! ((KEY_EVENT_RECORD&)irec.Event).wRepeatCount )
        {
            krec = (KEY_EVENT_RECORD&)irec.Event;
            return true;
        }
        
    }
    return false; //future ????
}