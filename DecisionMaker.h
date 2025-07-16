#ifndef DecisionMaker_H
#define DecisionMaker_H

#include <string>
#include "Logger.h"
#include "Vehicle.h"

using namespace std;

// The DecisionMaker Class Evaluates Conditions and Makes Ethical Driving Decisions
class DecisionMaker {
public:
    DecisionMaker(Logger& logger);

    // Evaluates Input Conditions and Controls the Vehicle's Behavior
    void evaluateConditions(bool pedestrian, bool obstacle, string roadType,
                            int speedLimit, string weather, Vehicle& vehicle);

private:
    Logger& logger;  // Logger to Record Decisions
};

#endif