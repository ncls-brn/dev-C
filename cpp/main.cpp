#include "user.hpp"
#include "password.hpp"
#include <iostream>

int main() {
    try {
       
        std::string username, raw_password;
        std::cout << "Entrez le nom d'utilisateur : ";
        std::cin >> username;
        std::cout << "Entrez le mot de passe : ";
        std::cin >> raw_password;
        Password password(raw_password, false);
        User user(username, password);
        
        user.save();

    } catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}