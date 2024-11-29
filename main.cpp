#include <iostream>
#include "password.hpp"

int main() {
 
    std::string password1;
    std::cout << "Veuillez entrer le premier mot de passe : ";
    std::cin >> password1;

   
    Password pwd1(password1);
    std::cout << "Premier mot de passe chiffré : " << pwd1 << std::endl; 

   
    std::string password2;
    std::cout << "Veuillez entrer le deuxième mot de passe : ";
    std::cin >> password2;

    
    Password pwd2(password2);
    std::cout << "Deuxième mot de passe chiffré : " << pwd2 << std::endl;

   
    if (pwd1 == pwd2) {
        std::cout << "Les mots de passe sont identiques." << std::endl;
    } else {
        std::cout << "Les mots de passe sont différents." << std::endl;
    }

    return 0;
}
