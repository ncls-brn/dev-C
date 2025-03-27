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
    // Il peut être intéressant ici d'utiliser un smart pointer
    // std::unique_ptr<Password> password;
    // Cela créé une nouvelle copie du mot de passe (donc pas
    // de souci si une autre partie du code free la mémoire)
    // et donne automatiquement aux instances de User la responsabilité
    // de libérer la mémoire de leurs mdp quand elle elles sont détruites
    Password* password;
    static const std::string FILE_NAME;

public:
    
    User(const std::string &name, Password &password);
    void save() const;
    std::string getName() const { return name; }
};

#endif 