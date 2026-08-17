#include "table.hpp"

void memasukkan(const std::string& id, const Record& record) {
    // Kita mencari id dahulu
    if (records.find(id) != records.end()) {
        std::cout << "ID " << id << " sudah ditemukan.\n";
        return;
    } else {
        // Kalau tidak ketemu
        std::cout << "ID belum ditemukan.\n";
        return;
    }
    
    // Setelah ketemu, langsung bisa memasukkan id
    records.insert(id, Record(id));
}

void menghapus(const std::string& id) {
    if (records.find(id) != records.end()) {
        std::cout << "ID: " << id << "sudah ditemukan.\n";
        return;
    } else {
        std::cout << "ID belum ditemukan.\n";
        return;
    }
    
    // Langsung menghapus id jika sudah ditemukan 
    std::cout << "ID BERHASIL DIHAPUS.\n";
    records.erase(id);
}

Tabel::mencari(const std::string& id) {
    auto it = records.find(id);

    if (it == records.end()) {
        std::cout << "ID " << id << "Berhasil ditemukan.\n";
        return &(it->second);
    } else {
        std::cout << "ID TIDAK DITEMUKAN.\n";
        return nullptr;
    }
}