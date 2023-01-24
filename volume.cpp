#include <strstream>

#include "parameter.h"
#include "volume.h"


Volume::Volume() : Volume(0) { }
Volume::Volume(int v) : Parameter(std::string_view("Volume"), 0, 100, 0, v) { }

std::string Volume::toString() const {
    std::ostrstream result;
    result << getName() << ": " << getValue() << "/" << getMaximumValue();
    return result.str();
}
