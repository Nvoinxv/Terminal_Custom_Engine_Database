#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include "record.hpp"

class Tabel {
public:
    void memasukkan(const std::string& id, const Record& record);
    void menghapus(const std::string& id);
    Record* mencari(const std::string& id);
    bool ada_record(const std::string& id) const;
    void tampilkan_semua_records() const;
    size_t jumlah_records() const;

private:
    std::unordered_map<std::string, Record> records;
};