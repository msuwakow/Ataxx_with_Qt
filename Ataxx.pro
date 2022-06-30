QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ai.cpp \
    chessboard.cpp \
    chooser1.cpp \
    chooser2.cpp \
    file.cpp \
    game.cpp \
    gamestate.cpp \
    level.cpp \
    login.cpp \
    main.cpp \
    mainmenu.cpp \
    nopainter.cpp \
    pos.cpp \
    signup.cpp \
    widget.cpp

HEADERS += \
    ai.h \
    chessboard.h \
    chooser1.h \
    chooser2.h \
    file.h \
    game.h \
    gamestate.h \
    level.h \
    login.h \
    mainmenu.h \
    nopainter.h \
    pos.h \
    signup.h \
    widget.h

FORMS += \
    chooser1.ui \
    chooser2.ui \
    login.ui \
    mainmenu.ui \
    nopainter.ui \
    signup.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myImages.qrc
