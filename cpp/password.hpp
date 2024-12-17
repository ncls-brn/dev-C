#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>
#include <iostream>

class Password {
private:
    std::string _raw_value;
    std::string _encrypted_value;
    void encrypt(const std::string &password);

public:
    Password(const std::string &password, bool is_encrypted);
    std::string str() const;
    bool operator==(const std::string &str) const;
    bool operator==(const Password &other) const;
};

#endif