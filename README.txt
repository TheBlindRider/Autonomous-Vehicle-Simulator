🚗 Autonomous Vehicle Ethical Decision Simulator 🚗

This project for CS 136 (Introduction to Data Structures) is a GUI-based simulation that models ethical decision-making in autonomous vehicles. Built using C++ and the Qt framework, the simulator allows users to define road conditions, environmental factors, and obstacles, then observes how the vehicle responds based on a simplified ethical framework.

📁 Project Overview 📁

- Team 2 Members:
  - Cristal Lara (Lead Developer)
    - Full development of the simulation software, including logic, UI, backend, and debugging.
    - Directed all programming decisions and implementation.
  - Cielito Fernandez
  - Oisin Kiely
  - Gang Li
  - Karmina Ramirez
- All remaining team members contributed to the project write-up, presentation preparation, and assisted with debugging.
- Language: C++
- Framework: Qt
- IDE Support: Visual Studio Code
- Key Classes:
  - MainWindow: Handles the GUI and simulation logic.
  - Vehicle: Tracks vehicle status (stop, slow down, continue).
  - DecisionMaker: Applies decision logic based on current conditions.
  - Logger: Logs the decisions for review.

🛠️ Build Instructions 🛠️
1) Open Qt Creator
2) Go to "File > Open File or Project..."
3) Select the following file: "Autonomous Vehicle Simulator/CMakeLists.txt"
4) Choose a build location when prompted
5) Click the Run button or press Ctrl + R to build and execute the application

📷 Media Note 📷

The animated GIF that visually represents the vehicle's movement is embedded in the application and plays automatically when the program starts.

❗ GIF Path Setup ❗

If the application fails to load the GIF, it is likely due to a file path issue. The GIF is included in the zip file under "/Media/Pixel_Art_Car_Driving_A_Highway_At_Night.gif".

To resolve this, please do the following:
1) Open MainWindow.cpp
2) Locate this line: "movie = new QMovie("D:/Misc/College/Spring 2025/CS 136/SRC Project/Autonomous Vehicle Simulator/Media/Pixel_Art_Car_Driving_A_Highway_At_Night.gif");"
3) Update the path to match your system, such as: movie = new QMovie("YOUR/RELATIVE/PATH/TO/Media/Pixel_Art_Car_Driving_A_Highway_At_Night.gif");

Ensure that the Media folder is placed in the same directory as your .exe or project root, or adjust the path accordingly.

📜 License 📜

This project is intended for educational use only.
