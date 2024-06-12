#include <iostream>
using namespace std;

class Node {
public:
    string namaProduk_030; // Nama produk
    int harga_030; // Harga produk
    Node* prev_030;
    Node* next_030;
};

class DoublyLinkedList {
public:
    Node* head_030;
    Node* tail_030;

    DoublyLinkedList() {
        head_030 = NULL;
        tail_030 = NULL;
    }

    // Fungsi untuk menambahkan produk ke awal daftar
    void tambah(string namaProduk_030, int harga_030) {
        Node* newNode_030 = new Node;
        newNode_030->namaProduk_030 = namaProduk_030;
        newNode_030->harga_030 = harga_030;
        newNode_030->prev_030 = NULL;
        newNode_030->next_030 = head_030;
        if (head_030 != NULL) {
            head_030->prev_030 = newNode_030;
        } else {
            tail_030 = newNode_030;
        }
        head_030 = newNode_030;
    }

    // Fungsi untuk menambahkan produk setelah produk tertentu
    void tambahSetelah(string namaProduk_030, int harga_030, string namaProdukSebelumnya_030) {
        Node* current_030 = head_030;
        while (current_030 != NULL && current_030->namaProduk_030 != namaProdukSebelumnya_030) {
            current_030 = current_030->next_030;
        }
        if (current_030 != NULL) {
            Node* newNode_030 = new Node;
            newNode_030->namaProduk_030 = namaProduk_030;
            newNode_030->harga_030 = harga_030;
            newNode_030->prev_030 = current_030;
            newNode_030->next_030 = current_030->next_030;
            if (current_030->next_030 != NULL) {
                current_030->next_030->prev_030 = newNode_030;
            } else {
                tail_030 = newNode_030;
            }
            current_030->next_030 = newNode_030;
        } else {
            cout << "Produk sebelumnya tidak ditemukan" << endl;
        }
    }

    // Fungsi untuk menghapus produk dari awal daftar
    void hapus() {
        if (head_030 == NULL) {
            return;
        }
        Node* temp_030 = head_030;
        head_030 = head_030->next_030;
        if (head_030 != NULL) {
            head_030->prev_030 = NULL;
        } else {
            tail_030 = NULL;
        }
        delete temp_030;
    }

    // Fungsi untuk mengupdate nama produk dan harga berdasarkan nama produk lama
    bool update(string namaProdukLama_030, string namaProdukBaru_030, int hargaBaru_030) {
        Node* current_030 = head_030;
        while (current_030 != NULL) {
            if (current_030->namaProduk_030 == namaProdukLama_030) {
                current_030->namaProduk_030 = namaProdukBaru_030;
                current_030->harga_030 = hargaBaru_030;
                return true;
            }
            current_030 = current_030->next_030;
        }
        return false;
    }

    // Fungsi untuk menghapus produk berdasarkan nama produk
    void hapusBerdasarkanNama(string namaProduk_030) {
        Node* current_030 = head_030;
        while (current_030 != NULL && current_030->namaProduk_030 != namaProduk_030) {
            current_030 = current_030->next_030;
        }
        if (current_030 != NULL) {
            if (current_030->prev_030 != NULL) {
                current_030->prev_030->next_030 = current_030->next_030;
            } else {
                head_030 = current_030->next_030;
            }
            if (current_030->next_030 != NULL) {
                current_030->next_030->prev_030 = current_030->prev_030;
            } else {
                tail_030 = current_030->prev_030;
            }
            delete current_030;
        } else {
            cout << "Produk tidak ditemukan" << endl;
        }
    }

    // Fungsi untuk menghapus semua produk dari daftar
    void hapusSemua() {
        Node* current_030 = head_030;
        while (current_030 != NULL) {
            Node* temp_030 = current_030;
            current_030 = current_030->next_030;
            delete temp_030;
        }
        head_030 = NULL;
        tail_030 = NULL;
    }

    // Fungsi untuk menampilkan daftar produk beserta harga
    void tampilkan() {
        Node* current_030 = head_030;
        cout << "Nama Produk\tHarga" << endl;
        while (current_030 != NULL) {
            cout << current_030->namaProduk_030 << "\t" << current_030->harga_030 << endl;
            current_030 = current_030->next_030;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list_030;

    // Menambahkan produk awal ke daftar
    list_030.tambah("Originote", 60000);
    list_030.tambah("Somethinc", 150000);
    list_030.tambah("Skintific", 100000);
    list_030.tambah("Wardah  ", 50000);
    list_030.tambah("Hanasui ", 30000);

    // Menampilkan produk awal
    cout << "Daftar Produk Awal:" << endl;
    list_030.tampilkan();

    // Menu operasi
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int pilihan_030;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan_030;

        switch (pilihan_030) {
            case 1: {
                string namaProduk_030;
                int harga_030;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk_030;
                cout << "Masukkan harga: ";
                cin >> harga_030;
                list_030.tambah(namaProduk_030, harga_030);
                break;
            }
            case 2: {
                string namaProduk_030;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk_030;
                list_030.hapusBerdasarkanNama(namaProduk_030);
                break;
            }
            case 3: {
                string namaProdukLama_030, namaProdukBaru_030;
                int hargaBaru_030;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProdukLama_030;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProdukBaru_030;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru_030;
                bool berhasil_030 = list_030.update(namaProdukLama_030, namaProdukBaru_030, hargaBaru_030);
                if (!berhasil_030) {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk_030, namaProdukSebelumnya_030;
                int harga_030;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> namaProduk_030;
                cout << "Masukkan harga: ";
                cin >> harga_030;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> namaProdukSebelumnya_030;
                list_030.tambahSetelah(namaProduk_030, harga_030, namaProdukSebelumnya_030);
                break;
            }
            case 5: {
                // Case 5: Hapus Data Urutan Tertentu
                break;
            }
            case 6: {
                list_030.hapusSemua();
                break;
            }
            case 7: {
                list_030.tampilkan();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    
    cout << "" << endl;
    cout << "" << endl;

    return 0;
}

