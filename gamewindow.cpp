#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QMessageBox>
#include <string>
#include <iostream>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "deck.h"


/******************************************************************************
 *
 *  Constructor GameWindow: Class GameWindow
 *_____________________________________________________________________________
 *  Set up UI for the GameWindow
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    game window is set up with background, texts and combo box.
 ******************************************************************************/
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    //Background
    this->setFixedSize(1280, 720);
    QPixmap back(":/image/image/newBackground.jpg");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setPalette(palette);

    //Theme Combo box
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/blue_back.png"), "Blue");
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/purple_back.png"), "Purple");
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/green_back.png"), "Green");
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/yellow_back.png"), "Yellow");
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/red_back.png"), "Red");
    ui->themeCombo->addItem(QIcon(":/image/image/cardsPNG/gray_back.png"), "Gray");

    //Initalize
    gamesPlayed = wins = losses = draws = 0;
    playerName = "Player 1";
    theme = "blue";
}

/******************************************************************************
 *
 *  Destructor GameWindow: Class GameWindow
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
GameWindow::~GameWindow()
{
    delete ui;
}

/******************************************************************************
 *
 *  Mutator setPlayerName: Class GameWindow
 *_____________________________________________________________________________
 *  This method will update the playername attribute to the parameter name value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    playerName is updated
 ******************************************************************************/
void GameWindow::setPlayerName(std::string name) {
    playerName = name;
}

/******************************************************************************
 *
 *  Method startGame: Class GameWindow
 *_____________________________________________________________________________
 *  Start a new round of Blackjack. Shuffle cards, update player names and
 *      cardback theme, draw cards, and show scores
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    deck is shuffled and two cards are dealt to each player
 ******************************************************************************/
void GameWindow::startGame() {
    deck.returnCards();
    deck.shuffle();

    //Set player name
    ui->P1Name->setText(playerName.c_str());

    //Set card back color
    std::string color = ":/image/image/cardsPNG/";
    color += theme + "_back.png";
    QPixmap cardBack(color.c_str());
    ui->Deck->setPixmap(cardBack.scaled(WIDTH, HEIGHT));
    ui->Deck2->setPixmap(cardBack.scaled(WIDTH, HEIGHT));
    ui->Deck3->setPixmap(cardBack.scaled(WIDTH, HEIGHT));
    ui->Deck4->setPixmap(cardBack.scaled(WIDTH, HEIGHT));
    ui->Deck5->setPixmap(cardBack.scaled(WIDTH, HEIGHT));

    //Draw first card
    ui->P1Label1->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
    _P1.push_back(deck.drawCard());

    ui->compLabel1->setPixmap(cardBack.scaled(WIDTH, HEIGHT));
    _dealer.push_back(deck.drawCard());


    //Draw second card
    ui->P1Label2->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
    _P1.push_back(deck.drawCard());

    ui->compLabel2->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
    _dealer.push_back(deck.drawCard());

    //Show score
    ui->P1Score->setText(std::to_string(getP1Score()).c_str());
    int dealerScore = _dealer[1].getValue();
    if(dealerScore == 1) {
        ui->compScore->setText("11");
    } else {
        ui->compScore->setText(std::to_string(dealerScore).c_str());
    }
}

/******************************************************************************
 *
 *  Method getP1Score: Class GameWindow
 *_____________________________________________________________________________
 *  Returns the largest possible player's score that is <= 21
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Player's Blackjack score is returned
 ******************************************************************************/
int GameWindow::getP1Score() {
    int score = 0;
    bool hasAce = false;
    for(unsigned long i = 0; i < _P1.size(); i++) {
        score += _P1[i].getValue();
        if(_P1[i].isAce()) {
            hasAce = true;
        }
    }

    if(hasAce && score <= 11) {
        score += 10;
    }

    return score;
}

/******************************************************************************
 *
 *  Method getDealerScore: Class GameWindow
 *_____________________________________________________________________________
 *  Returns the largest possible dealer's score that is <= 21
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Dealer's Blackjack score is returned
 ******************************************************************************/
