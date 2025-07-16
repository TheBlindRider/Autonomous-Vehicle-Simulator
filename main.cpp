/**
* For CS 136, this project explores how autonomous vehicles respond to various driving conditions by simulating ethical decision-making scenarios.
*
* This program allows users to input various driving conditions such as pedestrian presence and road obstacles.
* Additionally, the user may input the road type, weather, and speed limits.
* Based on these inputs, the system evaluates the safest and most ethical action for the vehicle to take.
* It will also follow a framework that prioritizes pedestrian safety and minimizes overall harm.
*
* Decisions are logged with timestamps and justifications based on ethical reasoning.
* This will allow users to review the vehicle's logic and behavior.
*
* @author Cristal Lara
* @author Cielito Fernandez
* @author Gang Li
* @author Oisin Kiely
* @author Karmina Ramirez
* @version May 31, 2025
*/
#include <QApplication>
#include <QGuiApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}
/*
Sample Run:
🚦 Decision Made: The vehicle will continue to move forward.
☑️ Simulation Run at 05/31/2025 05:17 PM

Time: Sat May 31 17:17:15 2025
| Driving Conditions |
Pedestrian: No
Obstacle: No
Road Type: City
Speed Limit: 35
Weather: Clear
Decision: Continue
Justification: No immediate threats. The vehicle will proceed cautiously.
*/