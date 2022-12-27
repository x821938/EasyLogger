/* This LOG_LEVEL can be set to LOG_LEVEL_EMERGENCY, LOG_LEVEL_ALERT, LOG_LEVEL_CRITICAL
   LOG_LEVEL_ERROR, LOG_LEVEL_WARNING, LOG_LEVEL_NOTICE, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG
   in order to filter out the lowest level information.
   If set to LOG_LEVEL_NONE, no logging will be done.
*/
#define LOG_LEVEL LOG_LEVEL_DEBUG

/* Use the LOG_FILTER definition with a comma separated list of services you want to show. */
#define LOG_FILTER "SETU,SVC1,SVC4"

/* If you define LOG_FILTER_EXCLUDE, then everything will be logged except services
   listed in LOG_FILTER. Effectively it reverses the filter */
#define LOG_FILTER_EXCLUDE

/* -------------------------------------------------------------------*/

#include <EasyLogger.h>

// An array of animals to choose from
const char *animals[] = {"Horse", "Cow", "Chicken", "Dog", "Snake", "Elephant"};

// An array of services to choose from
const char *services[] = {"SVC1", "SVC2", "SVC3", "SVC4"};

void setup()
{
    Serial.begin(115200);
    LOG_INFO("SETU", "Program has started");
}

void loop()
{
    // Get some random numbers in order to pick a loglevel, a delay, an animal and a service name
    int rnd_level = random(0, 8);
    int rnd_delay = random(1000, 3000);

    int rnd_animal_number = random(0, 6);
    const char *rnd_animal = animals[rnd_animal_number];

    int rnd_service_number = random(0, 4);
    const char *rnd_service = services[rnd_service_number];

    LOG_DEBUG("RAND", "Loglevel=" << rnd_level << ", Delay=" << rnd_delay << "ms, Animal number=" << rnd_animal_number);

    // Depending on the random loglevel number a message is logged with specific loglevel.
    // Notice how the stream operator is used to mix text and variables in an easy way
    if (rnd_level == 0)
        LOG_EMERGENCY(rnd_service, "The " << rnd_animal << " is in emergency");
    if (rnd_level == 1)
        LOG_ALERT(rnd_service, "The " << rnd_animal << " is on alert");
    if (rnd_level == 2)
        LOG_CRITICAL(rnd_service, "The " << rnd_animal << " is critical");
    if (rnd_level == 3)
        LOG_ERROR(rnd_service, "Error finding the " << rnd_animal);
    if (rnd_level == 4)
        LOG_WARNING(rnd_service, "Warning! The " << rnd_animal << " is behind you");
    if (rnd_level == 5)
        LOG_NOTICE(rnd_service, "Please notice the " << rnd_animal);
    if (rnd_level == 6)
        LOG_INFO(rnd_service, "For your info the " << rnd_animal << " is here");
    if (rnd_level == 7)
        LOG_DEBUG(rnd_service, "The " << rnd_animal << " wants it's fur debugged");

    delay(rnd_delay);
}