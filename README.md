# Terminal Custom Database Engine

Sebuah sistem database sederhana berbasis terminal yang diimplementasikan menggunakan C++. Project ini menyediakan antarmuka *command-line* (CLI) yang interaktif untuk melakukan operasi CRUD (Create, Read, Update, Delete) secara mudah. Didesain secara fleksibel, aplikasi ini juga mendukung perintah operasional (*commands*) dalam dua bahasa: Bahasa Indonesia dan Bahasa Inggris.

## 🚀 Fitur Utama
- Pembuatan dan penghapusan tabel secara dinamis sesuai kebutuhan pengguna.
- *Insert* record dengan *field* yang fleksibel menggunakan format *key-value pairs*.
- Pencarian record berdasarkan ID unik.
- Menampilkan seluruh *records* yang terdapat di dalam sebuah tabel.
- Menampilkan daftar keseluruhan tabel yang tersedia di dalam database.
- *Interface command-line* yang interaktif, responsif, dan mudah digunakan.
- Mendukung dua macam gaya penulisan perintah: Bahasa Indonesia dan English.

## 💻 Persyaratan Sistem (*Requirements*)
Untuk dapat mengompilasi dan menjalankan project ini, pastikan sistem Anda memenuhi spesifikasi berikut:
- **CMake** versi 3.10 atau lebih tinggi.
- ***Compiler* pendukung C++17** (GCC 7+, Clang 5+, atau MSVC 2017+).
- **Sistem Operasi**: Linux, macOS, atau Windows.

## 🛠️ Cara Kompilasi (*Build Instructions*)
Project ini menggunakan CMake sebagai *build system* utamanya. Ikuti langkah-langkah di bawah ini untuk mengompilasi kode sumber:

1. *Clone* repositori ini ke dalam direktori lokal Anda (jika belum):
   ```bash
   git clone https://github.com/username/terminal-custom-db-engine.git
   cd terminal-custom-db-engine
   ```
2. Buat direktori `build` baru dan arahkan terminal ke direktori tersebut:
   ```bash
   mkdir build
   cd build
   ```
3. Konfigurasikan project dengan menjalankan CMake:
   ```bash
   cmake ..
   ```
4. Kompilasi project menjadi *executable*:
   ```bash
   cmake --build .
   ```

## ▶️ Cara Menjalankan Program
Setelah proses kompilasi sukses, file *executable* akan di-generate ke dalam folder `bin/` yang berada di direktori *root* (atau mengikuti konfigurasi *build system* Anda).

Jalankan *database engine* melalui terminal:
```bash
# Untuk Linux / macOS:
./bin/Terminal_Custom_Database_Engine_debug

# Untuk Windows:
.\bin\Terminal_Custom_Database_Engine_debug.exe
```

## 📖 Panduan Penggunaan (*Usage Guide*)
Begitu program berhasil dijalankan, Anda akan masuk ke CLI interaktif. Ketik perintah lalu tekan `Enter` untuk mengeksekusi operasi database. 

### Daftar Perintah (*Supported Commands*)
Anda dapat secara bebas menggunakan varian perintah Bahasa Inggris atau Bahasa Indonesia:

| Perintah (English) | Perintah (Indonesia) | Deskripsi |
| :--- | :--- | :--- |
| `CREATE <tabel>` | `BUAT <tabel>` | Membuat tabel baru yang kosong |
| `INSERT <tabel> <id> <k=v>` | *(Sama dengan English)* | Memasukkan record baru dengan *key-value pairs* |
| `SELECT <tabel> [id]` | `CARI <tabel> [id]` | Mencari dan menampilkan record berdasarkan ID |
| `SELECT * FROM <tabel>` | *(Sama dengan English)* | Menampilkan seluruh record di tabel tersebut |
| `DELETE <tabel> <id>` | `HAPUS <tabel> <id>` | Menghapus record tertentu berdasarkan ID |
| `DROP <tabel>` | `BUANG <tabel>` | Menghapus suatu tabel beserta seluruh isinya |
| `SHOW TABLES` | `TAMPILKAN TABEL` | Menampilkan seluruh nama tabel dalam database |
| `HELP` | `BANTUAN` | Menampilkan daftar lengkap bantuan perintah |
| `EXIT` | `KELUAR` | Menutup sesi dan keluar dari aplikasi |

### Contoh Penggunaan (*Interactive Session Example*)
Berikut adalah ilustrasi singkat *workflow* penggunaan aplikasi:

```text
DB-Engine> BUAT users
[OK] Tabel 'users' berhasil dibuat.

DB-Engine> INSERT users 1 nama=Budi umur=25 kota=Jakarta
[OK] Record dengan ID 1 berhasil dimasukkan ke 'users'.

DB-Engine> INSERT users 2 nama=Andi umur=30 kota=Bandung
[OK] Record dengan ID 2 berhasil dimasukkan ke 'users'.

DB-Engine> CARI users 1
[RESULT] ID: 1 | nama: Budi | umur: 25 | kota: Jakarta

DB-Engine> SELECT * FROM users
[RESULT] Tabel 'users':
- ID: 1 | nama: Budi | umur: 25 | kota: Jakarta
- ID: 2 | nama: Andi | umur: 30 | kota: Bandung

DB-Engine> TAMPILKAN TABEL
[RESULT] Daftar Tabel:
1. users

DB-Engine> KELUAR
Terima kasih telah menggunakan Terminal Custom Database Engine!
```

## 📂 Struktur Project
Struktur dasar dari project ini adalah sebagai berikut:
```text
.
├── bin/             # Folder output tempat file executable diletakkan
├── include/         # Tempat menyimpan semua file header C++ (.hpp)
├── src/             # Tempat menyimpan semua implementasi *source code* (.cpp)
├── CMakeLists.txt   # File konfigurasi utama untuk CMake
└── README.md        # File dokumentasi project ini
```

## 📜 Lisensi
Project ini didistribusikan di bawah [MIT License](https://opensource.org/licenses/MIT). Anda bebas untuk menggunakan, memodifikasi, dan mendistribusikan kode ini untuk tujuan komersial maupun pribadi dengan tetap menyertakan atribusi hak cipta aslinya.
