CONFIG += \
        c++11 \
        stl_on
QT     += \
        widgets designer \
        core gui
SOURCES += \
    EnterPoint.cpp \
    backteria.cpp \
    food.cpp \
    hunter.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    backteria.h \
    food.h \
    hunter.h \
    mainwindow.h

RESOURCES += \
    res.qrc
