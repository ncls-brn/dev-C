#include "user.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

const std::string User::FILE_NAME = "users.txt";

User::User(const std::string &name, Password &password) 
    : name(name), password(&password) {}

void User::save() const {
    std::ifstream file_in(FILE_NAME);
    if (file_in) {
        std::string line;
        while (std::getline(file_in, line)) {
            
            size_t user_pos = line.find("user: " + name);
            if (user_pos != std::string::npos) {
                std::cout << "L'utilisateur '" << name << "' existe déjà." << std::endl;
                file_in.close();
                return;
            }
        }
    }
    file_in.close();
    std::ofstream file_out(FILE_NAME, std::ios::app);
    if (!file_out) {
        throw std::runtime_error("Impossible d'ouvrir le fichier pour sauvegarde.");
    }

    file_out << "user: " << name << " password: " << password->str() << "\n";
    file_out.close();

    std::cout << "Utilisateur '" << name << "' enregistré avec succès." << std::endl;
}
