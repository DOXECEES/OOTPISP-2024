#include <iostream>
#include <memory> 
#include "ErrorCollection.h"
#include "Errors.h"

int main() {
    ErrorCollection errors(10);
    try {
        errors[0] = std::make_unique<InvalidPointer>(nullptr);
        errors[1] = std::make_unique<ListError>();
        errors[2] = std::make_unique<InvalidIndex>(5);
        errors[3] = std::make_unique<ListOverflow>();

        for (int i = 0; i < 4; ++i) {
            std::cout << "Error " << i << ": ";
            errors[i]->Print();
        }
        if (*errors[0] == *errors[1]) {
            std::cout << "Error 0 and Error 1 are equal." << std::endl;
        }
        else {
            std::cout << "Error 0 and Error 1 are not equal." << std::endl;
        }

        if (!(*errors[2] == *errors[3])) {
            std::cout << "Error 2 and Error 3 are not equal." << std::endl;
        }
        else {
            std::cout << "Error 2 and Error 3 are equal." << std::endl;
        }
    }
    catch (const BaseError& e) {
        std::cerr << "Caught BaseError: ";
        e.Print();
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
