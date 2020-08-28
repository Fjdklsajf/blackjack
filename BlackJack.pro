QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    deck.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    card.h \
    deck.h \
    gamewindow.h \
    mainwindow.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    background.jpg \
    cardsPNG/10C.png \
    cardsPNG/10D.png \
    cardsPNG/10H.png \
    cardsPNG/10S.png \
    cardsPNG/2C.png \
    cardsPNG/2D.png \
    cardsPNG/2H.png \
    cardsPNG/2S.png \
    cardsPNG/3C.png \
    cardsPNG/3D.png \
    cardsPNG/3H.png \
    cardsPNG/3S.png \
    cardsPNG/4C.png \
    cardsPNG/4D.png \
    cardsPNG/4H.png \
    cardsPNG/4S.png \
    cardsPNG/5C.png \
    cardsPNG/5D.png \
    cardsPNG/5H.png \
    cardsPNG/5S.png \
    cardsPNG/6C.png \
    cardsPNG/6D.png \
    cardsPNG/6H.png \
    cardsPNG/6S.png \
    cardsPNG/7C.png \
    cardsPNG/7D.png \
    cardsPNG/7H.png \
    cardsPNG/7S.png \
    cardsPNG/8C.png \
    cardsPNG/8D.png \
    cardsPNG/8H.png \
    cardsPNG/8S.png \
    cardsPNG/9C.png \
    cardsPNG/9D.png \
    cardsPNG/9H.png \
    cardsPNG/9S.png \
    cardsPNG/AC.png \
    cardsPNG/AD.png \
    cardsPNG/AH.png \
    cardsPNG/AS.png \
    cardsPNG/JC.png \
    cardsPNG/JD.png \
    cardsPNG/JH.png \
    cardsPNG/JS.png \
    cardsPNG/KC.png \
    cardsPNG/KD.png \
    cardsPNG/KH.png \
    cardsPNG/KS.png \
    cardsPNG/QC.png \
    cardsPNG/QD.png \
    cardsPNG/QH.png \
    cardsPNG/QS.png \
    cardsPNG/aces.png \
    cardsPNG/back_cards-07.png \
    cardsPNG/blue_back.png \
    cardsPNG/gray_back.png \
    cardsPNG/green_back.png \
    cardsPNG/honor_clubs.png \
    cardsPNG/honor_diamond.png \
    cardsPNG/honor_heart-14.png \
    cardsPNG/honors_spade-14.png \
    cardsPNG/purple_back.png \
    cardsPNG/red_back.png \
    cardsPNG/yellow_back.png \
    gameBackground.jpg

RESOURCES += \
    resource.qrc
