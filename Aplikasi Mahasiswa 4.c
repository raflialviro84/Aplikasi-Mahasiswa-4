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

// Fungsi untuk mengurutkan data menggunakan Merge Sort
void merge(struct Mahasiswa arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Mahasiswa L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].NPM, R[j].NPM) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi untuk melakukan pencarian dengan algoritma Jump Search
int jumpSearch(struct Mahasiswa data[], int n, char target[]) {
    int step = sqrt(n);  // Langkah pencarian
    int prev = 0;

    // Melakukan pencarian dalam blok
    while (strcmp(data[step].NPM, target) < 0 && step < n) {
        prev = step;
        step += sqrt(n);
        if (step >= n) step = n - 1;
    }

    // Pencarian linear dalam blok yang ditemukan
    for (int i = prev; i <= step; i++) {
        if (strcmp(data[i].NPM, target) == 0) {
            return i;  // Kembalikan index jika ditemukan
        }
    }
    return -1;  // Jika tidak ditemukan
}

int main() {
    struct Mahasiswa mahasiswa[] = {
        {"061", "Arif Choirudin", "Teknik Informatika", 3.5},
        {"012", "Farel Budi", "Sistem Informasi", 3.2},
        {"093", "Fernando Young", "Teknik Elektro", 3.8},
        {"224", "Rafli Alviro", "Teknik Industri", 4.0},
        {"305", "Reno Alfa Reza", "DKV", 3.7},
        {"211", "Azrul Ananda", "Akuntansi", 2.9},
        {"767", "Sahzada", "Hukum", 3.6},
        {"268", "Dicky Haikal", "Psikologi", 3.9},
        {"399", "David Ainur", "Kedokteran", 3.4},
        {"110", "Salman Alfarizi", "Biologi", 3.3}
    };

    int n = sizeof(mahasiswa) / sizeof(mahasiswa[0]);
    char target[10];

    // Mengurutkan data mahasiswa berdasarkan NPM
    merge(mahasiswa, 0, n - 1);

    printf("Masukkan NPM yang ingin dicari: ");
    scanf("%s", target);

    // Melakukan pencarian
    int result = jumpSearch(mahasiswa, n, target);

    if (result != -1) {
        printf("\nData ditemukan:\n");
        printf("NPM: %s\n", mahasiswa[result].NPM);
        printf("Nama: %s\n", mahasiswa[result].NAMA);
        printf("Prodi: %s\n", mahasiswa[result].PRODI);
        printf("IPK: %.2f\n", mahasiswa[result].IPK);
    } else {
        printf("Data tidak ditemukan.\n");
    }

    return 0;
}
