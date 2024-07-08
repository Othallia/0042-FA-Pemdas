#include <iostream> 
using namespace std;
class MasukUniversitas {
    // isi access modifier disini 
protected: 
    int uangPendaftaran;
    // isi daftar variable yang dibutuhkan di bawah ini 
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;

public:
    MasukUniversitas() {
        uangPendaftaran = 0;
        // isi nilai default variable yang dibutuhkan di bawah ini 
            uangSemesterPertama = 0;
            uangBangunan = 0;
            totalBiaya = 0;  
    }

    virtual void namaJalurMasuk() { return; }
    // isi disini dengan fungsi virtual yang dibutuhkan 
    virtual string namaJalurMasuk() const = 0;

    void setUangPendaftaran(int uP) {uangPendaftaran = uP;
        this->uangPendaftaran = uP;
    }
    float setUangPendaftaran() {
        return uangPendaftaran;
    }

    // isi setter dan getter variable yang dibutuhkan di bawah ini 
    void setUangSemesterPertama(int usp) {uangSemesterPertama = usp;
        this->uangSemesterPertama = usp;
    }

    float setUangSemesterPertama() const { return uangSemesterPertama; }

    void setUangBangunan(int ub) { uangBangunan = ub;
        this->uangBangunan = ub;
    }
    float getUangBangunan() const { return uangBangunan; }

    void setTotalBiaya(int tb) { totalBiaya = tb;
        this->totalBiaya = tb;
    }
    float getTotalBiaya() const { return totalBiaya; }

    virtual void input() = 0;
    virtual void hitungTotalBiaya() = 0;
    virtual void tampilkanTotalBiaya() const = 0;
   
};

class SNBT: public MasukUniversitas{
    // isi disini untuk melengkapi class SNBT 
    public:
        string namaJalurMasuk() const override {
            return "SNBT";
        }

        void input() override {
            cout << "Masukkan uang pendaftaran: ";
            cin >> uangPendaftaran;
            cout << "Masukkan uang semester pertama: ";
            cin >> uangSemesterPertama;
            cout << "Masukkan uang bangunan: ";
            cin >> uangBangunan;
        }

        void hitungTotalBiaya() override {
            totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
        }

        void tampilkanTotalBiaya() const override {
            cout << "Total Biaya (SNBT): " << totalBiaya << endl;
            if (totalBiaya > 10000000) {
                cout << "Kategori: Mahal" << endl;
            }
            else if (totalBiaya > 5000000) {
                cout << "Kategori: Sedang" << endl;
            }
            else {
                cout << "Kategori: Murah" << endl;
            }
            cout << "Rekomendasi:" << endl;
            cout << "Tidak Direkomendasikan" << endl;
        }
};

class SNBP : public MasukUniversitas {
    // isi disini untuk melengkapi class SNBP 
public:
    string namaJalurMasuk() const override {
        return "SNBP";
    }

    void input() override {
        cout << "Masukkan uang pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: ";
        cin >> uangSemesterPertama;
    }
    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }

    void tampilkanTotalBiaya() const override {
        cout << "Total Biaya (SNBP): " << totalBiaya << endl;
        if (totalBiaya > 10000000) {
            cout << "Kategori: Mahal" << endl;
        }
        else if (totalBiaya > 5000000) {
            cout << "Kategori: Sedang" << endl;
        }
        else {
            cout << "Kategori: Murah" << endl;
        }
        cout << "Rekomendasi:" << endl;
        cout << "Dipertimbangkan" << endl;
    }
};

int main() {
    // isi disini untuk fungsi main
    cout << "Selamat datang diperhitungan masuk universitas" << endl;
    cout << "Pilih jalur masuk:" << endl;
    cout << "1. SNBT" << endl;
    cout << "2. SNBP" << endl;
    cout << "3. Keluar" << endl;
    int pilihan;
    cout << "Silahkan masukkan pilihan Anda: ";
    cin >> pilihan;

    MasukUniversitas* jalurMasuk = nullptr;

    if (pilihan == 1) {
        jalurMasuk = new SNBT();
    }
    else if (pilihan == 2) {
        jalurMasuk = new SNBP();
    }
    else {
        cout << "Pilihan tidak tersedia" << endl;
        return 1;
    }

    jalurMasuk->input();
    jalurMasuk->hitungTotalBiaya();
    jalurMasuk->tampilkanTotalBiaya();

    delete jalurMasuk;
    return 0;
}
