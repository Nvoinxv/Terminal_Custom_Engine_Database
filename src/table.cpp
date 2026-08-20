#include "table.hpp"

void Tabel::memasukkan(const std::string& id, const Record& record) {
    records[id] = record;
    std::cout << "Record dengan ID '" << id << "' berhasil ditambahkan." << std::endl;
}

void Tabel::menghapus(const std::string& id) {
    auto it = records.find(id);
    if (it != records.end()) {
        records.erase(it);
        std::cout << "Record dengan ID '" << id << "' berhasil dihapus." << std::endl;
    } else {
        std::cout << "Error: Record dengan ID '" << id << "' tidak ditemukan." << std::endl;
    }
}

Record* Tabel::mencari(const std::string& id) {
    auto it = records.find(id);
    if (it != records.end()) {
        return &(it->second);
    }
    return nullptr;
}

bool Tabel::ada_record(const std::string& id) const {
    return records.find(id) != records.end();
}

void Tabel::tampilkan_semua_records() const {
    if (records.empty()) {
        std::cout << "Tabel kosong." << std::endl;
        return;
    }
    
    std::cout << "Records dalam tabel:" << std::endl;
    for (const auto& [id, record] : records) {
        std::cout << "ID: " << id << std::endl;
        record.tampilkan_semua();
        std::cout << "---" << std::endl;
    }
}

size_t Tabel::jumlah_records() const {
    return records.size();
}