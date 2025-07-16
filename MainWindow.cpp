#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDateTime>
#include <QMovie>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>

using namespace std;

// Initializes the Main Window and Sets Up UI Components
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), decisionMaker(logger) {
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    // Connects Buttons to Their Respective Slots
    connect(ui->buttonSimulate, &QPushButton::clicked, this, &MainWindow::onSimulateClicked);
    ui->buttonSimulate->setFocus();
    connect(ui->buttonLog, &QPushButton::clicked, this, &MainWindow::onShowLogClicked);
    connect(ui->buttonReset, &QPushButton::clicked, this, &MainWindow::onResetClicked);

    // Loads and Starts Animated Driving GIF
    movie = new QMovie("D:/Misc/College/Spring 2025/CS 136/SRC Project/Autonomous Vehicle Simulator/Media/Pixel_Art_Car_Driving_A_Highway_At_Night.gif");
    // Source: OrkhanTheStargazer. "Pixel Art Car Driving a Highway at Night." Motion Array, motionarray.com/stock-video/pixel-art-car-driving-a-highway-at-night-2082701/.

    movie->setScaledSize(ui->labelVideo->size());
    movie->setCacheMode(QMovie::CacheAll);
    movie->setSpeed(100);
    
    ui->labelVideo->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Handles Simulation Logic and Displays Results
void MainWindow::onSimulateClicked() {
    bool pedestrian = ui->checkBoxPedestrian->isChecked();
    bool obstacle = ui->checkBoxObstacle->isChecked();
    QString roadType = ui->comboBoxRoadType->currentText();
    QString weather = ui->comboBoxWeather->currentText();
    int speedLimit = ui->spinBoxSpeed->value();

    // Evaluates Driving Conditions Using the DecisionMaker Class
    decisionMaker.evaluateConditions(
        pedestrian,
        obstacle,
        roadType.toStdString(),
        speedLimit,
        weather.toStdString(),
        vehicle
    );

    // Retrieve the Final Decision and Rationale
    QString decision = QString::fromStdString(vehicle.getStatus());
    QString rationale;

    // Determine the Rationale Based on Input
    if (pedestrian) {
        rationale = "Pedestrian detected. Prioritizing human life.";
    } else if (obstacle) {
        rationale = "Obstacle ahead. Minimizing potential harm.";
    } else if (weather == "Fog" || weather == "Rain") {
        rationale = "Poor visibility. Slowing down to ensure safety.";
    } else {
        rationale = "No immediate threats. Proceeding cautiously.";
    }

    // Output to the Log
    ui->textBrowserLog->append("🚦 Decision Made: " + QString::fromStdString(vehicle.getStatus()));
    ui->textBrowserLog->append("☑️ Simulation Run at " + ui->dateTimeEdit->dateTime().toString("MM/dd/yyyy hh:mm AP"));
    ui->textBrowserLog->append("📝 Rationale: " + rationale);
    ui->textBrowserLog->append("");  // Extra Space
    ui->textBrowserLog->append("----------------------------");  // Visual Separator
    ui->textBrowserLog->append("");  // Extra Space
}

// Displays Previously Logged Decisions
void MainWindow::onShowLogClicked() {
    ui->textBrowserLog->clear();
    for (const string &entry : logger.getLogs()) {
        ui->textBrowserLog->append(QString::fromStdString(entry));
        ui->textBrowserLog->append("----------------------------");  // Visual Separator
        ui->textBrowserLog->append("");  // Extra Space
    }
}

// Resets All Input Fields and Clears the Log
void MainWindow::onResetClicked() {
    ui->textBrowserLog->clear();

    ui->checkBoxPedestrian->setChecked(false);
    ui->checkBoxObstacle->setChecked(false);
    ui->comboBoxRoadType->setCurrentIndex(0);
    ui->comboBoxWeather->setCurrentIndex(0);
    ui->spinBoxSpeed->setValue(0);
    
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setReadOnly(true);
    ui->dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->dateTimeEdit->setFocusPolicy(Qt::NoFocus);
}