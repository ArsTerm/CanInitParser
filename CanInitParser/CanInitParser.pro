CONFIG -= qt

TEMPLATE = lib
DEFINES += CANINITPARSER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Visitor/caninitvisitor.cpp \
    Parser/binexprnode.cpp \
    caninitlexer.cpp \
    Parser/caninitnode.cpp \
    Parser/caninitparser.cpp \
    Parser/definitionnode.cpp \
    Parser/funccallnode.cpp \
    Parser/funcdefnode.cpp \
    Parser/idnode.cpp \
    Parser/indexaccessnode.cpp \
    Parser/numbernode.cpp \
    Parser/parsenode.cpp \
    Parser/structaccessnode.cpp

HEADERS += \
    CanInitParser_global.h \
    Visitor/caninitvisitor.h \
    Parser/binexprnode.h \
    caninitlexer.h \
    Parser/caninitnode.h \
    Parser/caninitparser.h \
    Parser/definitionnode.h \
    Parser/funccallnode.h \
    Parser/funcdefnode.h \
    Parser/idnode.h \
    Parser/indexaccessnode.h \
    Parser/numbernode.h \
    Parser/parsenode.h \
    Parser/structaccessnode.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
