include(CompileOptions)

set(target_name CanInitParser)

add_library(${target_name} SHARED)
target_compile_definitions(${target_name} PRIVATE CANINITPARSER_LIBRARY)
target_sources(
  ${target_name}
  PRIVATE caninitlexer.h
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
          Parser/commentnode.h
          Parser/commentnode.cpp
          Visitor/caninitvisitor.cpp
          Visitor/caninitvisitor.h
          Visitor/types/value.h
          Visitor/types/value.cpp
          Visitor/types/alias.h
          Visitor/types/alias.cpp
          Visitor/types/message.h
          Visitor/types/message.cpp
          Visitor/nodes/astnode.h
          Visitor/nodes/astnode.cpp
          Visitor/nodes/binexprastnode.h
          Visitor/nodes/binexprastnode.cpp
          Visitor/nodes/caninitastnode.h
          Visitor/nodes/caninitastnode.cpp
          Visitor/nodes/definitionastnode.h
          Visitor/nodes/definitionastnode.cpp
          Visitor/nodes/funccallastnode.h
          Visitor/nodes/funccallastnode.cpp
          Visitor/nodes/funcdefastnode.h
          Visitor/nodes/funcdefastnode.cpp
          Visitor/nodes/idastnode.h
          Visitor/nodes/idastnode.cpp
          Visitor/nodes/numberastnode.h
          Visitor/nodes/numberastnode.cpp
          Visitor/nodes/structaccessastnode.h
          Visitor/nodes/structaccessastnode.cpp
          Visitor/nodes/indexaccessastnode.h
          Visitor/nodes/indexaccessastnode.cpp
          Visitor/expr.h
          Visitor/expr.cpp
          Visitor/types/aliasmessage.cpp
          Visitor/types/aliasmessage.h
          Visitor/types/id.h
          Visitor/types/id.cpp
          Context/context.h
          Context/context.cpp
          Context/types/bbdata.h
          Context/types/canmes.h
          Context/types/valuesarray.h
          Context/types/valuesarray.cpp
      )

set_compile_options(${target_name})
