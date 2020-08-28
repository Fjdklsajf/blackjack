#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <vector>
#include <string>
#include "deck.h"
#include "card.h"

namespace Ui {class GameWindow;}

class GameWindow : public QDialog{

    Q_OBJECT

  public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    /**************
     ** MUTATORS **
     **************/
    void setPlayerName(std::string name);

    /***********************************
     ** MODIFICATION MEMBER FUNCTIONS **
     ***********************************/
    void startGame();
    int getP1Score();
    int getDealerScore();
    const char* findImage(const Card& card);
    void updateWins();
    void updateLosses();
    void updateDraws();
    void updateGamesPlayed();

    /*********************
     ** SIGNALS & SLOTS **
     *********************/
  private slots:
    void on_hitButton_clicked();
    void on_rematchButton_clicked();
    void on_standButton_clicked();
    void on_quitButton_clicked();
    void on_themeCombo_currentTextChanged(const QString &arg1);

  private:
    const int WIDTH = 150, HEIGHT = 210;
    int gamesPlayed, wins, losses, draws;
    std::string playerName, theme;
    std::vector<Card> _dealer, _P1;
    Ui::GameWindow *ui;
    Deck deck;
    QMessageBox::StandardButton message;
};
/******************************************************************************
 *  GameWindow Class
 *    Game window of Blackjack, the simulation page
 ******************************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/******************************************************************************
 *  explicit GameWindow(QWidget *parent = nullptr)()
 *    Constructor; Set up UI for the GameWindow
 *    Parameters: Qwidget *
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  ~GameWindow()
 *    Destructor; Delete the UI created
 *    Parameters: none
 *    Return: void
 ******************************************************************************/


/**************
 ** MUTATORS **
 **************/

/******************************************************************************
 *  void setPlayerName(std::string name);
 *
 *    Mutator; This method will update the playername attribute to the parameter
 *      name value
 * ----------------------------------------------------------------------------
 *    Parameters: _types_
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/***********************************
 ** MODIFICATION MEMBER FUNCTIONS **
 ***********************************/

/******************************************************************************
 *  void startGame();
 *
 *    Start a new round of Blackjack. Shuffle cards, update player names and
 *      cardback theme, draw cards, and show scores
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  int getP1Score();
 *
 *    Returns the largest possible player's score that is <= 21
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  int getDealerScore();
 *
 *    Returns the largest possible dealer's score that is <= 21
 * ----------------------------------------------------------------------------
 *    Parameters:
 * ----------------------------------------------------------------------------
 *    Return: int
 ******************************************************************************/

/******************************************************************************
 *  const char* findImage(const Card& card);
 *
 *    Return the directory path of the card
 * ----------------------------------------------------------------------------
 *    Parameters: const Card&
 * ----------------------------------------------------------------------------
 *    Return: const char*
 ******************************************************************************/

/******************************************************************************
 *  void updateWins();
 *
 *    Increase the number of wins displayed by 1
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void updateLosses();
 *
 *    Increase the number of losses displayed by 1
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void updateDraws();
 *
 *    Increase the number of draws displayed by 1
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void updateGamesPlayed();
 *
 *    Increase the number of games played displayed by 1
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/


/*********************
 ** SIGNALS & SLOTS **
 *********************/

/******************************************************************************
 *  void on_hitButton_clicked() const;
 *
 *    Player draws a card and update the card image to their side.
 *      Update the score and display a lose message if getP1Score > 21
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void on_standButton_clicked() const;
 *
 *    Reveal dealer's hidden card. Dealer draws according to player's cards
 *      Display win, lose, or draw message base on scores
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void on_rematchButton_clicked() const;
 *
 *    Reset card images, clear player's cards and scores, and startGame()
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void on_quitButton_clicked() const;
 *
 *    Quit the program
 * ----------------------------------------------------------------------------
 *    Parameters: none
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

/******************************************************************************
 *  void on_themeCombo_currentTextChanged(const QString &arg1);
 *
 *    Update the theme variable based on the text change
 * ----------------------------------------------------------------------------
 *    Parameters: const QString&
 * ----------------------------------------------------------------------------
 *    Return: void
 ******************************************************************************/

#endif // GAMEWINDOW_H
