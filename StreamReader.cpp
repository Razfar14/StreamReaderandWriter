#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //deklarasi variabel baris untuk menyipan data string
    string baris;

    //membuka file dalam mode menulis
    ofstream outfile;
   
    //menunjuk ke sebuah nama file
    outfile.open("contohfile.txt");

    cout << ">= Menulis file, \'q\'untuk keluar " <<endl;

    //unlimited loop untuk menulis file
    while(true){

        cout << "- ";
        //medapat setiap karakter dalam satu baris
        getline(cin, baris);
        //kondisi false jika baris hanya berisi karakter q
        if (baris == "q"){break;}
        //menulis dan memasukkan nilai dari variable baris ke dalam file 
        outfile << baris << endl;
    }
    //menutup file setelah penulisan selesai
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;
    //menunjuk ke sebuah nama file
    infile.open("contohfile.txt");

    cout << endl << ">= Membuka & membaca file " <<endl;
    //kondisi jika file ada
    if (infile.is_open()){

        //perulangan untuk ,e,umculkan setia[ baris
        while (getline(infile, baris)){
            //menampilkan isi file
            cout << baris << endl;
        }

        //menutup file setelah selesai membaca
        infile.close();
    }
