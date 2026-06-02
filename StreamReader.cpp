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
    
     
