#include "password.hpp"
#include <iostream>
#include <string>


Password::Password(std::string password, bool is_encrypted) : _raw_value(password), _is_encrypted(is_encrypted) {
    if (!is_encrypted) {
        encrypt();  
    } else {
        _encrypted_value = password;  
    }
}

void Password::encrypt() {
    _encrypted_value.clear();
    for (char c : _raw_value) {
        _encrypted_value += c + 3;  
    }
    _is_encrypted = true;  
}



std::string Password::str() {
    return _encrypted_value;
}


bool Password::operator==(const std::string& str) const {
    return str == _encrypted_value;
}


bool Password::operator==(const Password& other) const {
    return _encrypted_value == other._encrypted_value;
}


std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value; 
    return os;
}
