CONFIG -= qt

TEMPLATE = lib
DEFINES += CANINITPARSER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Visitor/abstractastnode.cpp \
    Visitor/binexprastnode.cpp \
    Visitor/caninitastnode.cpp \
    Visitor/caninitvisitor.cpp \
    Visitor/definitionastnode.cpp \
    Visitor/expressionastnode.cpp \
    Visitor/funccallastnode.cpp \
    Visitor/idastnode.cpp \
    Visitor/indexaccessastnode.cpp \
    Visitor/numberastnode.cpp \
    Visitor/structaccessastnode.cpp \
    binexprnode.cpp \
    caninitlexer.cpp \
    caninitnode.cpp \
    caninitparser.cpp \
    definitionnode.cpp \
    expressionnode.cpp \
    funccallnode.cpp \
    idnode.cpp \
    indexaccessnode.cpp \
    numbernode.cpp \
    parsenode.cpp \
    structaccessnode.cpp

HEADERS += \
    CanInitParser_global.h \
    Visitor/abstractastnode.h \
    Visitor/binexprastnode.h \
    Visitor/caninitastnode.h \
    Visitor/caninitvisitor.h \
    Visitor/definitionastnode.h \
    Visitor/expressionastnode.h \
    Visitor/funccallastnode.h \
    Visitor/idastnode.h \
    Visitor/indexaccessastnode.h \
    Visitor/numberastnode.h \
    Visitor/structaccessastnode.h \
    binexprnode.h \
    caninitlexer.h \
    caninitnode.h \
    caninitparser.h \
    definitionnode.h \
    expressionnode.h \
    funccallnode.h \
    idnode.h \
    indexaccessnode.h \
    numbernode.h \
    parsenode.h \
    structaccessnode.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
