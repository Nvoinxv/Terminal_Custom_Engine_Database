#pragma once
#include "DATABASE_ENGINE.hpp"
#include "record.hpp"
#include "table.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class command {
public:
    command(Database* db);
    void membaca_perintah(std::string& input);
    void membuat_parser(std::string& input);
    void tampilkan_bantuan();

private:
    Database* database;
    
    // Helper functions
    std::vector<std::string> split_string(const std::string& input, char delimiter);
    std::string to_lowercase(const std::string& input);
    void handle_create(std::vector<std::string>& tokens);
    void handle_insert(std::vector<std::string>& tokens);
    void handle_select(std::vector<std::string>& tokens);
    void handle_delete(std::vector<std::string>& tokens);
    void handle_drop(std::vector<std::string>& tokens);
    void handle_show(std::vector<std::string>& tokens);
};