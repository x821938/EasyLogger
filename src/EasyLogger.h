#ifndef _LOGGING_h
#define _LOGGING_h
    #include <Arduino.h>

    // Default loglevel to DEBUG, unless user defines something else before including logging.h.
    #ifndef LOG_LEVEL
    #define LOG_LEVEL LOG_LEVEL_DEBUG
    #endif

    // Streaming operator for serial print use to make nice logging like
    // LOG_DEBUG("TST", "var1" << var1 << ", var2=" << var2)
    template <class T>
    inline Print &operator<<(Print &obj, T arg)
    {
        obj.print(arg);
        return obj;
    }
    #define endl "\r\n"

    // LOG levels
    #define LOG_LEVEL_NONE -1
    #define LOG_LEVEL_EMERGENCY 0
    #define LOG_LEVEL_ALERT 1
    #define LOG_LEVEL_CRITICAL 2
    #define LOG_LEVEL_ERROR 3
    #define LOG_LEVEL_WARNING 4
    #define LOG_LEVEL_NOTICE 5
    #define LOG_LEVEL_INFO 6
    #define LOG_LEVEL_DEBUG 7

    #if LOG_LEVEL > LOG_LEVEL_NONE

        // Internal logging function that will be wrapped by definitions like LOG_NOTICE, LOG_ALERT, LOG_CRITICAL etc.
        // Prints time, loglevel and service code. No endline. That will be streamed by macro-wrapper
        static void print_log_line_header(uint8_t loglevel, const char *svc)
        {
            static const char *loglevels_text[] = {"EMERGENCY", "ALERT    ", "CRITICAL ", "ERROR    ", "WARNING  ", "NOTIC    ", "INFO     ", "DEBUG    "};
            long logTime = millis();
            long seconds = logTime / 1000;
            long minutes = seconds / 60;
            long hours = minutes / 60;
            long days = hours / 24;
            char logFormattedTime[17];
            sprintf(logFormattedTime, "%03u:%02u:%02u:%02u:%03u", days, hours % 24, minutes % 60, seconds % 60, logTime % 1000);
            Serial << logFormattedTime << "  ";
            Serial << loglevels_text[loglevel] << " (" << svc << ") : ";
        }

        #ifdef LOG_FILTER
            /* If logfiltering is enabled then this function decides if the service should be logged.
               It checks service against LOG_FILTER. Depending on LOG_FILTER_EXCLUDE is set, this
               function returns true or false, showing if it should be logged */
            static bool should_log_line(const char *svc) 
            {
                #ifdef LOG_FILTER_EXCLUDE
                    static const bool log_filter_exclude = true;
                #else 
                    static const bool log_filter_exclude = false;
                #endif

                bool svc_found_in_filter = (strstr(LOG_FILTER, svc) != NULL);
                if (svc_found_in_filter && !log_filter_exclude) return (true);
                if (!svc_found_in_filter && log_filter_exclude) return (true);
                return (false);
            }
        #endif

    #endif

    // Define logging macro functions per LOG_LEVEL
    #if LOG_LEVEL >= LOG_LEVEL_DEBUG
        #ifdef LOG_FILTER
            #define LOG_DEBUG(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_DEBUG, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_DEBUG(svc, content) { print_log_line_header(LOG_LEVEL_DEBUG, svc); Serial << content; Serial << endl; }
        #endif
    #endif
    
    #if LOG_LEVEL >= LOG_LEVEL_INFO
        #ifdef LOG_FILTER
            #define LOG_INFO(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_INFO, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_INFO(svc, content) { print_log_line_header(LOG_LEVEL_INFO, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_NOTICE
        #ifdef LOG_FILTER
            #define LOG_NOTICE(svc, content) if (should_log_line(svc)) { { print_log_line_header(LOG_LEVEL_NOTICE, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_NOTICE(svc, content) { print_log_line_header(LOG_LEVEL_NOTICE, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_WARNING
        #ifdef LOG_FILTER
            #define LOG_WARNING(svc, content) if (should_log_line(svc)) { { print_log_line_header(LOG_LEVEL_WARNING, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_WARNING(svc, content) { print_log_line_header(LOG_LEVEL_WARNING, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_ERROR
        #ifdef LOG_FILTER
            #define LOG_ERROR(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_ERROR, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_ERROR(svc, content) { print_log_line_header(LOG_LEVEL_ERROR, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_CRITICAL
        #ifdef LOG_FILTER
            #define LOG_CRITICAL(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_CRITICAL, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_CRITICAL(svc, content) { print_log_line_header(LOG_LEVEL_CRITICAL, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_ALERT
        #ifdef LOG_FILTER
            #define LOG_ALERT(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_ALERT, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_ALERT(svc, content) { print_log_line_header(LOG_LEVEL_ALERT, svc); Serial << content; Serial << endl; }
        #endif
    #endif

    #if LOG_LEVEL >= LOG_LEVEL_EMERGENCY
        #ifdef LOG_FILTER
            #define LOG_EMERGENCY(svc, content) { if (should_log_line(svc)) { print_log_line_header(LOG_LEVEL_EMERGENCY, svc); Serial << content; Serial << endl; } }
        #else
            #define LOG_EMERGENCY(svc, content) { print_log_line_header(LOG_LEVEL_EMERGENCY, svc); Serial << content; Serial << endl; }
        #endif
    #endif


    // If logging functions has not been defined before, because of too low LOG_LEVEL, then we define them as nothing here
    #ifndef LOG_DEBUG
        #define LOG_DEBUG(svc, content)
    #endif
    #ifndef LOG_INFO
        #define LOG_INFO(svc, content)
    #endif
    #ifndef LOG_NOTICE
        #define LOG_NOTICE(svc, content)
    #endif
    #ifndef LOG_WARNING
        #define LOG_WARNING(svc, content)
    #endif
    #ifndef LOG_ERROR
        #define LOG_ERROR(svc, content)
    #endif
    #ifndef LOG_CRITICAL
        #define LOG_CRITICAL(svc, content)
    #endif
    #ifndef LOG_ALERT
        #define LOG_ALERT(svc, content)
    #endif
    #ifndef LOG_EMERGENCY
        #define LOG_EMERGENCY(svc, content)
    #endif

#endif // ifndef _LOGGING_h