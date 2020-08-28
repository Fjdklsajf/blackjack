/******************************************************************************
 *  AUTHOR          : Zhongming Su
 *  DATE CREATED    : August 18, 2020
 ******************************************************************************/
#include <cstdlib>
#include <ctime>
#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "gamewindow.h"
#include "deck.h"
/******************************************************************************
 *
 * Blackjack
 *_____________________________________________________________________________
 * A Blackjack simulation done with Qt UI
 *_____________________________________________________________________________
 * Input:
 *  General input from mouse and keyboard
 *
 * Output:
 *  MainWindow: Welcoming page of Blackjack
 *  GameWindow: Game simulation page
 ******************************************************************************/

int main(int argc, char *argv[]) {

    srand(time(NULL));

    std::cout << "/********************************************************\n";
    std::cout << " Programmed by: Zhongming Su\n";
    std::cout << " Program title: Blackjack\n";
    std::cout << " Date created : August 18, 2020\n";
    std::cout << " ********************************************************/\n\n";

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
