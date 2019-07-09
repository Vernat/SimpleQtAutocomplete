#-------------------------------------------------
#
# Project created by QtCreator 2019-07-06T12:12:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleQtAutocomplete
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        completer.cpp \
        completion_window.cpp \
        dictionary_item_widget.cpp \
        fake_dictionary_provider.cpp \
        main.cpp \
        simple_matcher.cpp \
        widget.cpp

HEADERS += \
        abstract_completer.h \
        abstract_completion_window.h \
        abstract_dictionary_provider.h \
        abstract_matcher.h \
        completer.h \
        completion_window.h \
        dictionary_item.h \
        dictionary_item_widget.h \
        fake_dictionary_provider.h \
        simple_matcher.h \
        widget.h

FORMS += \
        completition.ui \
        dictionary_item_widget.ui \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
