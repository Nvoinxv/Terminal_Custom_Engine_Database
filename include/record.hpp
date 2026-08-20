#pragma once
#include <string>
#include <unordered_map>

class Record {
public:
    void set(const std::string& bidang, const std::string& nilai);
    std::string mendapatkan(const std::string& bidang) const;
    bool memiliki_bidang(const std::string& bidang) const;
    void tampilkan_semua() const;

private:
    std::unordered_map<std::string, std::string> Bidang;
};