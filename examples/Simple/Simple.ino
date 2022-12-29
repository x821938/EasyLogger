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