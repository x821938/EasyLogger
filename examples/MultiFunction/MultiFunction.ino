#include "log.h" // Global log settings for all sketch in one file

#include "MultiFunction_file1.h"
#include "MultiFunction_file2.h"

void setup()
{
    Serial.begin(115200);
    LOG_EMERGENCY("setup", "Just a fake emergency");
    function1();
    function3();
    function2();
    function4();
}

void loop()
{
}