#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

class Record;

class Tabel {
    public:
    void memasukkan(const std::string& id, const Record& record);
    void menghapus(const std::string& id);
    Record* mencari(const std::string& id);

    private:
    std::unordered_map<std::string, Record> records;
}