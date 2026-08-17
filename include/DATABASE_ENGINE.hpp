#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "table.hpp"

class Tabel;

class Database {
    public:
    void membuat_tabel(const std::string& nama);
    void menghapus_tabel(const std::string& nama);

    Tabel* mendapatkan_tabel(const std::string& nama);
    
    private:
    std::unordered_map<std::string, Tabel> tabel;
}

