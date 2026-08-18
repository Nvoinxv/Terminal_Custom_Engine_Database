#include "record.hpp"

void Record::set(const std::string& bidang,
std::string& nilai) {
    bidang[bidang] = nilai;
}

std::string Record::mendapatkan(const std::string& bidang) const {
    auto it = Bidang.find(bidang);

    if (it == Bidang.end()) {
        return " ";
    }
}