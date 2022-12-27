/* This LOG_LEVEL can be set to LOG_LEVEL_EMERGENCY, LOG_LEVEL_ALERT, LOG_LEVEL_CRITICAL
   LOG_LEVEL_ERROR, LOG_LEVEL_WARNING, LOG_LEVEL_NOTICE, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG
   in order to filter out the lowest level information.
   If set to LOG_LEVEL_NONE, no logging will be done.
*/
// #define LOG_LEVEL LOG_LEVEL_NOTICE

#include <EasyLogger.h>

void setup()
{
    Serial.begin(115200);
    LOG_DEBUG("TEST", "Here is a debug line");

    int var1 = 17;
    char var2[] = "Hello";
    LOG_WARNING("TEST", "something is wrong! var1=" << var1 << " and var2=" << var2);
}

void loop()
{
}