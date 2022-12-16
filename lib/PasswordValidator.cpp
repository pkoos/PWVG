#include "PasswordValidator.h"
#include <iostream>
#include <string>

PasswordValidator::PasswordValidator(int minLength, int maxLength) {
    this->minLength = minLength;
    this->maxLength = maxLength;
}

bool PasswordValidator::validate() {
    std::string password;
    std::cout << "Please enter a password to validate:";
    std::cin >> password;
    int passwordLength = password.length();
    if (isValidLength(passwordLength)) {
        std::cout << "The password's length is valid. ";
        return true;
    }
    else {
        std::cout << "Invalid password length. Password must be between " << minLength << " and " << maxLength << " characters long. ";
        return false;
    }
}

bool PasswordValidator::isValidLength(int passwordLength) {
    return passwordLength <= maxLength && passwordLength >= minLength;
}
