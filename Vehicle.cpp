#include "Vehicle.h"

using namespace std;

// Represents the Vehicle's Behavior and Driving Status
void Vehicle::stop() {
    status = "The vehicle has stopped.";
}

void Vehicle::slowDown() {
    status = "The vehicle is slowing down.";
}

void Vehicle::continueDriving() {
    status = "The vehicle will continue to move forward.";
}

string Vehicle::getStatus() const {
    return status;
}

void Vehicle::setStatus(const string& newStatus) {
    status = newStatus;
}