#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMovie>
#include "Logger.h"
#include "Vehicle.h"
#include "DecisionMaker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Main Application Window That Manages the UI and Simulation Logic
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSimulateClicked();  // Handles Simultation Button Click
    void onShowLogClicked();   // Handles Show Log Button Click
    void onResetClicked();     // Handles Reset Button Click

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* videoWidget;
    QMovie *movie;
    Logger logger;
    Vehicle vehicle;
    DecisionMaker decisionMaker;
};

#endif