#include <iostream>
#include <fstream> 

using namespace std;

class tv {

    private : 

        int pilihan,inputcaritv,result;
        string searchmerek;
        string searchukuran;
        string searchresolusi;
        int searchharga;

    public :
        string merek[1000];
        string ukuran[1000];
        string resolusi[1000];
        int harga[1000];
        int jumdata;
        int lenght;

    void tampilmenu(){
        cout << "======== TOKO TV ========" << endl;
        cout << " " << endl;
        cout << "Pilih menu : "  << endl;
        cout << "1. Input data TV" << endl;
        cout << "2. Lihat data TV" <<endl;
        cout << "3. Cari data TV" <<endl;
        cout << "4. Simpan data ke file" <<endl;
        cout << "5. Keluar" << endl;
        cout << " " << endl;
        
      cout << "Masukkan Pilihan : ";
      cin >> pilihan;
      cout << " " << endl;
    }    

    int jumlahdata(int x){
      cout << "Input Jumlah TV : ";
      cin >> x;

      return x;
    }

     void input(int jumlahData)
    {
        cout<<"\n\n======INPUT DATA TV======\n\n";
        for(int x=0; x<jumlahData; x++) 
        {
            int y=1;
            y=y+x;
            cout<<y<<".\n"; //menampilkan nomor urutan data, yang sebenarnya sama dengan (nomor array + 1)

            cout<<"Merk  : ";
            cin.ignore();
            getline(cin,merek[x]);

            cout<<"Ukuran (inch): ";
            cin>>ukuran[x];

            cout << "Resolusi : ";
            cin.ignore();
            getline(cin,resolusi[x]);

            cout<<"Harga : ";
            cin>>harga[x];
            cout<<endl;
        }
        cout<<"===simpan data berhasil!!===\n\n";
    }

     void output(int jumlahData)
    {
        cout<<"\n\n======DAFTAR TV======\n\n";
        for(int x=0; x<jumlahData; x++)
            {
                int y=1;
                y=y+x;
                cout<<y<<".\n"; //menampilkan nomor urutan data, yang sebenarnya sama dengan (nomor array + 1)
                cout<<"Merk  : "<<merek[x]<<endl;
                cout<<"Ukuran : "<<ukuran[x]<<endl;
                cout<<"Resolusi : "<<resolusi[x]<<endl;
                cout<<"Harga : "<<harga[x]<<endl;
                cout<<"\n";
            }
        cout<<"========================\n\n\n";
    }
  
    //input merek
    void merektv()
    { //kamus lokal :
    
      //deskripsi :
      cout << "\nMasukkan merek TV : ";
      cin.ignore();
      getline(cin,searchmerek);
      cout << "" << endl;
    }

    int searchmerektv( int lenght, string searchkey) //length  batas array
    {
      //kamus lokal:
      int i;
      i = 0;
      //deskripsi :
      while(i < lenght){
        if(merek[i] == searchkey){
          cout << "Merek   : ";
          cout << merek[i] << endl;                          
          cout << "Ukuran : ";
          cout << ukuran[i] << endl;
          cout << "Resolusi : "; 
          cout << resolusi[i] << endl;
          cout << "Harga   : ";
          cout << harga[i] << endl;
          cout << "" << endl;
          return 1;
        }
        i++;
      };
      return -1; //jika data tidak ditemukan
    }

     //input merek
    void ukurantv()
    { //kamus lokal :
    
      //deskripsi :
      cout << "\nMasukkan ukuran TV : ";
      cin.ignore();
      getline(cin,searchukuran);
      cout << "" << endl;
    }

     int searchukurantv( int lenght, string searchkey)
    {
      //kamus lokal:
      int i;
      i = 0;
      //deskripsi :
      while(i < lenght){
        if(ukuran[i] == searchkey){
          cout << "Merek   : ";
          cout << merek[i] << endl;                          
          cout << "Ukuran : ";
          cout << ukuran[i] << endl;
          cout << "Resolusi : "; 
          cout << resolusi[i] << endl;
          cout << "Harga   : ";
          cout << harga[i] << endl;
          cout << "" << endl;
          return 1;
        }
        i++;
      };
      return -1; //jika data tidak ditemukan
    }

