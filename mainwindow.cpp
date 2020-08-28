#include <QPixmap>
#include <QPalette>
#include <string>
#include <QBrush>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************
 *
 *  Constructor MainWindow: Class MainWindow
 *_____________________________________________________________________________
 *  Set up UI for the MainWindow
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    MainWindow UI is set up, background image is added
 ******************************************************************************/
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    //Set background
    this->setFixedSize(720, 450);
    QPixmap back(":/image/image/background.jpg");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setPalette(palette);
}

/******************************************************************************
 *
 *  Constructor MainWindow: Class MainWindow
 *_____________________________________________________________________________
 *  Delete the UI created
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    ui is deleted
 ******************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/******************************************************************************
 *
 *  Method on_playButton_clicked: Class MainWindow
 *_____________________________________________________________________________
 *  MainWindow is hidden, gameWindow is brought up
 *      update player name and starts the game
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Switched to the GameWindow UI
 ******************************************************************************/
void MainWindow::on_playButton_clicked()
{
    //Switch window
    hide();
    gameWindow = new GameWindow(this);
    gameWindow->show();

    //Set name;
    std::string name = ui->lineEdit->text().toStdString();
    gameWindow->setPlayerName(name);

    gameWindow->startGame();
}

/******************************************************************************
 *
 *  Method on_exitButton_clicked: Class MainWindow
 *_____________________________________________________________________________
 *  Quits the program
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Simulation is ended
 ******************************************************************************/
void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}
