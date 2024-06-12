#include <iostream>
using namespace std;

// Struktur node untuk menyimpan data mahasiswa
struct Node {
    string nama_030;
    int usia_030;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = NULL;
    }

    // Fungsi untuk menambahkan node di depan linked list
    void tambahDepan(string nama_030, int usia_030) {
        Node* newNode = new Node;
        newNode->nama_030 = nama_030;
        newNode->usia_030 = usia_030;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang linked list
    void tambahBelakang(string nama_030, int usia_030) {
        Node* newNode = new Node;
        newNode->nama_030 = nama_030;
        newNode->usia_030 = usia_030;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menampilkan isi linked list
    void tampilkan() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Nama: " << temp->nama_030 << ", Usia: " << temp->usia_030 << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus node dari linked list
    void hapus(string nama_030) {
        Node* temp = head;
        Node* prev = NULL;

        // Cari node yang akan dihapus
        while (temp != NULL && temp->nama_030 != nama_030) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == NULL) {
            cout << "Data dengan nama " << nama_030 << " tidak ditemukan." << endl;
            return;
        }

        // Jika node yang akan dihapus adalah head
        if (prev == NULL) {
            head = temp->next;
            delete temp;
            cout << "Data dengan nama " << nama_030 << " berhasil dihapus." << endl;
            return;
        }

        // Jika node yang akan dihapus bukan head
        prev->next = temp->next;
        delete temp;
        cout << "Data dengan nama " << nama_030 << " berhasil dihapus." << endl;
    }
    
    // Fungsi untuk menyisipkan node di antara dua mahasiswa berdasarkan nama
    void sisipDiAntara(string nama_awal, string nama_akhir, string nama_030, int usia_030) {
        Node* newNode = new Node;
        newNode->nama_030 = nama_030;
        newNode->usia_030 = usia_030;

        Node* temp = head;
        Node* prev = NULL;

        // Cari node dengan nama_awal
        while (temp != NULL && temp->nama_030 != nama_awal) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == NULL) {
            cout << "Data dengan nama " << nama_awal << " tidak ditemukan." << endl;
            return;
        }

        // Jika node dengan nama_awal ditemukan
        prev = temp;
        temp = temp->next;

        // Cari node dengan nama_akhir
        while (temp != NULL && temp->nama_030 != nama_akhir) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == NULL) {
            cout << "Data dengan nama " << nama_akhir << " tidak ditemukan." << endl;
            return;
        }

        // Sisipkan newNode di antara node dengan nama_awal dan nama_akhir
        prev->next = newNode;
        newNode->next = temp;
    }
    
     // Fungsi untuk menambahkan node di awal linked list
    void tambahDiAwal(string nama_030, int usia_030) {
        Node* newNode = new Node;
        newNode->nama_030 = nama_030;
        newNode->usia_030 = usia_030;
        newNode->next = head;
        head = newNode;
    }
    
   // Fungsi untuk mengubah data mahasiswa berdasarkan nama
    void ubahData(string nama_lama, string nama_baru, int usia_baru) {
        Node* temp = head;

        // Cari node dengan nama_lama
        while (temp != NULL && temp->nama_030 != nama_lama) {
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == NULL) {
            cout << "Data dengan nama " << nama_lama << " tidak ditemukan." << endl;
            return;
        }

        // Ubah nama dan usia node menjadi nama_baru dan usia_baru
        temp->nama_030 = nama_baru;
        temp->usia_030 = usia_baru;
        cout << "Data mahasiswa berhasil diubah." << endl;
    }
};

int main() {
    LinkedList list;
    string nama_030;
    int usia_030;


	// Memasukkan data pertama dari pengguna
    cout << "Masukkan nama anda: ";
    getline(cin, nama_030);
    cout << "Masukkan usia anda: ";
    cin >> usia_030;
    cin.ignore(); // Membersihkan buffer

    // Menambahkan data pertama ke linked list
    list.tambahDepan(nama_030, usia_030);

    // Memasukkan 6 data lagi dari pengguna
    for (int i = 0; i < 7; ++i) {
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, nama_030);
        cout << "Masukkan usia mahasiswa ke-" << i+1 << ": ";
        cin >> usia_030;
        cin.ignore(); // Membersihkan buffer

        // Menambahkan data ke linked list
        list.tambahBelakang(nama_030, usia_030);
    }

    // Menampilkan isi linked list
    cout << "\nData Mahasiswa:\n";
    list.tampilkan();

    // Meminta pengguna untuk menghapus data
    cout << "\nMasukkan nama mahasiswa yang ingin dihapus: ";
    getline(cin, nama_030);

    // Menghapus data dari linked list
    list.hapus(nama_030);
    

    // Menampilkan isi linked list setelah penghapusan
    cout << "\nData Mahasiswa setelah penghapusan:\n";
    list.tampilkan();
    
    // Meminta pengguna untuk menyisipkan data di antara dua nama mahasiswa
    string nama_awal, nama_akhir;
    cout << "\nMasukkan nama mahasiswa awal: ";
    getline(cin, nama_awal);
    cout << "Masukkan nama mahasiswa akhir: ";
    getline(cin, nama_akhir);
    cout << "Masukkan nama mahasiswa yang ingin disisipkan: ";
    getline(cin, nama_030);
    cout << "Masukkan usia mahasiswa yang ingin disisipkan: ";
    cin >> usia_030;
    cin.ignore(); 

    // Menyisipkan data di antara dua nama mahasiswa
    list.sisipDiAntara(nama_awal, nama_akhir, nama_030, usia_030);
      // Menampilkan isi linked list setelah penyisipan
    cout << "\nData Mahasiswa setelah penyisipan:\n";
    list.tampilkan();
    
    
    // Memasukkan data pertama dari pengguna
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, nama_030);
    cout << "Masukkan usia mahasiswa: ";
    cin >> usia_030;
    cin.ignore(); 

    // Menambahkan data pertama ke linked list
    list.tambahDiAwal(nama_030, usia_030);
      cout << "\nData Mahasiswa setelah ditambah:\n";
    list.tampilkan();
    
 	// Meminta pengguna untuk mengubah data mahasiswa berdasarkan nama
    string nama_lama;
    int usia_baru;
    cout << "\nMasukkan nama mahasiswa yang ingin diubah: ";
    getline(cin, nama_lama);
    cout << "Masukkan nama baru mahasiswa: ";
    getline(cin, nama_030);
    cout << "Masukkan usia baru mahasiswa: ";
    cin >> usia_baru;

    // Mengubah data mahasiswa berdasarkan nama
    list.ubahData(nama_lama, nama_030, usia_baru);

    // Menampilkan isi linked list setelah pengubahan
    cout << "\nSeluruh Data Mahasiswa:\n";
    list.tampilkan();
    
    

    cout << "" << endl;
    cout << "" << endl;
    return 0;
}
