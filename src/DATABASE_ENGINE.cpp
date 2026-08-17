#include "DATABASE_ENGINE.hpp"

void membuat_tabel(const std::string& nama) {
    if (tabel.find(nama) != tabel.end()) {
        std::cout << "Tabel sudah ada\n";
        return;
    } else {
        std::cout << "Tabel tidak ada\n";
        return;
    }

    tabel.emplace(nama, Tabel(nama));
}

void menghapus_tabel(const std::string& nama) {
    if (tabel.find(nama) != tabel.end()) {
        std::cout << "Tabel berhasil menemukan tabel. \n";
        std::cout << "Selanjutnya proses penghapusan. \n";
        return;
    } else {
        std::cout << "Tabel tidak ditemukan. \n";
    }

    tabel.erase(nama);
}

DATABASE_ENGINE::mendapatkan_tabel(const std::string& nama) {
    auto it = tabel.find(nama);
    if (it == tabel.end()) {
        std::cout << "Tidak menemukan tabel.\n";
        return nullptr;
    } else {
        std::cout << "Menemukan Tabel.\n";
        return &(it->second);
    }
}