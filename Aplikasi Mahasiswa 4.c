#include <stdio.h>
#include <math.h>
#include <string.h>

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    char NPM[10];
    char NAMA[50];
    char PRODI[50];
    float IPK;
};

// Fungsi untuk mengurutkan data menggunakan Bubble Sort
void bubbleSort(struct Mahasiswa mhs[], int n) {
    struct Mahasiswa temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(mhs[j].NPM, mhs[j+1].NPM) > 0) {
                temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan pencarian dengan algoritma Jump Search
int jumpSearch(struct Mahasiswa mhs[], int n, char target[]) {
    int step = sqrt(n);  // Langkah lompatan
    int prev = 0;  // Posisi sebelumnya

    // Loop untuk melompati data
    while (prev < n) {
        // Periksa apakah data yang dicari berada pada posisi yang dilompati
        if (strcmp(mhs[prev].NPM, target) == 0) {
            return prev;  // Data ditemukan
        }
        // Jika NPM yang dicari lebih kecil, lakukan linear search
        if (strcmp(mhs[prev].NPM, target) > 0) {
            for (int i = prev - step; i < prev; i++) {
                if (strcmp(mhs[i].NPM, target) == 0) {
                    return i;  // Data ditemukan
                }
            }
            return -1;  // Data tidak ditemukan setelah pencarian linear
        }
        prev += step;  // Lompat ke langkah berikutnya
    }
    return -1;  // Jika data tidak ditemukan
}

// Fungsi untuk menampilkan data mahasiswa
void printMahasiswa(struct Mahasiswa mhs) {
    printf("\nData Mahasiswa ditemukan:\n");
    printf("NPM   : %s\n", mhs.NPM);
    printf("Nama  : %s\n", mhs.NAMA);
    printf("Prodi : %s\n", mhs.PRODI);
    printf("IPK   : %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs[] = {
        {"061", "Arif Choirudin", "Teknik Informatika", 3.5},
        {"012", "Farel Budi", "Sistem Informasi", 3.2},
        {"093", "Fernando Young", "Teknik Elektro", 3.8},
        {"224", "Rafli Alviro", "Teknik Industri", 4.0},
        {"305", "Reno Alfa Reza", "DKV", 3.7},
        {"211", "Azrul Ananda", "Akuntansi", 2.9},
        {"767", "Sahzada Joko", "Hukum", 3.6},
        {"268", "Dicky Haikal", "Psikologi", 3.9},
        {"399", "David Ainur", "Kedokteran", 3.4},
        {"110", "Salman Alfarizi", "Biologi", 3.3}
    };

    int n = 10;
    char target[12];

    bubbleSort(mhs, n);

    printf("Masukkan NPM yang ingin dicari: ");
    scanf("%s", target);

    int result = jumpSearch(mhs, n, target);

    if (result != -1) {
        printMahasiswa(mhs[result]);
    } else {
        printf("Data tidak ditemukan.\n");
    }

    return 0;
}
