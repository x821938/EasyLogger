#include "log.h" // Global log settings for all sketch in one file

void function1()
{
    LOG_ALERT("file1", "An alert from function1 in file1");
}

void function2()
{
    LOG_WARNING("file1", "A warning from function2 in file1");
}