int GameWindow::getDealerScore() {
    int score = 0;
    bool hasAce = false;
    for(unsigned long i = 0; i < _dealer.size(); i++) {
        score += _dealer[i].getValue();
        if(_dealer[i].isAce()) {
            hasAce = true;
        }
    }

    if(hasAce && score <= 11) {
        score += 10;
    }

    return score;
}

/******************************************************************************
 *
 *  Method findImage: Class GameWindow
 *_____________________________________________________________________________
 *  Return the directory path of the card
 *  - returns const char*
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *   card image driectory is returned
 ******************************************************************************/
const char* GameWindow::findImage(const Card& card) {
    std::string directory = ":/image/image/cardsPNG/";
    switch(card.getRank()) {
        case 1:
            directory += "A";
            break;
        case 11:
            directory += "J";
            break;
        case 12:
            directory += "Q";
            break;
        case 13:
            directory += "K";
            break;
        default:
            directory += std::to_string(card.getRank());
            break;
    }
    switch(card.getSuit()) {
        case 1:
            directory += "S";
            break;
        case 2:
            directory += "H";
            break;
        case 3:
            directory += "C";
            break;
        default:
            directory += "D";
            break;
    }
    directory += ".png";

    return directory.c_str();
}

/******************************************************************************
 *
 *  Method updateWins: Class GameWindow
 *_____________________________________________________________________________
 *  Increase the number of wins displayed by 1
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    wins is incremented by one and displayed
 ******************************************************************************/
void GameWindow::updateWins() {
    wins++;
    updateGamesPlayed();
    ui->winsLabel->setText(std::to_string(wins).c_str());
}

/******************************************************************************
 *
 *  Method updateLosses: Class GameWindow
 *_____________________________________________________________________________
 *  Increase the number of losses displayed by 1
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    losses is incremented by one and displayed
 ******************************************************************************/
void GameWindow::updateLosses() {
    losses++;
    updateGamesPlayed();
    ui->lossesLabel->setText(std::to_string(losses).c_str());
}

/******************************************************************************
 *
 *  Method updaeDraws: Class GameWindow
 *_____________________________________________________________________________
 *  Increase the number of draws displayed by 1
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    draws is incremented by one and displayed
 ******************************************************************************/
void GameWindow::updateDraws() {
    draws++;
    updateGamesPlayed();
    ui->drawsLabel->setText(std::to_string(draws).c_str());
}

/******************************************************************************
 *
 *  Method updateGamesPlayed: Class GameWindow
 *_____________________________________________________________________________
 *  Increase the number of games played displayed by 1
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    gamesPlayed is incremented by one and displayed
 ******************************************************************************/
void GameWindow::updateGamesPlayed() {
    gamesPlayed++;
    ui->gameCountLabel->setText(std::to_string(gamesPlayed).c_str());
}

/******************************************************************************
 *
 *  Method on_hitButton_clicked: Class GameWindow
 *_____________________________________________________________________________
 *  Player draws a card and update the card image to their side.
 *      Update the score and display a lose message if getP1Score > 21
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    getP1Score <= 21
 *
 *  POST-CONDITIONS
 *    New card is added to player's side
 ******************************************************************************/
