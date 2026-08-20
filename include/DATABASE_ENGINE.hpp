#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "table.hpp"

class Database {
public:
    void membuat_tabel(const std::string& nama);
    void menghapus_tabel(const std::string& nama);
    Tabel* mendapatkan_tabel(const std::string& nama);
    bool ada_tabel(const std::string& nama) const;
    void tampilkan_semua_tabel() const;

private:
    std::unordered_map<std::string, Tabel> tabel;
};