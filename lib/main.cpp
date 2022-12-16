#include <iostream>
#include <vector>
#include "PasswordValidator.h"


#define DEFAULT_MAX_LEN 45
#define DEFAULT_MIN_LEN 8

std::vector<int> processArgs(int argc, char* argv[]) {
    std::vector<int> rv;

    for(int i = 0;i < argc;i++) {
        std::cout << "argv[" << i << "]: " << argv[i] << " ";
    }
    std::cout << std::endl;

    // std::cout << "End: " << std::end(argv) << std::endl;

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

// Usage: pwvalidator -min number -max number
int main(int argc, char* argv[]) {

    std::vector<char *> args(argv, argv + argc);

    for (std::vector<char *>::iterator i = args.begin(); i != args.end();++i) {
        std::cout << "i = " << *i << "; ";
    }
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
