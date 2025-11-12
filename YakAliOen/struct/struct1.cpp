#include <iostream>
#include <iomanip>
using namespace std;

struct warnet
{
    string nama;
    int jam;
    int menit;
    int detik;
    float harga;
};

float hitungHarga(int jam, int menit, int detik, float tarif);

int main()
{
    warnet w1;
    const float tarif = 130.0f;

    cout << "Selamat Datang di SCS Gaming" << endl;
    cout << "Nama: ";
    cin >> w1.nama;
    cout << "Jam: ";
    cin >> w1.jam;
    cout << "Menit: ";
    cin >> w1.menit;
    cout << "Detik: ";
    cin >> w1.detik;

    w1.harga = hitungHarga(w1.jam, w1.menit, w1.detik, tarif);

    cout << fixed << setprecision(2);
    cout << "Total Harga untuk " << w1.nama << ": Rp. " << w1.harga << endl;

    return 0;
}

float hitungHarga(int jam, int menit, int detik, float tarif_per_30_detik)
{
    int total_detik = jam * 3600 + menit * 60 + detik;
    float harga = (total_detik / 30.0f) * tarif_per_30_detik;
    return harga;
}