# EasyLogger
If you are tired of using Serial.println statements in your code, there is a much better way. The problem with print-statements is that they constantly needs to be deleted or commented out when you don't need them.
It's also quite cumbersome to print variables and text together, often this will result in severel lines of code just to write something like "var=xxx"

## A better and much easier way is with EasyLogger

First include the library
```
#include <EasyLogger.h>
```
Whenever you need to log something do:
```
LOG_DEBUG("TEST", "Here is a debug line");
```
If you want to log some variable information its very easy:
```
int var1 = 17;
char var2[] = "Hello";
LOG_WARNING("TEST", "something is wrong! var1=" << var1 << " and var2=" << var2);
```
Whenever you sketch reach a LOG_XXX line it will be logged to the serial terminal with timestamps like this:
```
000:00:00:00:015  DEBUG     (TEST) : Here is a debug line
000:00:00:00:016  WARNING   (TEST) : something is wrong! var1=17 and var2=Hello
```
## Loglevel Filtering
Just leave all your log-statements in your code. Depending on the loglevel you set in your code the logging will change.
If for example you put this line before your import statement:
```
#define LOG_LEVEL LOG_LEVEL_NOTICE
#include <EasyLogger.h>
```
You will only get log messages with loglevel from LOG_LEVEL_NOTICE and below (eg. WARNING, ERROR, CRITICAL, ALERT and EMERGENCY)
If you don't set LOG_LEVEL in your sketch everything will be logged from LOG_LEVEL_DEBUG down to LOG_LEVEL_EMERGENCY

## Loglevels:
These are the loglevels in EasyLogger
* LOG_LEVEL_EMERGENCY (0)
* LOG_LEVEL_ALERT (1)
* LOG_LEVEL_CRITICAL (2)
* LOG_LEVEL_ERROR (3)
* LOG_LEVEL_WARNING (4)
* LOG_LEVEL_NOTICE (5)
* LOG_LEVEL_INFO (6)
* LOG_LEVEL_DEBUG (7)

If you set LOG_LEVEL to LOG_LEVEL_NONE there will be no logging anymore.

## Service filtering
Imagine some log lines comming from different services (classes, functions or modules that you name)
```
LOG_INFO("svc1", "some info from svc1");
LOG_INFO("svc2", "some info from svc2");
LOG_INFO("svc3", "some info from svc3");
LOG_INFO("svc4", "some info from svc4");
```

If you only are interested in logging from svc1 and svc2 you could add a filter before including EasyLogger.h:
```
#define LOG_FILTER "svc1,svc2"
#include <EasyLogger.h>
```
If you don´t put a filter, then you will get logging for all 3 services.

You could also make an exclusion. If you want logging from all other services than svc1 and scc3 you could do:
```
#define LOG_FILTER "svc1,svc3"
#define LOG_FILTER_EXCLUDE
#include <EasyLogger.h>
```

## Compilation and code optimization
When you set the LOG_LEVEL for your sketch, only the code that actually logs will be compiled.
So the lower the LOG_LEVEL, the smaller your code will be.
If you set LOG_LEVEL to LOG_LEVEL NONE, your code will not be any bigger than if you commented out all the log statements!

## Log commands available
```
LOG_EMERGENCY(char* service, stream logline);
LOG_ALERT(char* service, stream logline);
LOG_CRITICAL(char* service, stream logline);
LOG_ERROR(char* service, stream logline);
LOG_WARNING(char* service, stream logline);
LOG_NOTICE(char* service, stream logline);
LOG_INFO(char* service, stream logline);
LOG_DEBUG(char* service, stream logline);
```
## Examples
See the included examples in /examples folder for usage.