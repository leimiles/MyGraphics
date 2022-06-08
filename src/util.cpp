#include "util.h"
#include "windows.h"

util::util(/* args */)
{
}

util::~util()
{
}

void util::hideConsole()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}
