#include <iostream>
#include "film.h"
#include "cemilan.h"
#include <sstream>
#include <ctime>

using namespace std;

class mainn
{
  private :
     int pilihan;
     int subPilihan;
     int uang;
     int pilriwayat;
     int manage;
     string namaFilm;
     string namaCemilan;
     string beltiket;
     string belcemilan;

  public : 
     DatabaseFilm databaseFilm;
     DatabaseCemilan databaseCemilan;

//=============================================================
  void inputmenu()
  {
   cout << "===== MENU BIOSKOP =====" <<endl;
   cout << "1. Manajemen Film" <<endl;
   cout << "2. DaftarFilm" <<endl;
   cout << "3. Beli Tiket" <<endl;
   cout << "4. Beli Cemilan" <<endl;
   cout << "5. Riwayat Transaksi" <<endl;
   cout << "6. Keluar" << endl;
   cout << "======================" <<endl;
   cout << "Pilihan: ";
   cin >> pilihan;
  }
//=============================================================   
  void beliTiket()
  {
    //kamus lokal : 

    //mendapatkan tgl dan waktu sekarang 
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;

    //deskripsi : 
     cout << "\nMasukkan nama film : ";
     cin.ignore();
     getline(cin, namaFilm);
     Film * film = databaseFilm.cariFilm(namaFilm); //memanggil method cari film dengan input nam film
     if (film != nullptr)
      {
       cout << "\n===== Informasi Film =====\n" <<endl;
       cout << "Nama Film\t: " << film->nama<<endl;
       cout << "Genre\t\t: " << film->genre <<endl;
       cout << "Durasi\t\t: " << film->durasi <<endl;
       cout << "Tanggal Tayang\t: " << film->tanggal <<endl;
       cout << "Jam Tayang\t: " << film->tayang <<endl;
       cout << "Harga\t\t: " << film->harga <<endl;
       cout << "================================" <<endl;
       cout << "\nMasukkan Uang : "; //input uang anda
       cin >> uang;
       
       //membuat variable untuk convert film-> harga ke int
       int harga;
       string  hargafilm = film->harga;

       stringstream temp; // tempat sementara untuk convert film->harga ke int
       
       // proses convert
       temp << hargafilm; 
       temp >> harga;

       if (uang >= harga) { // Pastikan uang mencukupi
        //Jika uang mencukupi
        cout << "\n===== Pembelian Sukses =====\n" <<endl;
        cout << "Nama Film\t: " << film->nama <<endl;
        cout << "Genre\t\t: " << film->genre <<endl;
        cout << "Durasi\t\t: " << film->durasi <<endl;
        cout << "Tanggal Tayang\t: " << film->tanggal <<endl;
        cout << "Jam Tayang\t: " << film->tayang <<endl;
        cout << "Harga\t\t: " << film->harga <<endl;
        cout << "Uang Anda \t: " << uang << endl;
        cout << "Kembalian Anda  : "  << uang - harga << endl;

        ofstream simpan("riwayat.txt", ios::app); //proses menyimpan ke riwayat.txt
        if (simpan.is_open())
        {  
        simpan << "\n===== Pembelian Tiket =====\n" <<endl;
        simpan << "Nama Film         : " << film->nama <<endl;
        simpan << "Tanggal Tayang    : " << film->tanggal <<endl;
        simpan << "Jam Tayang        : " << film->tayang <<endl;

        // Menampilkan tgl dan waktu
        simpan << "Tanggal Transaksi : " << day << "-" << month << "-" << year << endl;
        simpan << "Waktu Transaksi   : " << hour << "." << minute << " WIB "<< endl;

        //menampilkan harga dan uang kembalian
        simpan << "Harga             : " << film->harga <<endl;
        simpan << "Uang Anda         : " << uang << endl;
        simpan << "Kembalian Anda    : " << uang - harga << endl;
        }
        simpan.close();
        
       }else {
        //jika uang tiddak mnencukupi
        cout << "Uang Anda tidak mencukupi." << endl;
       }
      }
      else
      {
       cout << "Film dengan nama \"" << namaFilm << "\" tidak ditemukan." <<endl;
      }
  }
//=============================================================  
void beliCemilan()
  {
    //kamus lokal : 
    //mendapatkan tgl dan waktu sekarang 
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;

    //deskripsi : 
     cout << "\nMasukkan nama cemilan : ";
     cin.ignore();
     getline(cin, namaCemilan);

    Cemilan * cemilan = databaseCemilan.cariCemilan(namaCemilan);
    if (cemilan != nullptr)
      {
       cout << "\n===== Informasi Cemilan =====\n" <<endl;
       cout << "Jenis\t\t: " << cemilan->jenis <<endl;
       cout << "Nama\t\t: " << cemilan->nama <<endl;
       cout << "Harga\t\t: " << cemilan->harga <<endl;
       cout << "================================" <<endl;
       cout << "\nMasukkan Uang : ";
       cin >> uang;
       
       int harga;
       string  hargamenu = cemilan->harga;

       stringstream temp; // untuk convert film->cemilan ke int

       temp << hargamenu;
       temp >> harga;

       if (uang >= harga) { // Pastikan uang mencukupi
        cout << "\n===== Pembelian Sukses =====\n" <<endl;
        cout << "Jenis\t\t: " << cemilan->jenis <<endl;
        cout << "Nama\t\t: " << cemilan->nama <<endl;
        cout << "Harga\t\t: " << cemilan->harga <<endl;
        cout << "Uang Anda \t: " << uang << endl;
        cout << "Kembalian Anda  : " << uang - harga << endl;

        ofstream simpan("riwayat.txt", ios::app);
        if (simpan.is_open())
        {  
        simpan << "\n===== Pembelian Cemilan =====\n" <<endl;
        simpan << "Jenis             : " << cemilan->jenis <<endl;
        simpan << "Nama              : " << cemilan->nama <<endl;

        // Menampilkan tgl & waktu 
        simpan << "Tanggal Transaksi : " << day << "-" << month << "-" << year << endl;
        simpan << "Waktu Transaksi   : " << hour << "." << minute << " WIB "<< endl;

        //menampilkan harga dan uang kembalian
        simpan << "Harga             : " << cemilan->harga <<endl;
        simpan << "Uang Anda         : " << uang << endl;
        simpan << "Kembalian Anda    : " << uang - harga << endl;
        }
        simpan.close();

       }else {
        cout << "Uang Anda tidak mencukupi." << endl;
       }
      }
      else
      {
       cout << "Cemilan dengan nama \"" << namaCemilan << "\" tidak ditemukan." <<endl;
      }
  }
//=============================================================  
void riwayat()
  {
    ifstream myfile("riwayat.txt"); 
      string line;
        if(myfile.is_open()){
          while(getline (myfile, line)){
            cout << line << endl;
          }
          myfile.close();
        }else {
          cout << "File gagal dibuka";
        }
  }
//=============================================================
Film data;

void tambahdata()
{   
   cout << "Nama : ";
   cin.ignore();
   getline(cin, data.nama);
   cout << "Genre : ";
   cin.ignore();
   getline(cin, data.genre);
   cout << "Durasi : ";
   cin.ignore();
   getline(cin, data.durasi);
   cout << "Tanggal Tayang : ";
   cin.ignore();
   getline(cin, data.tanggal);
   cout << "Jam Tayang : ";
   cin.ignore();
   getline(cin, data.tayang);
   cout << "Harga : ";
   cin >> data.harga;

   ofstream simpan("film.txt", ios::app);
    if (simpan.is_open())
    {
      simpan << data.nama << endl;
      simpan << data.genre << endl;
      simpan << data.durasi << endl;
      simpan << data.tanggal << endl;
      simpan << data.tayang << endl;
      simpan << data.harga << endl;
      simpan.close();
      
    }
}
//=============================================================

