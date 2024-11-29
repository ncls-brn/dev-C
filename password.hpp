#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>
#include <iostream>

class Password {
public:
    Password(std::string password, bool is_encrypted = false);  
    void encrypt();  
    std::string str();  
    bool operator==(const std::string& str) const;  
    bool operator==(const Password& other) const;  
    friend std::ostream &operator<<(std::ostream &os, const Password &p);  

private:
    std::string _raw_value;  
    std::string _encrypted_value;
    bool _is_encrypted;  
};

#endif
