#ifndef Logger_H
#define Logger_H

#include <string>
#include <vector>

using namespace std;

class Logger {
public:
    void logDecision(const string& decision, const string& conditions, const string& justification);  // Log a Decision with Contextual Information
    const vector<string>& getLogs() const;  // Retrieve All Logged Entries

private:
    vector<string> logs;
};

#endif