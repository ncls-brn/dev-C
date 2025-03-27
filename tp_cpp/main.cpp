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

    // on préfère cibler les exceptions spécifiques à chaque erreur possible
    // quitte à faire plusieurs blocs try/catch.
    } catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    // Quelques tests sur l'objet Password pour vérifier
    // son bon fonctionnement auraient été bienvenus ici.
    return 0;
}