void GameWindow::on_hitButton_clicked()
{
    if(getP1Score() > 21) {
        return;
    }

    int cardsNum = _P1.size()+1;
    //Draw card
    switch(cardsNum) {
        case 3:
            ui->P1Label3->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
        case 4:
            ui->P1Label4->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
        case 5:
            ui->P1Label5->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
        case 6:
            ui->P1Label6->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
        case 7:
            ui->P1Label7->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
        default:
            ui->P1Label8->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
            break;
    }
    _P1.push_back(deck.drawCard());
    //Update P1 score
    ui->P1Score->setText(std::to_string(getP1Score()).c_str());

    if(getP1Score() > 21) {
        updateLosses();

        message = QMessageBox::critical(this, "You lose!", "Busted!!!\n\n\nRematch?",
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(message == QMessageBox::Yes) {
            on_rematchButton_clicked();
        }
    }
}

/******************************************************************************
 *
 *  Method on_standButton_clicked: Class GameWindow
 *_____________________________________________________________________________
 *  Reveal dealer's hidden card. Dealer draws according to player's cards
 *      Display win, lose, or draw message base on scores
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    getP1Score <= 21
 *
 *  POST-CONDITIONS
 *    Dealer's cards are drawn and reveal, match result displayed
 ******************************************************************************/
void GameWindow::on_standButton_clicked()
{
    int P1Score = getP1Score();
    if(P1Score > 21) {
        return;
    }

    //Reveal card
    ui->compLabel1->setPixmap(QPixmap(findImage(_dealer[0])).scaled(WIDTH, HEIGHT));

    //Update score
    int dealerScore = getDealerScore();
    ui->compScore->setText(std::to_string(dealerScore).c_str());

    //Draw cards
    int round = _dealer.size() + 1;

    while((dealerScore < P1Score && dealerScore < 21) || (dealerScore == P1Score && dealerScore <= 16)) {
        switch(round) {
            case 3:
                ui->compLabel3->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
            case 4:
                ui->compLabel4->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
            case 5:
                ui->compLabel5->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
            case 6:
                ui->compLabel6->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
            case 7:
                ui->compLabel7->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
            default:
                ui->compLabel8->setPixmap(QPixmap(findImage(deck.seeTop())).scaled(WIDTH, HEIGHT));
                break;
        }
        _dealer.push_back(deck.drawCard());
        dealerScore = getDealerScore();
        round++;

        //Update dealer score
        ui->compScore->setText(std::to_string(dealerScore).c_str());
    }

    //win/lose message
    if(P1Score == dealerScore) {
        updateDraws();
        message = QMessageBox::information(this, "Push!", "Draw -.-\n\n\nRematch?",
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    } else if(P1Score == 21) {
        updateWins();
        message = QMessageBox::warning(this, "You win!", "Blackjack!!!\n\n\nRematch?",
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    } else if(P1Score > dealerScore || dealerScore > 21) {
        updateWins();
        message = QMessageBox::warning(this, "You win!", "You win!!\n\n\nRematch?",
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    } else {
        updateLosses();
        message = QMessageBox::critical(this, "You lose!", "You lose! Better luck next time...\n\n\nRematch?",
                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

    if(message == QMessageBox::Yes) {
        on_rematchButton_clicked();
    }
}

/******************************************************************************
 *
 *  Method on_rematchButton_clicked: Class GameWindow
 *_____________________________________________________________________________
 *  Reset card images, clear player's cards and scores, and startGame()
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    A new game is started
 ******************************************************************************/
void GameWindow::on_rematchButton_clicked()
{
    ui->P1Label3->setText("3");
    ui->P1Label4->setText("4");
    ui->P1Label5->setText("5");
    ui->P1Label6->setText("6");
    ui->P1Label7->setText("7");
    ui->P1Label8->setText("8");

    ui->compLabel3->setText("3");
    ui->compLabel4->setText("4");
    ui->compLabel5->setText("5");
    ui->compLabel6->setText("6");
    ui->compLabel7->setText("7");
    ui->compLabel8->setText("8");

    _dealer.clear();
    _P1.clear();

    startGame();
}

/******************************************************************************
 *
 *  Method on_quitButton_clicked: Class GameWindow
 *_____________________________________________________________________________
 *  Quit the program
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    The window is closed
 ******************************************************************************/
void GameWindow::on_quitButton_clicked()
{
    close();
}

/******************************************************************************
 *
 *  Method on_themeCombo_currentTextChanged: Class GameWindow
 *_____________________________________________________________________________
 *  Update the theme variable based on the text change
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    The cardback color is updated
 ******************************************************************************/
void GameWindow::on_themeCombo_currentTextChanged(const QString &arg1)
{
    std::string color = arg1.toStdString();
    if(color == "Purple") {
        theme = "purple";
    } else if(color == "Green") {
        theme = "green";
    } else if(color == "Yellow") {
        theme = "yellow";
    } else if(color == "Red") {
        theme = "red";
    } else if(color == "Gray") {
        theme = "gray";
    } else {
        theme = "blue";
    }
}
