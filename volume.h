#pragma once

#include "parameter.h"

class Volume: public Parameter {
public:
    Volume();
    Volume(int value);
    virtual ~Volume() = default;

    std::string toString() const override;
};
