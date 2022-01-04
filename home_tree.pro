QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demo_add.cpp \
    demo_change.cpp \
    demo_del.cpp \
    demo_search.cpp \
    demo_view.cpp \
    genealogy.cpp \
    main.cpp \
    mainwindow.cpp \
    person_version.cpp \
    tree_find.cpp

HEADERS += \
    demo_add.h \
    demo_change.h \
    demo_del.h \
    demo_search.h \
    demo_view.h \
    genealogy.h \
    mainwindow.h \
    person.h \
    person_version.h \
    tree_find.h

FORMS += \
    demo_add.ui \
    demo_change.ui \
    demo_del.ui \
    demo_search.ui \
    demo_view.ui \
    mainwindow.ui \
    person_version.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
