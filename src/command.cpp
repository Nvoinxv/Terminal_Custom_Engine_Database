#include "command.hpp"

Command::Command(Database& database)
    : database(database)
{
}

void Command::membaca_perintah()
{
    std::string input;

    std::cout << "mydb> ";
    std::getline(std::cin, input);

    membuat_parser(input);
}