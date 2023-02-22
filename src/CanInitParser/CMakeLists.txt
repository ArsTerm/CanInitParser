include(CompileOptions)

set(target_name CanInitParser)

add_library(${target_name} SHARED)
target_compile_definitions(${target_name} PRIVATE CANINITPARSER_LIBRARY)
target_sources(${target_name} PRIVATE
         caninitlexer.h
         caninitlexer.cpp
         CanInitParser_global.h
         Parser/caninitnode.cpp
         Parser/caninitnode.h
         Parser/caninitparser.cpp
         Parser/caninitparser.h
         Parser/definitionnode.cpp
         Parser/definitionnode.h
         Parser/funccallnode.cpp
         Parser/funccallnode.h
         Parser/funcdefnode.cpp
         Parser/funcdefnode.h
         Parser/idnode.cpp
         Parser/idnode.h
         Parser/indexaccessnode.cpp
         Parser/indexaccessnode.h
         Parser/numbernode.cpp
         Parser/numbernode.h
         Parser/parsenode.cpp
         Parser/parsenode.h
         Parser/structaccessnode.cpp
         Parser/structaccessnode.h
         Parser/binexprnode.cpp
         Parser/binexprnode.h
         Visitor/caninitvisitor.cpp
         Visitor/caninitvisitor.h
         Visitor/abstractastnode.h
         Visitor/abstractastnode.cpp
         Visitor/value.h
         Visitor/value.cpp)
