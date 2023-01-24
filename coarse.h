#pragma once

#include "parameter.h"

class Coarse: public Parameter {
public:
    Coarse();
    Coarse(int value);
    virtual ~Coarse() = default;

    std::string toString() const override;
};
