#include "bst.h"


void createTree(adrNode &root) {
    root = nullptr;
}

adrNode createNode(int x) {
    adrNode p;

    p = new Node;
    p->value = x;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->value < root->value) {
        insertNode(root->left, p);
    } else {
        insertNode(root->right, p);
    }
}

adrNode searchNode(adrNode root, int x) {
    if (root == nullptr) {
        return nullptr;
    } else if (x < root->value) {
        return searchNode(root->left, x);
    } else if (x > root->value) {
        return searchNode(root->right, x);
    }

    return root;
}

void displayTree(adrNode root) {
    if (root != nullptr) {
        displayTree(root->left);
        cout << root->value << " ";
        displayTree(root->right);
    }
}

adrNode findMin(adrNode root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->left == nullptr) {
        return root;
    } else {
        return findMin(root->left);
    }
}

void deleteNode(adrNode &root, int x) {
    if (root == nullptr) {
        return;
    }

    if (x < root->value) {
        deleteNode(root->left, x);
    } else if (x > root->value) {
        deleteNode(root->right, x);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr;
        }
        else if (root->left == nullptr) {
            root = root->right;
        }
        else if (root->right == nullptr) {
            root = root->left;
        }
        else {
            adrNode temp = findMin(root->right);
            root->value = temp->value;
            deleteNode(root->right, temp->value);
        }
    }
}

void findPredecessor(adrNode root, adrNode& pre, int val) {
    if (root != nullptr) {
        if (root->value == val) {
            if (root->left != nullptr) {
                adrNode temp = root->left;
                while (temp->right != nullptr){
                    temp = temp->right;
                }
                pre = temp;
            }
        } else if (val < root->value) {
            findPredecessor(root->left, pre, val);
        } else {
            pre = root;
            findPredecessor(root->right, pre, val);
        }
    }
}

void findSuccessor(adrNode root, adrNode& suc, int val) {
    if (root != nullptr) {
        if (root->value == val) {
            if (root->right != nullptr) {
                adrNode temp = root->right;
                while (temp->left != nullptr){
                    temp = temp->left;
                }
                suc = temp;
            }
        } else if (val < root->value) {
            suc = root;
            findSuccessor(root->left, suc, val);
        } else {
            findSuccessor(root->right, suc, val);
        }
    }
}

void printPath(adrNode root, int x) {
    if (root == nullptr) {
        return;
    }

    cout << root->value;

    if (root->value != x) {
        cout << " -> ";
        if (x < root->value) {
            printPath(root->left, x);
        } else {
            printPath(root->right, x);
        }
    }
}

int heightTree(adrNode root) {
    if (root == nullptr) {
        return -1;
    } else {
        int kiri = heightTree(root->left);
        int kanan = heightTree(root->right);
        if (kiri > kanan){
            return kiri + 1;
        }else{
            return kanan + 1;
        }
    }
}

int depthNode(adrNode root, int x, int level) {
    if (root == nullptr) {
        return -1;
    }
    if (root->value == x) {
        return level;
    } else if (x < root->value) {
        return depthNode(root->left, x, level + 1);
    } else {
        return depthNode(root->right, x, level + 1);
    }
}

void printRange(adrNode root, int minVal, int maxVal) {
    if (root == nullptr) {
        return;
    }

    if (minVal < root->value) {
        printRange(root->left, minVal, maxVal);
    }

    if (root->value >= minVal && root->value <= maxVal) {
        cout << root->value << " ";
    }

    if (maxVal > root->value) {
        printRange(root->right, minVal, maxVal);
    }
}

//PENJELASAN

