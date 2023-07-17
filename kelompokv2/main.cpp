#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
  mainn data;
  char ulangmenu;

  do {
  data.inputmenu();
  data.switchcase();
  cout << "\nIngin kembali ke menu (y/n) : "; 
  cin >> ulangmenu;                               
  cout << "" << endl;
  }while(ulangmenu == 'Y' || ulangmenu == 'y');

  cout << "===== TERIMA KASIH =====" << endl;
}
