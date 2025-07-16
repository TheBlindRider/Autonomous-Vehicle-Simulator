#include "DecisionMaker.h"

using namespace std;

DecisionMaker::DecisionMaker(Logger& logger) : logger(logger) {};

void DecisionMaker::evaluateConditions(bool pedestrian, bool obstacle, string roadType,
                                       int speedLimit, string weather, Vehicle& vehicle) {
    string decision, justification, conditions;

    // Compose Current Conditions
    conditions = "\nPedestrian: " + string(pedestrian ? "Yes" : "No") +
                 "\nObstacle: " + string(obstacle ? "Yes" : "No") +
                 "\nRoad Type: " + roadType +
                 "\nSpeed Limit: " + to_string(speedLimit) +
                 "\nWeather: " + weather;

    // Simple Ethical Framework (Based on Interviewee Consensus)
    if (pedestrian) {
        decision = "Stop";
        justification = "Prioritizing pedestrian safety based on ethical framework.";
        vehicle.stop();
    } else if (obstacle) {
        decision = "Slow Down";
        justification = "Minimizing harm while obstacle is present; no pedestrian.";
        vehicle.slowDown();
    } else if (weather == "fog" || weather == "rain") {
        decision = "Slow Down";
        justification = "Reduced visibility and slippery roads.";
        vehicle.slowDown();
    } else {
        decision = "Continue";
        justification = "No immediate threats. The vehicle will proceed cautiously.";
        vehicle.continueDriving();
    }

    logger.logDecision(decision, conditions, justification);
}