/*
#include "tree.h"

// =========================================================
// INISIALISASI TREE
// Tujuan: Memastikan pointer root menunjuk ke null (kosong)
// agar tidak menunjuk ke alamat memori acak (garbage).
// =========================================================
void createTree(adrNode &root) {
    root = nullptr;
}

// =========================================================
// MEMBUAT NODE BARU
// Algoritma:
// 1. Alokasi memori baru untuk node.
// 2. Isi data (value) dengan x.
// 3. Set pointer kiri dan kanan node baru ke nullptr (isolasi).
// =========================================================
adrNode createNode(int x) {
    adrNode p;

    p = new Node;
    p->value = x;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

// =========================================================
// MENYISIPKAN NODE (INSERT)
// Algoritma (Rekursif):
// 1. Jika tempat kosong, taruh node di situ.
// 2. Jika nilai baru < root, rekursif ke Kiri.
// 3. Jika nilai baru > root, rekursif ke Kanan.
// =========================================================
void insertNode(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p; // Basis: Tempat kosong ditemukan
    } else if (p->value < root->value) {
        insertNode(root->left, p); // Geser ke kiri
    } else {
        insertNode(root->right, p); // Geser ke kanan
    }
}

// =========================================================
// PENCARIAN DATA (SEARCH)
// Algoritma:
// Bandingkan x dengan root, lalu bergerak kiri/kanan sesuai
// aturan BST sampai ketemu atau sampai di ujung (nullptr).
// =========================================================
adrNode searchNode(adrNode root, int x) {
    if (root == nullptr) {
        return nullptr; // Data tidak ditemukan
    } else if (x < root->value) {
        return searchNode(root->left, x); // Cari di kiri
    } else if (x > root->value) {
        return searchNode(root->right, x); // Cari di kanan
    }

    return root; // Data ditemukan
}

// =========================================================
// MENAMPILKAN ISI TREE (IN-ORDER TRAVERSAL)
// Urutan: Kiri -> Cetak -> Kanan
// Efek: Menghasilkan output angka yang terurut (Ascending).
// =========================================================
void displayTree(adrNode root) {
    if (root != nullptr) {
        displayTree(root->left);       // Kunjungi anak kiri habis-habisan
        cout << root->value << " ";    // Cetak nilai
        displayTree(root->right);      // Kunjungi anak kanan
    }
}

// =========================================================
// MENCARI NILAI TERKECIL
// Algoritma:
// Terus bergerak ke KIRI sampai mentok (left == nullptr).
// =========================================================
adrNode findMin(adrNode root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->left == nullptr) {
        return root; // Ini node paling kiri (terkecil)
    } else {
        return findMin(root->left); // Lanjut ke kiri
    }
}

// =========================================================
// MENGHAPUS NODE (DELETE)
// Menangani 3 Kasus: Leaf, 1 Anak, 2 Anak.
// =========================================================
void deleteNode(adrNode &root, int x) {
    if (root == nullptr) {
        return; // Data tidak ada, selesai.
    }

    // 1. Cari posisi node yang mau dihapus
    if (x < root->value) {
        deleteNode(root->left, x);
    } else if (x > root->value) {
        deleteNode(root->right, x);
    } else {
        // Node ketemu! Eksekusi penghapusan berdasarkan kasus:

        // KASUS 1: Leaf Node (Tidak punya anak)
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr; // Langsung hapus pointer
        }
        // KASUS 2: Punya 1 Anak (Kanan saja)
        else if (root->left == nullptr) {
            root = root->right; // Bypass parent ke anak kanan
        }
        // KASUS 2: Punya 1 Anak (Kiri saja)
        else if (root->right == nullptr) {
            root = root->left; // Bypass parent ke anak kiri
        }
        // KASUS 3: Punya 2 Anak
        else {
            // Cari nilai terkecil di subtree KANAN (Successor)
            adrNode temp = findMin(root->right);
            // Salin nilainya ke node yang mau dihapus
            root->value = temp->value;
            // Hapus node duplikat (si successor asli) di bawah
            deleteNode(root->right, temp->value);
        }
    }
}

// =========================================================
// MENCARI PREDECESSOR
// Predecessor: Nilai terbesar yang lebih KECIL dari val.
// Logika: Cari Max di Subtree Kiri.
// =========================================================
void findPredecessor(adrNode root, adrNode& pre, int val) {
    if (root != nullptr) {
        if (root->value == val) {
            // Jika node ketemu, cari paling kanan dari anak kirinya
            if (root->left != nullptr) {
                adrNode temp = root->left;
                while (temp->right != nullptr){
                    temp = temp->right;
                }
                pre = temp;
            }
        } else if (val < root->value) {
            findPredecessor(root->left, pre, val);
        } else {
            // Jika kita belok kanan, simpan root ini sebagai kandidat predecessor
            pre = root;
            findPredecessor(root->right, pre, val);
        }
    }
}

// =========================================================
// MENCARI SUCCESSOR
// Successor: Nilai terkecil yang lebih BESAR dari val.
// Logika: Cari Min di Subtree Kanan.
// =========================================================
void findSuccessor(adrNode root, adrNode& suc, int val) {
    if (root != nullptr) {
        if (root->value == val) {
            // Jika node ketemu, cari paling kiri dari anak kanannya
            if (root->right != nullptr) {
                adrNode temp = root->right;
                while (temp->left != nullptr){
                    temp = temp->left;
                }
                suc = temp;
            }
        } else if (val < root->value) {
            // Jika kita belok kiri, simpan root ini sebagai kandidat successor
            suc = root;
            findSuccessor(root->left, suc, val);
        } else {
            findSuccessor(root->right, suc, val);
        }
    }
}

// =========================================================
// MENAMPILKAN JALUR (PATH)
// Algoritma: Cetak nilai saat ini, lalu lanjut telusuri
// ke arah target x sambil mencetak panah "->".
// =========================================================
void printPath(adrNode root, int x) {
    if (root == nullptr) {
        return;
    }

    cout << root->value; // Cetak node yang dilewati

    if (root->value != x) {
        cout << " -> ";
        if (x < root->value) {
            printPath(root->left, x);
        } else {
            printPath(root->right, x);
        }
    }
}

// =========================================================
// MENGHITUNG TINGGI POHON (HEIGHT)
// Algoritma: Post-Order Traversal.
// Bandingkan tinggi subtree kiri dan kanan, ambil Max + 1.
// =========================================================
int heightTree(adrNode root) {
    if (root == nullptr) {
        return -1; // Tinggi pohon kosong biasanya -1 atau 0
    } else {
        int u = heightTree(root->left);
        int v = heightTree(root->right);
        if (u > v){
            return u + 1;
        }else{
            return v + 1;
        }
    }
}

// =========================================================
// MENGHITUNG KEDALAMAN NODE (DEPTH)
// Menghitung seberapa jauh node x dari root (level ke-berapa).
// =========================================================
int depthNode(adrNode root, int x, int level) {
    if (root == nullptr) {
        return -1; // Tidak ketemu
    }
    if (root->value == x) {
        return level; // Ketemu, kembalikan level saat ini
    } else if (x < root->value) {
        return depthNode(root->left, x, level + 1); // Turun level (tambah 1)
    } else {
        return depthNode(root->right, x, level + 1);
    }
}

// =========================================================
// CETAK RANGE
// Hanya mencetak node yang nilainya >= minVal DAN <= maxVal.
// Menggunakan optimasi: tidak perlu cek cabang yang sudah pasti out of range.
// =========================================================
void printRange(adrNode root, int minVal, int maxVal) {
    if (root == nullptr) {
        return;
    }

    // Jika nilai root > minVal, berarti di kiri MUNGKIN ada angka yang masuk range
    if (minVal < root->value) {
        printRange(root->left, minVal, maxVal);
    }

    // Jika nilai root masuk dalam range, cetak
    if (root->value >= minVal && root->value <= maxVal) {
        cout << root->value << " ";
    }

    // Jika nilai root < maxVal, berarti di kanan MUNGKIN ada angka yang masuk range
    if (maxVal > root->value) {
        printRange(root->right, minVal, maxVal);
    }
}
*/
