#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linked.h"
#include "stack.h"
#include "queue.h"

// Fungsi untuk menampilkan menu
void tampilMenuUtama();
void tampilMenuLinkedList();
void tampilMenuStack();
void tampilMenuQueue();
void tampilMenuKombinasi();

// Fungsi operasi untuk setiap struktur data
void operasiLinkedList();
void operasiStack();
void operasiQueue();
void operasiKombinasi();

// Fungsi kombinasi struktur data
void pindahStackKeQueue(Stack *S, Queue *Q);
void pindahQueueKeStack(Queue *Q, Stack *S);
void balikQueue(Queue *Q);
void urutkanData(Stack *S, Queue *Q);
void palindromeCheck();

int main() {
    int pilihan = 0;
    
    do {
        tampilMenuUtama();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
                operasiLinkedList();
                break;
            case 2:
                operasiStack();
                break;
            case 3:
                operasiQueue();
                break;
            case 4:
                operasiKombinasi();
                break;
            case 0:
                printf("\nTerima kasih telah menggunakan program ini!\n");
                break;
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
        }
    } while(pilihan != 0);
    
    return 0;
}

void tampilMenuUtama() {
    printf("\n===== MENU UTAMA =====\n");
    printf("1. Operasi Linked List\n");
    printf("2. Operasi Stack\n");
    printf("3. Operasi Queue\n");
    printf("4. Operasi Kombinasi\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
}

void tampilMenuLinkedList() {
    printf("\n===== OPERASI LINKED LIST =====\n");
    printf("1. Buat List Baru\n");
    printf("2. Tambah Data di Awal\n");
    printf("3. Tambah Data di Akhir\n");
    printf("4. Tambah Data Setelah Nilai Tertentu\n");
    printf("5. Hapus Data Awal\n");
    printf("6. Hapus Data Akhir\n");
    printf("7. Cari Data\n");
    printf("8. Tampilkan List\n");
    printf("9. Hitung Jumlah Elemen\n");
    printf("10. Cari Nilai Minimum\n");
    printf("11. Hitung Rata-rata\n");
    printf("12. Balik List\n");
    printf("0. Kembali ke Menu Utama\n");
    printf("Pilihan: ");
}

void tampilMenuStack() {
    printf("\n===== OPERASI STACK =====\n");
    printf("1. Buat Stack Baru\n");
    printf("2. Push (Tambah Data)\n");
    printf("3. Pop (Ambil Data)\n");
    printf("4. Cek Stack Kosong\n");
    printf("5. Tampilkan Stack\n");
    printf("0. Kembali ke Menu Utama\n");
    printf("Pilihan: ");
}

void tampilMenuQueue() {
    printf("\n===== OPERASI QUEUE =====\n");
    printf("1. Buat Queue Baru\n");
    printf("2. Enqueue (Tambah Data)\n");
    printf("3. Dequeue (Ambil Data)\n");
    printf("4. Cek Queue Kosong\n");
    printf("5. Tampilkan Queue\n");
    printf("6. Hitung Panjang Queue\n");
    printf("0. Kembali ke Menu Utama\n");
    printf("Pilihan: ");
}

void tampilMenuKombinasi() {
    printf("\n===== OPERASI KOMBINASI =====\n");
    printf("1. Pindahkan Data dari Stack ke Queue\n");
    printf("2. Pindahkan Data dari Queue ke Stack\n");
    printf("3. Balik Urutan Queue menggunakan Stack\n");
    printf("4. Urutkan Data menggunakan Stack dan Queue\n");
    printf("5. Cek Palindrom\n");
    printf("0. Kembali ke Menu Utama\n");
    printf("Pilihan: ");
}

void operasiLinkedList() {
    address head = NULL;
    address hasil, baru;
    int pilihan = -1;
    int nilai, nilaiTarget;
    
    while(pilihan != 0) {
        tampilMenuLinkedList();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: // Buat List Baru
                head = NULL;
                printf("\nList baru berhasil dibuat!\n");
                break;
                
            case 2: // Tambah Data di Awal
                printf("\nMasukkan nilai yang akan ditambahkan: ");
                scanf("%d", &nilai);
                Create_Node(&baru);
                Isi_Node(&baru, nilai);
                Ins_Awal(&head, baru);
                printf("Nilai %d berhasil ditambahkan di awal list.\n", nilai);
                break;
                
            case 3: // Tambah Data di Akhir
                printf("\nMasukkan nilai yang akan ditambahkan: ");
                scanf("%d", &nilai);
                Create_Node(&baru);
                Isi_Node(&baru, nilai);
                Ins_Akhir(&head, baru);
                printf("Nilai %d berhasil ditambahkan di akhir list.\n", nilai);
                break;
                
            case 4: // Tambah Data Setelah Nilai Tertentu
                printf("\nMasukkan nilai yang akan ditambahkan: ");
                scanf("%d", &nilai);
                printf("Masukkan nilai target (setelahnya): ");
                scanf("%d", &nilaiTarget);
                Create_Node(&baru);
                Isi_Node(&baru, nilai);
                InsertAfter(&head, nilaiTarget, baru);
                printf("Nilai %d berhasil ditambahkan setelah %d.\n", nilai, nilaiTarget);
                break;
                
            case 5: // Hapus Data Awal
                if(isEmpty(head)) {
                    printf("\nList kosong, tidak ada yang bisa dihapus.\n");
                } else {
                    Del_Awal(&head, &nilai);
                    printf("\nNilai %d berhasil dihapus dari awal list.\n", nilai);
                }
                break;
                
            case 6: // Hapus Data Akhir
                if(isEmpty(head)) {
                    printf("\nList kosong, tidak ada yang bisa dihapus.\n");
                } else {
                    Del_Akhir(&head, &nilai);
                    printf("\nNilai %d berhasil dihapus dari akhir list.\n", nilai);
                }
                break;
                
            case 7: // Cari Data
                printf("\nMasukkan nilai yang akan dicari: ");
                scanf("%d", &nilai);
                hasil = Search(head, nilai);
                if(hasil != NULL) {
                    printf("Nilai %d ditemukan dalam list.\n", nilai);
                } else {
                    printf("Nilai %d tidak ditemukan dalam list.\n", nilai);
                }
                break;
                
            case 8: // Tampilkan List
                printf("\nIsi List: ");
                Tampil_List(head);
                break;
                
            case 9: // Hitung Jumlah Elemen
                printf("\nJumlah elemen dalam list: %d\n", NbElmt(head));
                break;
                
            case 10: // Cari Nilai Minimum
                if(isEmpty(head)) {
                    printf("\nList kosong, tidak ada nilai minimum.\n");
                } else {
                    printf("\nNilai minimum dalam list: %d\n", Min(head));
                }
                break;
                
            case 11: // Hitung Rata-rata
                if(isEmpty(head)) {
                    printf("\nList kosong, tidak ada rata-rata.\n");
                } else {
                    printf("\nRata-rata nilai dalam list: %d\n", Rerata(head));
                }
                break;
                
            case 12: // Balik List
                if(isEmpty(head)) {
                    printf("\nList kosong, tidak bisa dibalik.\n");
                } else {
                    head = BalikList(head);
                    printf("\nList berhasil dibalik!\n");
                }
                break;
                
            case 0: // Kembali ke Menu Utama
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
        }
    }
}

