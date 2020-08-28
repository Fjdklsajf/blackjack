#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{

    Q_OBJECT

  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*********************
     ** SIGNALS & SLOTS **
     *********************/
  private slots:
    void on_playButton_clicked();
    void on_exitButton_clicked();

  private:
    Ui::MainWindow *ui;
    GameWindow *gameWindow;
};
/******************************************************************************
 *  MainWindow Class
 *    Main window of the simulation. Welcoming page to the game of Blackjack
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  MainWindow(QWidget *parent = nullptr)
 *    Constructor; Set up UI for the MainWindow
 *    Parameters: QWidget *
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  ~MainWindow()
 *    Destructor; Delete the UI created
 *    Parameters: none
 *    Return: void
 ******************************************************************************/


/*********************
 ** SIGNALS & SLOTS **
 *********************/

/******************************************************************************
 *  void on_playButton_clicked() const;
 *
 *    Switch to the GameWindow UI
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void on_exitButton_clicked() const;
 *
 *    Quits the program
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

#endif // MAINWINDOW_H
