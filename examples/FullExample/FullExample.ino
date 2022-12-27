/* This LOG_LEVEL can be set to LOG_LEVEL_EMERGENCY, LOG_LEVEL_ALERT, LOG_LEVEL_CRITICAL
   LOG_LEVEL_ERROR, LOG_LEVEL_WARNING, LOG_LEVEL_NOTICE, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG
   in order to filter out the lowest level information.
   If set to LOG_LEVEL_NONE, no logging will be done.
*/
#define LOG_LEVEL LOG_LEVEL_NOTICE
#include <EasyLogger.h>

// An array of animals to choose from
const char *animals[] = {"Horse", "Cow", "Chicken", "Dog", "Snake", "Elephant"};

void setup()
{
    Serial.begin(115200);
    LOG_INFO("SET", "Program has started");
}

void loop()
{
    // Get some random numbers in order to pick a loglevel, a delay and an animal
    int rnd_level = random(0, 8);
    int rnd_delay = random(1000, 3000);

    int rnd_animal_number = random(0, 6);
    const char *rnd_animal = animals[rnd_animal_number];

    LOG_DEBUG("RND", "Loglevel=" << rnd_level << ", Delay=" << rnd_delay << "ms, Animal number=" << rnd_animal_number);

    // Depending on the random loglevel number a message is logged with specific loglevel.
    // Notice how the stream operator is used to mix text and variables in an easy way
    if (rnd_level == 0)
        LOG_EMERGENCY("LEV", "The " << rnd_animal << " is in emergency");
    if (rnd_level == 1)
        LOG_ALERT("LEV", "The " << rnd_animal << " is on alert");
    if (rnd_level == 2)
        LOG_CRITICAL("LEV", "The " << rnd_animal << " is critical");
    if (rnd_level == 3)
        LOG_ERROR("LEV", "Error finding the " << rnd_animal);
    if (rnd_level == 4)
        LOG_WARNING("LEV", "Warning! The " << rnd_animal << " is behind you");
    if (rnd_level == 5)
        LOG_NOTICE("LEV", "Please notice the " << rnd_animal);
    if (rnd_level == 6)
        LOG_INFO("LEV", "For your info the " << rnd_animal << " is here");
    if (rnd_level == 7)
        LOG_DEBUG("LEV", "The " << rnd_animal << " wants it's fur debugged");

    delay(rnd_delay);
}