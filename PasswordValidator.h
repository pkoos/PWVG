#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

class PasswordValidator {

    public:
        PasswordValidator(int minLength, int maxLength);
        int minLength;
        int maxLength;
        bool validate();
        bool isValidLength(int passwordLength);
};

#endif