#include <iostream>    
#include <fstream>     
#include <array>      
#include <string>     
#include <stdexcept>   

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    TokoElektronik() {
        etalase = {"Smartphone Samsung", "Laptop Lenovo", "Smart TV LG"};
    }

    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (out_of_range& e) {
            // Melemparkan pesan error kustom (Syarat 2)
            throw runtime_error("Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!");
        }
    }
};

void tampilkanDaftarGudang() {
    string baris;
    ifstream infile;
    infile.open("gudang.txt", ios::in);
    
    cout << endl << "=== DAFTAR BARANG DI GUDANG ===" << endl;
    if (infile.is_open()) {
        bool adaData = false;
        while (getline(infile, baris)) {
            cout << baris << endl;
            adaData = true;
        }
        if (!adaData) cout << "[Gudang kosong]" << endl;
        infile.close();
    } else {
        cout << "[Gudang kosong atau belum ada data]" << endl;
    }
}

void tambahBarangGudang() {
    string id, nama, harga;
    ofstream outfile;
    outfile.open("gudang.txt", ios::app);

    cout << endl << "--- Tambah Barang ---" << endl;
    cout << "Masukkan ID Barang: "; cin >> id;
    cout << "Masukkan Nama Barang: "; cin.ignore(); getline(cin, nama);
    cout << "Masukkan Harga Barang: "; cin >> harga;

    outfile << id << "," << nama << "," << harga << endl;
    outfile.close();
    cout << "Berhasil ditambahkan!" << endl;
}



void kelolaDataGudang(bool isDelete) {
    string targetId, id, nama, harga;
    string isiFileBaru = "";
    bool ditemukan = false;
    
    ifstream infile;
    infile.open("gudang.txt", ios::in);

    cout << endl << (isDelete ? "--- Hapus Barang ---" : "--- Update Barang ---") << endl;
    cout << "Masukkan ID Barang target: "; cin >> targetId;

    if (infile.is_open()) {
        while (getline(infile, id, ',')) {
            getline(infile, nama, ',');
            getline(infile, harga);

            if (id == targetId) {
                ditemukan = true;
                if (!isDelete) { 
                    cout << "Masukkan Nama Baru: "; cin.ignore(); getline(cin, nama);
                    cout << "Masukkan Harga Baru: "; cin >> harga;
                    isiFileBaru += id + "," + nama + "," + harga + "\n";
                }
                
            } else {
                isiFileBaru += id + "," + nama + "," + harga + "\n";
            }
        }
        infile.close();
        
        
        ofstream outfile;
        outfile.open("gudang.txt", ios::out);
        outfile << isiFileBaru;
        outfile.close();

        if (ditemukan) cout << "Operasi berhasil dieksekusi!" << endl;
        else cout << "ID Barang tidak ditemukan." << endl;
    } else {
        cout << "Gudang belum memiliki data!" << endl;
    }
}

void jalankanSimulasiEtalase(TokoElektronik& toko) {
    cout << endl << "=== SIMULASI EXCEPTION HANDLING ===" << endl;
    
    cout << "Skenario 1 (Indeks 1):" << endl;
    try {
        cout << "Sukses mengambil: " << toko.ambilProduk(1) << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << endl << "Skenario 2 (Indeks 5):" << endl;
    try {
        cout << "Sukses mengambil: " << toko.ambilProduk(5) << endl;
    } catch (exception& e) {
        cout << "Tertangkap Error -> " << e.what() << endl;
    }
}

int main() {
    TokoElektronik gibranJaya;
    int pilihanMenu;

    do {
        tampilkanDaftarGudang();
        cout << endl << "1. Tambah (Create)\n2. Update\n3. Hapus (Delete)\n4. Simulasi Etalase\n5. Keluar\nPilih: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: tambahBarangGudang(); break;
            case 2: kelolaDataGudang(false); break;
            case 3: kelolaDataGudang(true); break;
            case 4: jalankanSimulasiEtalase(gibranJaya); break;
            case 5: cout << "Keluar dari sistem." << endl; break;
            default: 
                cout << "Tidak valid!" << endl; 
                cin.clear(); cin.ignore(10000, '\n');
        }
    } while (pilihanMenu != 5);

    return 0;
}