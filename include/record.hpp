#pragma once
#include <string>
#include <unordered_map>

class Record {
    public:
    void set(const std::string& bidang, std::string& nilai);
    std::string mendapatkan(const std::string& bidang) const;

    private:
    std::unordered_map<std::string, std::string> Bidang;
}