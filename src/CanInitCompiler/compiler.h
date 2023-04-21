#pragma once

#include "caninitcompiler_global.h"
#include <Visitor/types/id.h>
#include <optional>
#include <string>

namespace cicompiler {

class CANINITCOMPILER_EXPORT Compiler {
public:
    int compile(std::string_view inFile, std::string_view outFile);
    void parseSet(const ciparser::Id::Set& s, std::string_view outFile);

private:
    virtual std::optional<std::pair<void*, size_t>>
    readFile(std::string_view file);
    virtual void freeFile(void* data);
};

}
