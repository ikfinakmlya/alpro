#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

struct Cemilan {
    std::string jenis, nama, harga;
};

class DatabaseCemilan {
private:
    std::vector<Cemilan> dataCemilan;

public:
    // Konstruktor
    DatabaseCemilan();

    // Method untuk membaca data dari file
    void bacaDariFile();

    // Method untuk mencari menu berdasarkan nama
    Cemilan* cariCemilan(const std::string& namaCemilan);

    // Method untuk menampilkan daftar menu
    void daftarCemilan();

    // Method untuk mengubah string menjadi huruf kecil
    std::string lowercase(std::string target);
};

// Implementasi konstruktor
DatabaseCemilan::DatabaseCemilan() {
    bacaDariFile();
}

// Implementasi method untuk membaca data dari file
void DatabaseCemilan::bacaDariFile() {
    std::ifstream file("makanan.txt");
    if (!file) {
        std::cout << "Gagal membuka file!" << std::endl;
        return;
    }

    dataCemilan.clear();

    Cemilan info;
    while (getline(file, info.jenis)) {
        getline(file, info.nama);
        getline(file, info.harga);
        
        dataCemilan.push_back(info);
    }

    file.close();
}
 

// Implementasi method untuk mencari menu berdasarkan nama
Cemilan* DatabaseCemilan::cariCemilan(const std::string& namaCemilan) {
    for (Cemilan & cemilan : dataCemilan) {
        if (lowercase(cemilan.nama) == lowercase(namaCemilan)) {
            return & cemilan;
        }
    }
    return nullptr;
}

// Implementasi method untuk menampilkan daftar menu
void DatabaseCemilan::daftarCemilan() {
    for (const Cemilan & menu : dataCemilan) {
        std::cout << "Jenis\t\t: " << menu.jenis << std::endl;
        std::cout << "Nama\t\t: " << menu.nama << std::endl;
        std::cout << "Harga\t\t: " << menu.harga << std::endl;
        std::cout << " " << std::endl;
    }
}

// Implementasi method untuk mengubah string menjadi huruf kecil
std::string DatabaseCemilan::lowercase(std::string target) {
    std::transform(target.begin(), target.end(), target.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return target;
}