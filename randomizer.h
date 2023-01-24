#pragma once

#include <random>
#include <limits>  // for limits of integer types

#include "parameter.h"

// Singleton class to provide a random value for a parameter.
// See Marius Bancila, "Modern C++ Programming Cookbook, 2nd Ed",
// chapter "Implementing a thread-safe singleton" for the design pattern,
// and Paul Deitel & Harvey Deitel, "C++20 for Programmers", chapter 5,
// for the random number generation.

class ParameterRandomizer {
private:
    std::random_device device{};
    std::mt19937 engine{ device() };
    std::uniform_int_distribution<int> distribution{INT_MIN, INT_MAX};

    ParameterRandomizer() { }

public:
    ParameterRandomizer(ParameterRandomizer const &) = delete;
    ParameterRandomizer& operator=(ParameterRandomizer const &) = delete;

    static ParameterRandomizer& instance() {
        static ParameterRandomizer single;
        return single;
    }

    int getRandomValue(const Parameter& parameter) {
        // Set the parameters of the uniform distribution
        // according to the `parameter` max and min values
        distribution.param(std::uniform_int_distribution<int>::param_type(
            parameter.getMinimumValue(),
            parameter.getMaximumValue()
        ));
        return distribution(engine);
    }
};
