#include "record.hpp"
#include <iostream>

void Record::set(const std::string& bidang, const std::string& nilai) {
    Bidang[bidang] = nilai;
}

std::string Record::mendapatkan(const std::string& bidang) const {
    auto it = Bidang.find(bidang);
    if (it != Bidang.end()) {
        return it->second;
    }
    return ""; // Return empty string if field not found
}

bool Record::memiliki_bidang(const std::string& bidang) const {
    return Bidang.find(bidang) != Bidang.end();
}

void Record::tampilkan_semua() const {
    for (const auto& [bidang, nilai] : Bidang) {
        std::cout << "  " << bidang << ": " << nilai << std::endl;
    }
}