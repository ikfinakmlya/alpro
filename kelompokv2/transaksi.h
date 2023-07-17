#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

struct Riwayat {
    std::string nama, tanggal, tayang, tgl transaksi, 
};

class DatabaseRiwayat {
private:
    std::vector<Riwayat> dataFilm;

public:
    // Konstruktor
    DatabaseRiwayat();

    // Method untuk membaca data dari file
    void bacaDariFile();

    // Method untuk mencari film berdasarkan nama
    Film* cariFilm(const std::string& namaFilm);

    // Method untuk menampilkan daftar film
    void daftarFilm();

    // Method untuk mengubah string menjadi huruf kecil
    std::string lowercase(std::string target);
};

// Implementasi konstruktor
DatabaseFilm::DatabaseFilm() {
    bacaDariFile();
}

// Implementasi method untuk membaca data dari file
void DatabaseFilm::bacaDariFile() {
    std::ifstream file("film.txt");
    if (!file) {
        std::cout << "Gagal membuka file!" << std::endl;
        return;
    }

    dataFilm.clear();

    Film info;
    while (getline(file, info.nama)) {
        getline(file, info.genre);
        getline(file, info.durasi);
        getline(file, info.tanggal);
        getline(file, info.tayang);
        getline(file, info.harga);

        dataFilm.push_back(info);
    }

    file.close();
}

// Implementasi method untuk mencari film berdasarkan nama
Film* DatabaseFilm::cariFilm(const std::string& namaFilm) {
    for (Film& film : dataFilm) {
        if (lowercase(film.nama) == lowercase(namaFilm)) {
            return &film;
        }
    }
    return nullptr;
}

// Implementasi method untuk menampilkan daftar film
void DatabaseFilm::daftarFilm() {
    for (const Film& film : dataFilm) {
        std::cout << "Nama\t\t: " << film.nama << std::endl;
        std::cout << "Genre\t\t: " << film.genre << std::endl;
        std::cout << "Durasi\t\t: " << film.durasi << std::endl;
        std::cout << "Tanggal Tayang\t: " << film.tanggal << std::endl;
        std::cout << "Jam Tayang\t: " << film.tayang << std::endl;
        std::cout << "Harga\t\t: " << film.harga << std::endl;
        std::cout << "=============================" << std::endl;
    }
}

// Implementasi method untuk mengubah string menjadi huruf kecil
std::string DatabaseFilm::lowercase(std::string target) {
    std::transform(target.begin(), target.end(), target.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return target;
}
