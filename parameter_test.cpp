#include <iostream>
#include <vector>
#include <memory>

#include "parameter.h"
#include "volume.h"
#include "coarse.h"
#include "pan.h"

int main() {
    std::vector<std::unique_ptr<Parameter>> parameters;

    Volume volume(25);
    Coarse coarse(-6);
    Pan pan(-2);

    // Need to use a smart pointer when adding subclass instances
    // to the vector, otherwise "slicing" occurs.
    parameters.push_back(std::make_unique<Volume>(volume));
    parameters.push_back(std::make_unique<Coarse>(coarse));
    parameters.push_back(std::make_unique<Pan>(pan));

    // We don't care about the actual type, just about the fact
    // that they are all Parameter subclasses. This is LSP or
    // "Liskov Substitution Principle", or "behavioral subtyping".
    for (const auto& parameter : parameters) {
        std::cout
            << "name = " << parameter->getName()
            << " [" << parameter->getMinimumValue()
            << "..." << parameter->getMaximumValue()
            << "] default = " << parameter->getDefaultValue()
            << " current = " << parameter->getValue()
            << std::endl;

        // Every subclass of Parameter overrides the toString() method,
        // so the result is different for every instance.
        std::cout << parameter->toString() << std::endl;
    }

    volume.setValue(50);
    std::cout << "volume = " << volume.getValue() << std::endl;

    // Pan is clamping by default, so setting it to a value
    // outside its range should be fine:
    std::cout << "setting pan to " << -40 << "..." << std::endl;
    pan.setValue(-40);
    std::cout << "pan is now " << pan.getValue() << std::endl;  // should be clamped to -7

    // Coarse is not clamping, so this will throw an exception:
    coarse.setValue(1000);

    // Trying to instantiate an abstract class; will not compile
    //Parameter p = new Parameter("foo", 10, 20, 10, 0, true);

    return 0;
}
