#ifndef USER_HPP
#define USER_HPP

#include "password.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class User {
private:
    std::string name;
    Password* password;
    static const std::string FILE_NAME;

public:
    
    User(const std::string &name, Password &password);
    void save() const;
    std::string getName() const { return name; }
};

#endif 