#include "coarse.h"

#include <strstream>

Coarse::Coarse() : Coarse(0) { }
Coarse::Coarse(int v) : Parameter(std::string_view("Coarse"), -24, 24, 0, v) { }

std::string Coarse::toString() const {
    std::ostrstream result;
    result << getName() << " = " << getValue();
    return result.str();
}
