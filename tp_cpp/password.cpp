#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted) 
    // Pas besoin de garder le mot de passe en clair en mémoire
    : _raw_value(password) {
    if (is_encrypted) {
        _encrypted_value = password;
    } else {
        encrypt(password);
    }
}

void Password::encrypt(const std::string &password) {
    _encrypted_value.clear();
    for (char c : password) {
        _encrypted_value += c + 3;
    }
}

std::string Password::str() const {
    return _encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == _encrypted_value;
}

bool Password::operator==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
}