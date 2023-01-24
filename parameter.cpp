#include <iostream>
#include <string>
#include <string_view>
#include <strstream>

#include "parameter.h"
#include "randomizer.h"

Parameter::Parameter(std::string_view n, int min, int max, int d, int v, bool c) :
    name(n), minimumValue(min), maximumValue(max), defaultValue(d), value(v), clamping(c)
{

}

std::string Parameter::getName() const { return name; }
int Parameter::getDefaultValue() const { return defaultValue; }
int Parameter::getMinimumValue() const { return minimumValue; }
int Parameter::getMaximumValue() const { return maximumValue; }
int Parameter::getValue() const { return value; }

void Parameter::setValue(int newValue) {
    if (newValue >= minimumValue && newValue <= maximumValue) {
        value = newValue;
    }
    else {
        if (clamping) {
            if (newValue < minimumValue) {
                value = minimumValue;
            }
            else if (newValue > maximumValue) {
                value = maximumValue;
            }
            else {
                value = newValue;
            }
        }
        else {
            std::ostrstream message;
            message
                << "value must be between "
                << minimumValue << " and " << maximumValue
                << " (was " << newValue << ")";
            throw std::invalid_argument(message.str());
        }
    }
}

bool Parameter::isClamping() const { return clamping; }

// There is no implementation of the `toString` method,
// because it is pure virtual.

void Parameter::setRandomValue() {
    int newValue = ParameterRandomizer::instance().
        getRandomValue(*this);
    setValue(newValue);
}
