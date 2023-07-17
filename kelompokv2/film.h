#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

struct Film {
    std::string nama, genre, durasi, tanggal, tayang, harga;
};

class DatabaseFilm {
private:
    std::vector<Film> dataFilm;

public:
    // Konstruktor
    DatabaseFilm();

    // Method untuk membaca data dari file
    void bacaDariFile();

    // Method untuk mencari film berdasarkan nama
    Film* cariFilm(const std::string& namaFilm);

    // Method untuk menampilkan daftar film
    void daftarFilm();

    // Method untuk mengubah string menjadi huruf kecil
    std::string lowercase(std::string target);

    void tambahdata();

    void hapusData(const std::string &namaFilm);

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

//tambah data film
void DatabaseFilm::tambahdata() {
std::ofstream file("film.txt", std::ios::app);
if (!file) {
std::cout << "Gagal membuka file!" << std::endl;
return;
}

Film data;

std::cout << "Masukkan Nama Film: ";
std::cin.ignore();
std::getline(std::cin, data.nama);

std::cout << "Masukkan Genre Film: ";
std::getline(std::cin, data.genre);

std::cout << "Masukkan Durasi Film: ";
std::getline(std::cin, data.durasi);

std::cout << "Masukkan Tanggal Tayang Film: ";
std::getline(std::cin, data.tanggal);

std::cout << "Masukkan Jam Tayang Film: ";
std::getline(std::cin, data.tayang);

std::cout << "Masukkan Harga Tiket Film: ";
std::getline(std::cin, data.harga);

file 
     << data.nama << std::endl
     << data.genre << std::endl
     << data.durasi << std::endl
     << data.tanggal << std::endl
     << data.tayang << std::endl
     << data.harga;

file.close();

bacaDariFile(); // Membaca ulang data setelah menambahkan data

}

//hapus data film
void DatabaseFilm::hapusData(const std::string &namaFilm) 
{
std::ofstream file("film.txt", std::ofstream::trunc); // Membuka file dengan mode truncating untuk menghapus semua data// Membuka file dengan mode truncating untuk menghapus semua data

if (!file) {
    std::cout << "Gagal membuka file!" << std::endl;
    return;
}

std::vector<Film>::iterator it;
for (it = dataFilm.begin(); it != dataFilm.end(); ++it) {
    if (lowercase(it->nama) != lowercase(namaFilm)) {
        // Menyimpan data selain data yang ingin dihapus ke file
        file
             << it->nama << std::endl
             << it->genre << std::endl
             << it->durasi << std::endl
             << it->tanggal << std::endl
             << it->tayang << std::endl
             << it->harga;
    }
}

file.close();

bacaDariFile(); // Membaca ulang data setelah menghapus data

std::cout << "Data film dengan nama " << namaFilm << " berhasil dihapus." << std::endl;
}

