#include <stdio.h>
#include <string.h>

int main()
{

    int jumlahPertemuan;

    // Mengisi data mahasiswa dalam satu kelas
    int jumlahMahasiswa;
    printf("========================================\n");
    printf("|      PROGRAM ABSENSI MAHASISWA       |\n");
    printf("========================================\n\n");
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlahMahasiswa);
    printf("_______________________________\n");
    // Untuk menghapus newline character yang tersisa pada buffer input sebelumnya

    printf("Masukkan jumlah pertemuan: ");
    scanf("%d", &jumlahPertemuan);
    printf("_______________________________\n");

    // Struct untuk data mahasiswa
    struct Mahasiswa
    {
        char nama[50];
        int hadir[jumlahPertemuan];
    };

    // Array struct Mahasiswa
    struct Mahasiswa dataMahasiswa[jumlahMahasiswa];

    char namaMhs[50];
    int i;
    getchar();

    // menggunakan loop for yang bertujuan untuk memasukkan nama mahasiswa
    for (i = 0; i < jumlahMahasiswa; i++)
    {

        //"fgets" fungsi untuk membaca string dari input yang telah dimasukkan dan nantinya akan di simpan pada variabel yang telah ditentukan
        //"sizeof" memiliki fungsi agar fgets tidak membaca lebih dari ukuran yang telah ditentukan untuk 'namaMhs'.
        //"stdin" berfungsi untuk membaca input dari user dan menyimpannya dalam variabel yang telah ditentukan.
        //"namaMhs" sebagai variabel yang akan diisikan oleh input user.
        printf("Masukkan nama mahasiswa ke-%d: ", i + 1);
        fgets(namaMhs, sizeof(namaMhs), stdin);

        // Setelah itu, menggunakan fungsi if untuk mengecek apabila pada karakter mengandung endline(\n) maka dihapus
        //"strlen" untuk mengetahui panjang string yang digunakan dan melakukan cek apabila di karakter terakhir memiliki endline(\n) otomatis dihapus
        if ((strlen(namaMhs) > 0) && (namaMhs[strlen(namaMhs) - 1] == '\n'))
        {
            namaMhs[strlen(namaMhs) - 1] = '\0';
        }

        // user memasukkan nama dan nama tersebut disimpan dalam variabel `namaMhs` lalu disalin ke dalam array indeks i`dataMahasiswa[i].nama` dengan menggunakan fungsi strcpy
        strcpy(dataMahasiswa[i].nama, namaMhs);
    }

    printf("\n============Daftar Mahasiswa============\n");
    // Dalam loop for dibawah berfungsi untuk mencetak secara berulang melalui array `dataMahasiswa` dan mencetak nama setiap mahasiswa.
    for (i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Nama mahasiswa ke-%d: %s\n", i + 1, dataMahasiswa[i].nama);
    }
    printf("______________________________________\n");

    // Mengambil absensi
    int j;
    int lolos = 0, tidakLolos = 0;
    // Nested loop for dibawah ini untuk menginput absensi tiap pertemuan
    for (j = 0; j < jumlahPertemuan; j++)
    {
        printf("Pertemuan: %d\n", j + 1);

        for (i = 0; i < jumlahMahasiswa; i++)
        {

            // lalu hasil dari scanf akan disimpan pada array indeks i, array `dataMahasiswa[i].nama
            // sedangkan untuk nilai dari hadir akan disimpan pada indeks j
            printf("Apakah %s hadir? (1: Ya, 0: Tidak): ", dataMahasiswa[i].nama);
            scanf("%d", &dataMahasiswa[i].hadir[j]);
        }
    }
    printf("=========================================\n");

    // Wait
    printf("\nMenghitung Rekap Absensi...\n");
    sleep(2);
    printf("Mohon Tunggu");
    for (i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }

    // Menampilkan rekap absensi
    printf("\n\n==============Rekap Absensi==============\n");
    // Nesteed loop dibawah ini berguna untuk menampilkan absensi mahasiswa dari semua pertemuan
    for (i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Nama Mahasiswa: %s\n", dataMahasiswa[i].nama);
        int totalHadir = 0;

        // berfungsi untuk mentotal kehadiran dari mahasiswa yang dimana pada waktu pengambilan absensi bernilai satu
        // maka, pada array `dataMahasiswa[i].hadir[j]` akan menambahkan nilai 1 pada tabel struct hadir
        for (j = 0; j < jumlahPertemuan; j++)
        {
            if (dataMahasiswa[i].hadir[j] == 1)
            {
                totalHadir++;
            }
        }
        printf("Jumlah kehadiran: %d\n", totalHadir);
        // fungsi if else berfungsi untuk menentukan mahasiswa yang lolos/tidak pada absensi.
        // apabila mahasiswa tersebut memiliki absensi dari 3/4 dari jumlah pertemuan maka mahasiswa itu akan lolos.
        if (totalHadir >= (jumlahPertemuan * 0.75))
        {
            printf("Status: Lulus\n");
        }
        else
        {
            printf("Status: Tidak Lulus\n");
        }

        // Perhitungan lolos dan tidaklolos
        if (totalHadir >= (jumlahPertemuan * 0.75))
        {
            lolos++;
        }
        else
        {
            tidakLolos++;
        }

        printf("=========================================\n");
    }

    printf("Jumlah Mahasiswa: %d\nLolos: %d\nTidak Lolos: %d\n", jumlahMahasiswa, lolos, tidakLolos);

    return 0;
}