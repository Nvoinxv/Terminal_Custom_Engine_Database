#include "../command.hpp"
#include "../DATABASE_ENGINE.hpp"
#include "../record.hpp"
#include "../table.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "====================================\n";
    std::cout << "   SISTEM DATABASE SEDERHANA v1.0   \n";
    std::cout << "====================================\n";
    std::cout << "Ketik 'HELP' untuk melihat bantuan\n";
    std::cout << "Ketik 'EXIT' untuk keluar\n\n";
    
    Database database;
    command cmd(&database);
    
    std::string input;
    
    while (true) {
        cmd.membaca_perintah(input);
        cmd.membuat_parser(input);
    }
    
    return 0;
}