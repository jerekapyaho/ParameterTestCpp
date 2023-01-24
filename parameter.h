#pragma once

#include <string>
#include <string_view>

// Abstract base class for a parameter
class Parameter {
public:
    explicit Parameter(std::string_view n, int min, int max, int d, int v, bool c = false);
    virtual ~Parameter() = default;  // compiler generates virtual constructor

    // Read-only properties; only getters provided
    std::string getName() const;
    int getDefaultValue() const;
    int getMinimumValue() const;
    int getMaximumValue() const;

    int getValue() const;
    void setValue(int newValue);
    bool isClamping() const;

    // Pure virtual function to make this an abstract base class
    // (so that you can't make instances of Parameter, only subclasses)
    virtual std::string toString() const = 0;

    void setRandomValue();

private:
    std::string name;
    int defaultValue;
    int minimumValue;
    int maximumValue;
    int value;
    bool clamping;
};