  void switchcase()
  {
    switch (pilihan)
    {
    case 1:
      cout << "\n===== Managemen data =====" << endl;
      cout << "1. Tambah data film" << endl;
      cout << "2. Hapus data film" << endl;
      cout << "============================" << endl;
      cout << "pilihan : ";
      cin >> manage;
      cout << "" << endl;
      switch(manage){
        case 1 :
          databaseFilm.tambahdata();
          break;
        case 2 :
          cout << "\nMasukkan nama film : ";
          cin.ignore();
          getline(cin, namaFilm);
          databaseFilm.hapusData(namaFilm);
          break;
      }
      break;

    case 2 :
      cout << "\n====== Daftar Film ======\n" <<endl;
      databaseFilm.daftarFilm();
      cout << "Ingin beli tiket ? (y/n) : ";
      cin >> beltiket;
      if(beltiket == "y" || beltiket == "Y"){
        beliTiket();
      }
      break;

    case 3 : 
      beliTiket();
      break;

    case 4:
      cout << "\n====== Daftar Menu Camilan ======\n" <<endl;
      databaseCemilan.daftarCemilan();
      cout << "Ingin beli cemilan ? (y/n) : ";
      cin >> belcemilan;
      if(belcemilan == "y" || belcemilan == "Y"){
        beliCemilan();
      }
      break;
    
    case 5 : 
      riwayat();
      break;

    case 6 :
      cout << "\n===== TERIMA KASIH =====";
      exit(0); 

    default:
      cout << "Pilihan tidak valid." <<endl;
      break;
    }
  }
};
