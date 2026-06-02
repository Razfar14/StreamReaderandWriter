#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //deklarasi variabel baris untuk menyipan data string & Nama file
    string baris, NamaFile;

    //membuka file dalam mode menulis
    ofstream outfile;
    //menunujuk ke sebuah nama fiule dengan ekstensi txt
    outfile.open(NamaFile + ".txt", ios::out);

    cout << ">= Menulis file, \'q\'untuk keluar " <<endl;

    //looping untuk menulis isi file
    while(true){

        cout << "- ";
        //medapat setiap karakter dalam satu baris
        getline(cin, baris);
        //kondisi false jika baris hanya berisi karakter q
        if (baris == "q"){break;}
        //menulis dan memasukkan nilai dari variable baris ke dalam file 
        outfile << baris << endl;
    }

    //menutup file apabila penulisan selesai di tulis
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;

    //menunjuk ke sebuah nama file dengan ekstensi txt
    infile.open(NamaFile + ".txt", ios::in);

    cout << endl << ">= Membuka & membaca file " <<endl;
    //kondisi jika file ada
    if (infile.is_open()){

        //perulangan untuk menampilkan setiap baris
        while (getline(infile, baris)){
            cout << baris << endl;
        }

        //menutup file setelah selesai membaca
        infile.close();
    }
    //kondisi jika file tidak ada
    else {
        cout << "File tidak ditemukan!" << endl;
        return 0;
    }
}