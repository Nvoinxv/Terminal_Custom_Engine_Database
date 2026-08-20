#include "DATABASE_ENGINE.hpp"

void Database::membuat_tabel(const std::string& nama) {
    if (ada_tabel(nama)) {
        std::cout << "Error: Tabel '" << nama << "' sudah ada." << std::endl;
        return;
    }
    tabel[nama] = Tabel();
    std::cout << "Tabel '" << nama << "' berhasil dibuat." << std::endl;
}

void Database::menghapus_tabel(const std::string& nama) {
    auto it = tabel.find(nama);
    if (it != tabel.end()) {
        tabel.erase(it);
        std::cout << "Tabel '" << nama << "' berhasil dihapus." << std::endl;
    } else {
        std::cout << "Error: Tabel '" << nama << "' tidak ditemukan." << std::endl;
    }
}

Tabel* Database::mendapatkan_tabel(const std::string& nama) {
    auto it = tabel.find(nama);
    if (it != tabel.end()) {
        return &(it->second);
    }
    return nullptr;
}

bool Database::ada_tabel(const std::string& nama) const {
    return tabel.find(nama) != tabel.end();
}

void Database::tampilkan_semua_tabel() const {
    if (tabel.empty()) {
        std::cout << "Database kosong." << std::endl;
        return;
    }
    
    std::cout << "Tabel dalam database:" << std::endl;
    for (const auto& [nama, _] : tabel) {
        std::cout << "- " << nama << " (" << _.jumlah_records() << " records)" << std::endl;
    }
}