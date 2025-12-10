#include "bst.h"
#include <iostream>

using namespace std;

int main() {
    adrNode root;
    createTree(root);

    int pilihan = -1; // Inisialisasi agar masuk loop
    int val, L, R;
    adrNode tempNode = nullptr;
    adrNode pre = nullptr, suc = nullptr;

    cout << "=== SISTEM MONITORING NILAI SENSOR ===" << endl;

    // Loop menu tanpa break
    while (pilihan != 0) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Sensor (Insert)" << endl;
        cout << "2. Hapus Data Sensor (Delete)" << endl;
        cout << "3. Tampilkan Semua Data (Ascending)" << endl;
        cout << "4. Cari Predecessor & Successor" << endl;
        cout << "5. Tampilkan Jalur ke Data (Path)" << endl;
        cout << "6. Info Tree (Height & Node Depth)" << endl;
        cout << "7. Tampilkan Data Range [L, R]" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int juminput;
            cout << "Masukan jumlah input n : ";
            cin >> juminput;
            for(int i = 0 ; i < juminput; i++){
                cout << "Masukkan nilai intensitas sensor ke " << i+1 << " : ";
                cin >> val;
                insertNode(root, createNode(val)); // atau insertnode(root,p);
            }
            cout << "Data berhasil disimpan." << endl;

        } else if (pilihan == 2) {
            cout << "Masukkan nilai yang akan dihapus: ";
            cin >> val;
            if (searchNode(root, val) != nullptr) {
                deleteNode(root, val);
                cout << "Data berhasil dihapus." << endl;
            } else {
                cout << "Data tidak ditemukan!" << endl;
            }

        } else if (pilihan == 3) {
            cout << "Data Sensor (Urut): ";
            displayTree(root); // secara ascending
            cout << endl;

        } else if (pilihan == 4) {
            cout << "Masukkan nilai acuan: ";
            cin >> val;

            // Reset pointer
            pre = nullptr;
            suc = nullptr;

            // Cek apakah data ada di tree untuk kasus spesifik
            if (searchNode(root, val) != nullptr) {
                findPredecessor(root, pre, val);
                findSuccessor(root, suc, val);

                cout << "Predecessor (Nilai < " << val << " terdekat): ";
                if (pre != nullptr){
                    cout << pre->value;
                }else{
                    cout << "-";
                }
                cout << endl;

                cout << "Successor   (Nilai > " << val << " terdekat): ";
                if (suc != nullptr){
                    cout << suc->value;
                }else{
                    cout << "-";
                }
                cout << endl;
            } else {
                cout << "Nilai acuan harus ada di dalam tree untuk fitur ini." << endl;
            }

        } else if (pilihan == 5) {
            cout << "Masukkan nilai yang dicari jalurnya: ";
            cin >> val;
            if (searchNode(root, val) != nullptr) {
                cout << "Jalur: ";
                printPath(root, val);
                cout << endl;
            } else {
                cout << "Data tidak ditemukan." << endl;
            }

        } else if (pilihan == 6) {
            cout << "Tinggi Pohon Sensor: " << heightTree(root) << endl;

            cout << "Cek kedalaman node (masukkan nilai): ";
            cin >> val;
            int d = depthNode(root, val, 0);
            if (d != -1) {
                cout << "Kedalaman node " << val << " adalah: " << d << endl;
            } else {
                cout << "Node tidak ditemukan." << endl;
            }

        } else if (pilihan == 7) {
            cout << "Masukkan Batas Bawah (L): ";
            cin >> L;
            cout << "Masukkan Batas Atas (R): ";
            cin >> R;
            cout << "Data dalam range [" << L << ", " << R << "]: ";
            printRange(root, L, R);
            cout << endl;

        } else if (pilihan == 0) {
            cout << "Keluar dari sistem monitoring..." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
