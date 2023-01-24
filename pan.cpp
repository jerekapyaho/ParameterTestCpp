#include "pan.h"

#include <strstream>

Pan::Pan() : Pan(0) { }
Pan::Pan(int v) : Parameter(std::string_view("Pan"), -7, 7, 0, v, true) { }

std::string Pan::toString() const {
    std::ostrstream result;
    result << getName() << " = ";

    int v = getValue();
    result << "L|-------0-------|R";
    result << " " << v;

    return result.str();
}
