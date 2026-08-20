#include "command.hpp"
#include <algorithm>
#include <cctype>

command::command(Database* db) : database(db) {}

std::vector<std::string> command::split_string(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        // Trim whitespace
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::string command::to_lowercase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void command::membaca_perintah(std::string& input) {
    std::cout << ">> ";
    std::getline(std::cin, input);
}

void command::membuat_parser(std::string& input) {
    if (input.empty()) return;
    
    // Split by space for main command
    std::vector<std::string> tokens = split_string(input, ' ');
    
    if (tokens.empty()) return;
    
    std::string command_type = to_lowercase(tokens[0]);
    
    if (command_type == "help" || command_type == "bantuan") {
        tampilkan_bantuan();
    }
    else if (command_type == "create" || command_type == "buat") {
        handle_create(tokens);
    }
    else if (command_type == "insert" || command_type == "masukkan") {
        handle_insert(tokens);
    }
    else if (command_type == "select" || command_type == "cari") {
        handle_select(tokens);
    }
    else if (command_type == "delete" || command_type == "hapus") {
        handle_delete(tokens);
    }
    else if (command_type == "drop" || command_type == "buang") {
        handle_drop(tokens);
    }
    else if (command_type == "show" || command_type == "tampilkan") {
        handle_show(tokens);
    }
    else if (command_type == "exit" || command_type == "keluar") {
        std::cout << "Terima kasih telah menggunakan sistem database!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Error: Perintah tidak dikenal. Ketik 'help' untuk bantuan." << std::endl;
    }
}

void command::handle_create(std::vector<std::string>& tokens) {
    if (tokens.size() < 2) {
        std::cout << "Error: Gunakan format 'CREATE <nama_tabel>'" << std::endl;
        return;
    }
    
    if (tokens.size() >= 3 && to_lowercase(tokens[1]) == "table") {
        database->membuat_tabel(tokens[2]);
    } else {
        database->membuat_tabel(tokens[1]);
    }
}

void command::handle_insert(std::vector<std::string>& tokens) {
    if (tokens.size() < 4) {
        std::cout << "Error: Gunakan format 'INSERT <nama_tabel> <id> <field1=value1> <field2=value2> ...'" << std::endl;
        return;
    }
    
    std::string nama_tabel = tokens[1];
    std::string id = tokens[2];
    
    Tabel* tabel = database->mendapatkan_tabel(nama_tabel);
    if (!tabel) {
        std::cout << "Error: Tabel '" << nama_tabel << "' tidak ditemukan." << std::endl;
        return;
    }
    
    Record record;
    
    // Parse field=value pairs
    for (size_t i = 3; i < tokens.size(); i++) {
        size_t pos = tokens[i].find('=');
        if (pos != std::string::npos) {
            std::string field = tokens[i].substr(0, pos);
            std::string value = tokens[i].substr(pos + 1);
            record.set(field, value);
        }
    }
    
    tabel->memasukkan(id, record);
}

void command::handle_select(std::vector<std::string>& tokens) {
    if (tokens.size() < 2) {
        std::cout << "Error: Gunakan format 'SELECT <nama_tabel> [id]'" << std::endl;
        return;
    }
    
    // Handle "SELECT * FROM table" syntax
    if (tokens.size() >= 4 && tokens[1] == "*" && to_lowercase(tokens[2]) == "from") {
        Tabel* tabel = database->mendapatkan_tabel(tokens[3]);
        if (tabel) {
            tabel->tampilkan_semua_records();
        } else {
            std::cout << "Error: Tabel '" << tokens[3] << "' tidak ditemukan." << std::endl;
        }
        return;
    }
    
    std::string nama_tabel = tokens[1];
    Tabel* tabel = database->mendapatkan_tabel(nama_tabel);
    
    if (!tabel) {
        std::cout << "Error: Tabel '" << nama_tabel << "' tidak ditemukan." << std::endl;
        return;
    }
    
    if (tokens.size() == 2) {
        // Show all records
        tabel->tampilkan_semua_records();
    } else if (tokens.size() == 3) {
        // Find specific record
        Record* record = tabel->mencari(tokens[2]);
        if (record) {
            std::cout << "Record ID '" << tokens[2] << "':" << std::endl;
            record->tampilkan_semua();
        } else {
            std::cout << "Error: Record dengan ID '" << tokens[2] << "' tidak ditemukan." << std::endl;
        }
    }
}

void command::handle_delete(std::vector<std::string>& tokens) {
    if (tokens.size() < 3) {
        std::cout << "Error: Gunakan format 'DELETE <nama_tabel> <id>'" << std::endl;
        return;
    }
    
    Tabel* tabel = database->mendapatkan_tabel(tokens[1]);
    if (!tabel) {
        std::cout << "Error: Tabel '" << tokens[1] << "' tidak ditemukan." << std::endl;
        return;
    }
    
    tabel->menghapus(tokens[2]);
}

void command::handle_drop(std::vector<std::string>& tokens) {
    if (tokens.size() < 2) {
        std::cout << "Error: Gunakan format 'DROP <nama_tabel>'" << std::endl;
        return;
    }
    
    if (tokens.size() >= 3 && to_lowercase(tokens[1]) == "table") {
        database->menghapus_tabel(tokens[2]);
    } else {
        database->menghapus_tabel(tokens[1]);
    }
}

void command::handle_show(std::vector<std::string>& tokens) {
    if (tokens.size() >= 2 && (to_lowercase(tokens[1]) == "tables" || to_lowercase(tokens[1]) == "tabel")) {
        database->tampilkan_semua_tabel();
    } else {
        database->tampilkan_semua_tabel();
    }
}

void command::tampilkan_bantuan() {
    std::cout << "\n=== BANTUAN DATABASE SEDERHANA ===\n"
              << "Perintah yang tersedia:\n"
              << "1. CREATE <nama_tabel>          - Membuat tabel baru\n"
              << "2. INSERT <tabel> <id> <field=value>... - Menambahkan record\n"
              << "3. SELECT <tabel> [id]          - Menampilkan record(s)\n"
              << "4. SELECT * FROM <tabel>       - Menampilkan semua records\n"
              << "5. DELETE <tabel> <id>          - Menghapus record\n"
              << "6. DROP <tabel>                 - Menghapus tabel\n"
              << "7. SHOW TABLES                  - Menampilkan semua tabel\n"
              << "8. HELP                         - Menampilkan bantuan ini\n"
              << "9. EXIT                         - Keluar dari program\n"
              << "================================\n\n";
}