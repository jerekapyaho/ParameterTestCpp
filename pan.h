#pragma once

#include "parameter.h"

class Pan: public Parameter {
public:
    Pan();
    Pan(int value);
    virtual ~Pan() = default;

    std::string toString() const override;
};
