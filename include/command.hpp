#pragma once
#include "DATABSE_ENGINE.hpp"
#include "record.hpp"
#include "table.hpp"
#include <unordered_map>
#include <iostream>
#include <string>

class DATABASE;

class command {
    public:
    void membaca_perintah(std::string& input);
    void membuat_parser(std::string& input);

    private:
    DATABASE* database;
}