void operasiStack() {
    Stack S;
    int pilihan = -1;
    int nilai;
    boolean stackDibuat = false;
    
    while(pilihan != 0) {
        tampilMenuStack();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: // Buat Stack Baru
                CreateStack(&S);
                stackDibuat = true;
                printf("\nStack baru berhasil dibuat!\n");
                break;
                
            case 2: // Push
                if(!stackDibuat) {
                    printf("\nStack belum dibuat. Buat stack terlebih dahulu.\n");
                } else {
                    printf("\nMasukkan nilai yang akan di-push: ");
                    scanf("%d", &nilai);
                    Push(&S, nilai);
                    printf("Nilai %d berhasil di-push ke stack.\n", nilai);
                }
                break;
                
            case 3: // Pop
                if(!stackDibuat) {
                    printf("\nStack belum dibuat. Buat stack terlebih dahulu.\n");
                } else if(IsEmpty(S)) {
                    printf("\nStack kosong, tidak bisa melakukan pop.\n");
                } else {
                    Pop(&S, &nilai);
                    printf("\nNilai %d berhasil di-pop dari stack.\n", nilai);
                }
                break;
                
            case 4: // Cek Stack Kosong
                if(!stackDibuat) {
                    printf("\nStack belum dibuat. Buat stack terlebih dahulu.\n");
                } else if(IsEmpty(S)) {
                    printf("\nStack kosong.\n");
                } else {
                    printf("\nStack tidak kosong.\n");
                }
                break;
                
            case 5: // Tampilkan Stack
                if(!stackDibuat) {
                    printf("\nStack belum dibuat. Buat stack terlebih dahulu.\n");
                } else {
                    printf("\nIsi Stack: ");
                    PrintStack(S);
                }
                break;
                
            case 0: // Kembali ke Menu Utama
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
        }
    }
}

