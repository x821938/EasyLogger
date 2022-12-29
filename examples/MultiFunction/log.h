/* This LOG_LEVEL can be set to LOG_LEVEL_EMERGENCY, LOG_LEVEL_ALERT, LOG_LEVEL_CRITICAL
   LOG_LEVEL_ERROR, LOG_LEVEL_WARNING, LOG_LEVEL_NOTICE, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG
   in order to filter out the lowest level information.
   If set to LOG_LEVEL_NONE, no logging will be done.
   If not defined the the level will default to LOG_LEVEL_DEBUG. Everything will get logged
*/

#define LOG_LEVEL LOG_LEVEL_DEBUG

/* Use the LOG_FILTER definition with a comma separated list of services you want to show.
   Every service in this list will get logged
*/

#define LOG_FILTER "xxxxx"

/* If you define LOG_FILTER_EXCLUDE, then everything will be logged except services
   listed in LOG_FILTER. Effectively it reverses the filter */

#define LOG_FILTER_EXCLUDE

/* LOG_FORMATTING can be set to LOG_FORMATTING_HMS, LOG_FORMATTING_MILLIS or LOG_FORMATTING_NOTIME
   If not defined, the standard will be LOG_FORMAT_HMS */

#define LOG_FORMATTING LOG_FORMATTING_HMS

#include <EasyLogger.h>