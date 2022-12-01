#include <iostream>
#include <vector>
#include "PasswordValidator.h"


#define DEFAULT_MAX_LEN 45
#define DEFAULT_MIN_LEN 8

std::vector<int> processArgs(int argc, char* argv[]) {
    std::vector<int> rv;
    
    switch (argc) {
        case 2:
            rv.push_back(std::stoi(argv[1]));
            rv.push_back(DEFAULT_MAX_LEN);
        break;
        case 3:
            rv.push_back(std::stoi(argv[1]));
            rv.push_back(std::stoi(argv[2]));
        break;
        default:
            rv.push_back(DEFAULT_MIN_LEN);
            rv.push_back(DEFAULT_MAX_LEN);
    }

    return rv;
}

int main(int argc, char* argv[]) {
    std::vector<int> passwordLengthBounds = processArgs(argc, argv);
    PasswordValidator validator = PasswordValidator(passwordLengthBounds.at(0), passwordLengthBounds.at(1));

    if (validator.validate()) {
        std::cout << "Password is valid." << std::endl;
    }
    else {
        std::cout << "Invalid password." << std::endl;
    }

    return 0;
}
