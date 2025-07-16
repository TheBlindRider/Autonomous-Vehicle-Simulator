#include "Logger.h"
#include <ctime>

using namespace std;

// Logs a Decision Along with the Conditions and Justification
void Logger::logDecision(const string& decision, const string& conditions, const string& justification) {
    time_t now = time(0);  // Obtain Current Time
    struct tm* timeInfo = localtime(&now);

    // Format the Timestamp
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", timeInfo);
    string formattedTime(buffer);

    // Create and Store the Log Entry
    logs.push_back("Time: " + formattedTime +
                   "\n| Driving Conditions |" + conditions +
                   "\nDecision: " + decision +
                   "\nJustification: " + justification + "\n");
}

const vector<string>& Logger::getLogs() const {
    return logs;
}