void operasiQueue() {
    Queue Q;
    int pilihan = -1;
    int nilai;
    boolean queueDibuat = false;
    
    while(pilihan != 0) {
        tampilMenuQueue();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: // Buat Queue Baru
                CreateQueue(&Q);
                queueDibuat = true;
                printf("\nQueue baru berhasil dibuat!\n");
                break;
                
            case 2: // Enqueue
                if(!queueDibuat) {
                    printf("\nQueue belum dibuat. Buat queue terlebih dahulu.\n");
                } else {
                    printf("\nMasukkan nilai yang akan di-enqueue: ");
                    scanf("%d", &nilai);
                    Enqueue(&Q, nilai);
                    printf("Nilai %d berhasil di-enqueue ke queue.\n", nilai);
                }
                break;
                
            case 3: // Dequeue
                if(!queueDibuat) {
                    printf("\nQueue belum dibuat. Buat queue terlebih dahulu.\n");
                } else if(IsQueueEmpty(Q)) {
                    printf("\nQueue kosong, tidak bisa melakukan dequeue.\n");
                } else {
                    Dequeue(&Q, &nilai);
                    printf("\nNilai %d berhasil di-dequeue dari queue.\n", nilai);
                }
                break;
                
            case 4: // Cek Queue Kosong
                if(!queueDibuat) {
                    printf("\nQueue belum dibuat. Buat queue terlebih dahulu.\n");
                } else if(IsQueueEmpty(Q)) {
                    printf("\nQueue kosong.\n");
                } else {
                    printf("\nQueue tidak kosong.\n");
                }
                break;
                
            case 5: // Tampilkan Queue
                if(!queueDibuat) {
                    printf("\nQueue belum dibuat. Buat queue terlebih dahulu.\n");
                } else {
                    PrintQueue(Q);
                }
                break;
                
            case 6: // Hitung Panjang Queue
                if(!queueDibuat) {
                    printf("\nQueue belum dibuat. Buat queue terlebih dahulu.\n");
                } else {
                    printf("\nPanjang Queue: %d\n", QueueLength(Q));
                }
                break;
                
            case 0: // Kembali ke Menu Utama
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
        }
    }
}

void pindahStackKeQueue(Stack *S, Queue *Q) {
    infotype nilai;
    Stack tempStack;
    CreateStack(&tempStack);
    
    printf("\nMemindahkan elemen dari Stack ke Queue...\n");
    
    // Simpan ke stack temp untuk mempertahankan urutan asli
    while(!IsEmpty(*S)) {
        Pop(S, &nilai);
        Push(&tempStack, nilai);
    }
    
    // Pindahkan dari temp ke queue untuk mendapatkan urutan yang sama
    while(!IsEmpty(tempStack)) {
        Pop(&tempStack, &nilai);
        Enqueue(Q, nilai);
        printf("Elemen %d dipindahkan ke Queue\n", nilai);
    }
    
    printf("Pemindahan selesai!\n");
}

void pindahQueueKeStack(Queue *Q, Stack *S) {
    infotype nilai;
    Queue tempQueue;
    CreateQueue(&tempQueue);
    int queueLen = QueueLength(*Q);
    int i;
    
    printf("\nMemindahkan elemen dari Queue ke Stack...\n");
    
    for(i = 0; i < queueLen; i++) {
        Dequeue(Q, &nilai);
        Enqueue(&tempQueue, nilai);
    }
    
    for(i = 0; i < queueLen; i++) {
        Dequeue(&tempQueue, &nilai);
        Push(S, nilai);
        Enqueue(Q, nilai);
        printf("Elemen %d dipindahkan ke Stack\n", nilai);
    }
    
    printf("Pemindahan selesai!\n");
}

void balikQueue(Queue *Q) {
    Stack tempStack;
    CreateStack(&tempStack);
    infotype nilai;
    
    printf("\nMembalik urutan Queue menggunakan Stack...\n");
    
    // Pindahkan semua elemen queue ke stack (urutan akan terbalik)
    while(!IsQueueEmpty(*Q)) {
        Dequeue(Q, &nilai);
        Push(&tempStack, nilai);
        printf("Elemen %d dipindahkan ke Stack sementara\n", nilai);
    }
    
    // Pindahkan kembali ke queue (urutan terbalik lagi = urutan asli terbalik)
    while(!IsEmpty(tempStack)) {
        Pop(&tempStack, &nilai);
        Enqueue(Q, nilai);
        printf("Elemen %d dikembalikan ke Queue\n", nilai);
    }
    
    printf("Queue berhasil dibalik!\n");
}

