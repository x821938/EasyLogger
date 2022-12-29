#include "log.h" // Global log settings for all sketch in one file

void function3()
{
    LOG_DEBUG("file2", "A debug message from function3 in file2");
}

void function4()
{
    LOG_NOTICE("file2", "A notice from function4 in file2");
}
