// Nama : Ikfina Kamaliya R.
//NIM : A11.2022.14170
//Kelompok : A11.4205
// PROGRAM TOKO TV
#include <iostream>
#include "tv.h"

using namespace std;

int main(){
    tv data;
    string kmblmenu;
    int pilihan;
    int jumdata;

    do {
    data.tampilmenu();
    data.outputmenu();
    cout << "\nIngin kembali ke menu(y/n) : ";
    cin >> kmblmenu;
    cout << "" <<endl;
    }while(kmblmenu == "y" || kmblmenu == "Y");
    cout << "===== Terima Kasih =====" <<endl;
    return 0;
}