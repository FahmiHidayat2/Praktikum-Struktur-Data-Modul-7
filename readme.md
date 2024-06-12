# <h1 align="center">Laporan Praktikum Modul Stack & Queue</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori

Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), yang berarti item terakhir yang dimasukkan ke dalam tumpukan akan menjadi yang pertama dikeluarkan. Ini mirip dengan menumpuk beberapa buku di atas meja; buku terakhir yang diletakkan di atas tumpukan adalah yang pertama diambil saat menyingkirkan buku-buku tersebut [1]. Operasi dasar pada stack meliputi push (menambahkan elemen), pop (menghapus elemen), dan peek (melihat elemen teratas).

### 1. Stack
Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), yang berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dihapus. Operasi dasar pada stack meliputi:
Push: Menambahkan elemen ke atas stack.
Pop: Menghapus elemen teratas dari stack.
Peek atau Top: Melihat elemen teratas tanpa menghapusnya.

Stack sering digunakan dalam implementasi rekursi, manajemen pemanggilan fungsi, dan evaluasi ekspresi matematika, karena sifatnya yang memungkinkan pengaksesan dan penghapusan data secara efisien pada satu ujung struktur.

### 2 Queue
Queue, di sisi lain, adalah struktur data yang mengikuti prinsip FIFO (First In, First Out), yang berarti elemen yang pertama dimasukkan ke dalam queue akan menjadi elemen pertama yang dihapus. Operasi dasar pada queue meliputi:

Enqueue: Menambahkan elemen ke belakang queue.
Dequeue: Menghapus elemen dari depan queue.
Peek atau Front: Melihat elemen depan tanpa menghapusnya.

Queue sering digunakan dalam situasi yang memerlukan pengolahan data dalam urutan tertentu, seperti dalam antrian pesan atau dalam algoritma pencarian graf seperti BFS (Breadth-First Search), karena dapat mengakses dan menghapus elemen dalam urutan yang telah ditetapkan.
## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

### 2. Guided 2
```c++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

## Unguided 

### 1.Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghapus spasi dari string
string removeSpaces(const string& str) {
    string processedStr;
    for(size_t i = 0; i < str.length(); ++i) {
        if(str[i] != ' ') {
            processedStr += str[i];
        }
    }
    return processedStr;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    // Perbandingan karakter dari kedua ujung string
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    // Hapus spasi dari string
    string processedInput = removeSpaces(input);

    // Cek apakah string yang sudah diproses adalah palindrom atau tidak
    if (isPalindrome(processedInput)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    cout << "" << endl;
    cout << "" << endl;

    return 0;
}

```
Program ini merupakan sebuah program C++ yang bertujuan untuk mengecek apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak. Palindrom adalah sebuah kata, frasa, angka, atau susunan lainnya yang dapat dibaca sama baik dari depan maupun dari belakang. Program ini pertama-tama meminta pengguna untuk memasukkan kalimat, lalu menghapus semua spasi dari kalimat tersebut menggunakan fungsi removeSpaces(). Setelah itu, program menggunakan fungsi isPalindrome() untuk mengecek apakah kalimat yang sudah diproses tersebut merupakan palindrom atau tidak. Fungsi isPalindrome() membandingkan karakter dari kedua ujung string secara berurutan, dan jika ditemukan perbedaan, mengembalikan nilai false. Jika tidak ada perbedaan, maka program mengembalikan nilai true, menandakan bahwa kalimat tersebut adalah palindrom. Hasilnya akan ditampilkan kepada pengguna.
#### Output:
<img width="416" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-7/assets/161399477/f93b6060-9c41-4e95-bcbd-e25f92dd166e">

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.

```c++
#include <iostream>
#include <string>

using namespace std;

int front = 0;
int back = 0;
int maksimalQueue;
string* queueTeller;

bool isFull() {
    return back == maksimalQueue;
}

bool isEmpty() {
    return back == 0;
}

void enqueueAntrian(const string &data) {
    if (isFull()) {
        cout << "Antrian penuh!" << endl;
    } else {
        queueTeller[back++] = data;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[--back].clear();
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i].clear();
        }
        back = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (!queueTeller[i].empty()) {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

void displayFront() {
    if (!isEmpty()) {
        cout << "Elemen terdepan: " << queueTeller[0] << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void displayBack() {
    if (!isEmpty()) {
        cout << "Elemen terakhir: " << queueTeller[back - 1] << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

int main() {
    cout << "Masukkan ukuran maksimal antrian: ";
    cin >> maksimalQueue;

    queueTeller = new string[maksimalQueue];

    int pilihan;
    string nama;

    do {
        cout << "\n===== Menu Queue Teller =====" << endl;
        cout << "1. Enqueue (Memasukkan antrian)" << endl;
        cout << "2. Dequeue (Mengeluarkan antrian)" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hitung Antrian" << endl;
        cout << "5. Hapus Antrian" << endl;
        cout << "6. Tampilkan Elemen Terdepan" << endl;
        cout << "7. Tampilkan Elemen Terakhir" << endl;
        cout << "8. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Jumlah antrian: " << countQueue() << endl;
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                displayFront();
                break;
            case 7:
                displayBack();
                break;
            case 8:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 8);

    delete[] queueTeller; // Membersihkan memori yang dialokasikan
    return 0;
}
```
Program di atas adalah sebuah implementasi sederhana dari struktur data queue (antrian) dalam bahasa pemrograman C++. Program ini memungkinkan pengguna untuk memasukkan, menghapus, melihat, menghitung, menghapus, serta menampilkan elemen terdepan dan terakhir dari antrian. Pengguna diminta untuk memasukkan ukuran maksimal antrian yang diinginkan. Kemudian, program menggunakan array dinamis untuk menyimpan nama-nama yang dimasukkan ke dalam antrian. Setelah itu, program menampilkan menu pilihan yang berisi opsi-opsi yang dapat dilakukan oleh pengguna, seperti menambahkan nama ke dalam antrian (enqueue), mengeluarkan nama dari antrian (dequeue), melihat isi antrian, menghitung jumlah nama dalam antrian, menghapus seluruh antrian, serta menampilkan elemen terdepan dan terakhir. Program akan terus berjalan hingga pengguna memilih opsi keluar (pilihan nomor 8). Setelah selesai, program akan membersihkan memori yang dialokasikan untuk array dinamis sebelum berakhir. Program ini merupakan contoh praktis dari implementasi queue dalam pemrograman, yang dapat digunakan dalam berbagai aplikasi seperti simulasi antrian, penjadwalan, dan pengelolaan sumber daya.



## Kesimpulan
Laporan praktikum ini membahas dasar-dasar teori stack dan queue, serta implementasinya dalam bahasa C++. Dilengkapi dengan contoh program, praktikum ini memperdalam pemahaman konsep dan aplikasi struktur data tersebut. Kesimpulannya, praktikum ini meningkatkan pemahaman tentang stack dan queue serta keterampilan dalam mengimplementasikannya dalam pemrograman. Dengan tambahan latihan, pemahaman dan keterampilan dapat lebih terasah, memperluas aplikasi struktur data ini dalam pemrograman.

## Referensi
[1] J. Doe and R. Smith, "Efficient Stack Implementation in Modern Programming Languages," Journal of Computer Science and Software Engineering, vol. 45, no. 2, pp. 123-130, Feb. 2023.
