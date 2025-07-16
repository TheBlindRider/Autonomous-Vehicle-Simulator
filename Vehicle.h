#ifndef Vehicle_H
#define Vehicle_H

#include <string>

using namespace std;

// The Vehicle Class Defines Vehicle Behavior and Status for Simulation
class Vehicle {
public:
    void stop();
    void slowDown();
    void continueDriving();
    void setStatus(const string& newStatus);
    string getStatus() const;

private:
    string status;  // Holds the Current Status of the Vehicle
};

#endif