void urutkanData(Stack *S, Queue *Q) {
    infotype nilai, temp;
    Stack tempStack;
    Queue tempQueue;
    
    CreateStack(&tempStack);
    CreateQueue(&tempQueue);
    
    printf("\nPengurutan data menggunakan Stack dan Queue...\n");
    
    // Pindahkan semua elemen dari stack ke queue
    while(!IsEmpty(*S)) {
        Pop(S, &nilai);
        Enqueue(Q, nilai);
    }
    
    // Bubble sort menggunakan queue
    int n = QueueLength(*Q);
    int i, j;
    
    for(i = 0; i < n; i++) {
        // Dequeue elemen pertama untuk perbandingan
        Dequeue(Q, &nilai);
        Enqueue(&tempQueue, nilai);
        
        for(j = 0; j < n-1; j++) {
            Dequeue(Q, &temp);
            
            if(nilai > temp) {  // Swap jika diperlukan
                Enqueue(Q, nilai);
                nilai = temp;
            } else {
                Enqueue(Q, temp);
            }
        }
        
        // Nilai terkecil pada iterasi ini di-enqueue ke tempQueue
        Enqueue(&tempQueue, nilai);
    }
    
    // Pindahkan kembali elemen yang sudah urut dari tempQueue ke stack
    while(!IsQueueEmpty(tempQueue)) {
        Dequeue(&tempQueue, &nilai);
        Push(S, nilai);
    }
    
    printf("Pengurutan selesai!\n");
}

void palindromeCheck() {
    char input[100];
    Stack charStack;
    int i, length;
    infotype c;
    boolean isPalindrome = true;
    
    CreateStack(&charStack);
    
    printf("\nMasukkan kata/kalimat untuk dicek palindrom: ");
    scanf(" %[^\n]", input);
    
    length = strlen(input);
    
    // Push karakter pertama sampai tengah ke stack
    for(i = 0; i < length/2; i++) {
        Push(&charStack, input[i]);
    }
    
    // Skip karakter tengah jika jumlah karakter ganjil
    if(length % 2 != 0) {
        i++;
    }
    
    // Bandingkan karakter kedua-setengah dengan yang di stack
    while(i < length && isPalindrome) {
        Pop(&charStack, &c);
        if(c != input[i]) {
            isPalindrome = false;
        }
        i++;
    }
    
    if(isPalindrome) {
        printf("\"%s\" adalah palindrom.\n", input);
    } else {
        printf("\"%s\" bukan palindrom.\n", input);
    }
}

void operasiKombinasi() {
    Stack S;
    Queue Q;
    int pilihan = -1;
    int i, nilai;
    
    CreateStack(&S);
    CreateQueue(&Q);
    
    while(pilihan != 0) {
        tampilMenuKombinasi();
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: // Pindahkan Data dari Stack ke Queue
                printf("\nMengisi Stack dengan contoh data...\n");
                CreateStack(&S);
                for(i = 1; i <= 5; i++) {
                    Push(&S, i*10);
                }
                printf("Isi Stack: ");
                PrintStack(S);
                
                CreateQueue(&Q);
                pindahStackKeQueue(&S, &Q);
                
                printf("Isi Queue setelah pemindahan: ");
                PrintQueue(Q);
                break;
                
            case 2: // Pindahkan Data dari Queue ke Stack
                printf("\nMengisi Queue dengan contoh data...\n");
                CreateQueue(&Q);
                for(i = 1; i <= 5; i++) {
                    Enqueue(&Q, i*5);
                }
                printf("Isi Queue: ");
                PrintQueue(Q);
                
                CreateStack(&S);
                pindahQueueKeStack(&Q, &S);
                
                printf("Isi Stack setelah pemindahan: ");
                PrintStack(S);
                break;
                
            case 3: // Balik Urutan Queue
                printf("\nMengisi Queue dengan contoh data...\n");
                CreateQueue(&Q);
                for(i = 1; i <= 5; i++) {
                    Enqueue(&Q, i);
                }
                printf("Isi Queue sebelum dibalik: ");
                PrintQueue(Q);
                
                balikQueue(&Q);
                
                printf("Isi Queue setelah dibalik: ");
                PrintQueue(Q);
                break;
                
            case 4: // Urutkan Data
                printf("\nMengisi Stack dengan data acak...\n");
                CreateStack(&S);
                Push(&S, 42);
                Push(&S, 17);
                Push(&S, 30);
                Push(&S, 8);
                Push(&S, 25);
                printf("Isi Stack sebelum diurutkan: ");
                PrintStack(S);
                
                CreateQueue(&Q);
                urutkanData(&S, &Q);
                
                printf("Isi Stack setelah diurutkan: ");
                PrintStack(S);
                break;
                
            case 5: // Cek Palindrom
                palindromeCheck();
                break;
                
            case 0: // Kembali ke Menu Utama
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan coba lagi.\n");
        }
    }
}
