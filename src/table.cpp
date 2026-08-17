#include "table.hpp"

void memasukkan(const std::string& id, const Record& record) {
    // Kita mencari id dahulu
    if (record.find(id) != record.end()) {
        std::cout << "ID " << id << " sudah ditemukan.\n";
        return;
    } else {
        // Kalau tidak ketemu
        std::cout << "ID belum ditemukan.\n";
        return;
    }
    
    // Setelah ketemu, langsung bisa memasukkan id
    record.insert(id, Record(id));
}