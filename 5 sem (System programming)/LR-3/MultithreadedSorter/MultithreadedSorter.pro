QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entities/testclass.cpp \
    Entities/thread.cpp \
    Service/TableServices/testclasstable.cpp \
    Service/TableServices/threadtable.cpp \
    Service/mergesortservice.cpp \
    Service/threadservice.cpp \
    main.cpp \
    indexwindow.cpp

HEADERS += \
    Entities/testclass.h \
    Entities/thread.h \
    Service/TableServices/testclasstable.h \
    Service/TableServices/threadtable.h \
    Service/mergesortservice.h \
    Service/threadservice.h \
    indexwindow.h

FORMS += \
    indexwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourses/Icons.qrc