     //input merek
    void resolusitv()
    { //kamus lokal :
    
      //deskripsi :
      cout << "\nMasukkan resolusi TV : ";
      cin.ignore();
      getline(cin,searchresolusi);
      cout << "" << endl;
    }

    int searchresolusitv( int lenght, string searchkey)
    {
      //kamus lokal:
      int i;
      i = 0;
      //deskripsi :
      while(i < lenght){
        if(resolusi[i] == searchkey){
          cout << "Merek   : ";
          cout << merek[i] << endl;                          
          cout << "Ukuran : ";
          cout << ukuran[i] << endl;
          cout << "Resolusi : "; 
          cout << resolusi[i] << endl;
          cout << "Harga   : ";
          cout << harga[i] << endl;
          cout << "" << endl;
          return 1;
        }
        i++;
      };
      return -1; //jika data tidak ditemukan
    }

     //input merek
    void hargatv()
    { //kamus lokal :
    
      //deskripsi :
      cout << "\nMasukkan Harga TV : ";
      cin >> searchharga;
      cout << "" << endl;
    }
    
     int searchhargatv( int lenght, int searchkey)
    {
      //kamus lokal:
      int i;
      i = 0;
      //deskripsi :
      while(i < lenght){
        if(harga[i] == searchkey){
          cout << "Merek   : ";
          cout << merek[i] << endl;                          
          cout << "Ukuran : ";
          cout << ukuran[i] << endl;
          cout << "Resolusi : "; 
          cout << resolusi[i] << endl;
          cout << "Harga   : ";
          cout << harga[i] << endl;
          cout << "" << endl;
          return 1;
        }
        i++;
      };
      return -1; //jika data tidak ditemukan
    }

    void simpandata(int lenght){
      for(int i = 0;i < lenght; i++){
      ofstream file;
      file.open("data.txt", ios_base::app);

      file << i + 1 << endl;
      file << "Merek : " << merek[i] <<endl;
      file << "Ukuran : " << ukuran[i] << endl;
      file << "Resolusi : " << resolusi[i] << endl;
      file << "Harga : " << harga[i] << endl; 
      file.close();
    }
      cout << "simpan data berhasil" << endl;
    }


    void outputmenu(){
      switch(pilihan){
        case 1:
          jumdata = jumlahdata(lenght);
          input(jumdata);
          break;
        case 2: 
          output(jumdata);
          break;
        case 3: 
          cout << "Cari Tv berdasar : \n 1. Merek \n 2. Ukuran \n 3. Resolusi \n 4. Harga \n"  << endl; 
          cout << "Input no : ";
          cin >> inputcaritv; 
          switch(inputcaritv){
            case 1 : 
              merektv();
              result = searchmerektv(jumdata, searchmerek);
              if(result == -1){
                cout << "Merek Tv tidak ditemukan" << endl;
              }
             break; 
             case 2 :
              ukurantv();
              result = searchukurantv(jumdata, searchukuran);
              if(result == -1){
                cout << "Tv dengan ukuran tersebut tidak ditemukan" << endl;
              }
             break;
             case 3 :
              resolusitv();
              result = searchresolusitv(jumdata, searchresolusi);
              if(result == -1){
                cout << "Tv dengan resolusi tersebut tidak ditemukan" << endl;
              }
             break;
             case 4 :
              hargatv();
              result = searchhargatv(jumdata, searchharga);
              if(result == -1){
                cout << "Tv dengan harga tersebut tidak ditemukan" << endl;
              }
             break;
          } 
          break;
        case 4 :
          simpandata(jumdata);
          break;
        case 5 :
          cout << "TERIMA KASIH" << endl;
          exit(0);
          break;
        default : 
          cout << "Input salah" << endl;
      }
    }

   

};