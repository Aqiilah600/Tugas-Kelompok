#include <iostream>
#include <string>
using namespace std;

struct LayananSalon {
  string namaLayanan;
  int harga;
  int stok;
  LayananSalon* next;
};

class Salon {
private:
  LayananSalon* head;
public:
  Salon() : head(nullptr) {}

  void tambahLayanan(const string& nama, int harga, int stok) {
    LayananSalon* baru = new LayananSalon{nama, harga, stok, nullptr};
    if (!head) {
      head = baru;
    } else {
      LayananSalon* temp = head;
      while (temp->next) temp = temp->next;
      temp->next = baru;
    }
    cout << "Layanan berhasil ditambahkan.\n";
  }

  void tampilkanLayanan() {
    if (!head) {
      cout << "Belum ada layanan.\n";
      return;
    }
    LayananSalon* temp = head;
    cout << "Daftar Layanan Salon:\n";
    while (temp) {
      cout << "- " << temp->namaLayanan
         << " | Harga: Rp" << temp->harga
         << " | Stok: " << temp->stok << endl;
      temp = temp->next;
    }
  }

  void pesanLayanan(const string& nama) {
    LayananSalon* temp = head;
    while (temp) {
      if (temp->namaLayanan == nama) {
        if (temp->stok > 0) {
          temp->stok--;
          cout << "Layanan " << nama << " berhasil dipesan. Sisa stok: " << temp->stok << endl;
        } else {
          cout << "Stok layanan " << nama << " habis.\n";
        }
        return;
      }
      temp = temp->next;
    }
    cout << "Layanan tidak ditemukan.\n";
  }

  ~Salon() {
    while (head) {
      LayananSalon* temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  Salon salon;
  int pilihan;
  do {
    cout << "\n=== Sistem Salon ===\n";
    cout << "1. Tambah Layanan\n";
    cout << "2. Tampilkan Layanan\n";
    cout << "3. Pesan Layanan\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();
    if (pilihan == 1) {
      string nama;
      int harga, stok;
      cout << "Nama layanan: ";
      getline(cin, nama);
      cout << "Harga: ";
      cin >> harga;
      cout << "Stok: ";
      cin >> stok;
      salon.tambahLayanan(nama, harga, stok);
    } else if (pilihan == 2) {
      salon.tampilkanLayanan();
    } else if (pilihan == 3) {
      string nama;
      cout << "Nama layanan yang ingin dipesan: ";
      cin.ignore();
      getline(cin, nama);
      salon.pesanLayanan(nama);
    }
  } while (pilihan != 0);
  return 0;
}