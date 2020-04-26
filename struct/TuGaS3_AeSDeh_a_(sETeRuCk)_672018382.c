#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"

int main();
struct ___{
    char id[5];
    char nambar[20];
    int rego;
    int cacah;
};
struct ____{
    char jeneng[20];
    char nim[9];
};

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void __(){
    struct ____ _;

    void give(){
        system("@cls || clear");
        printf("Input Nama : ");
        scanf(" %[^\n]s", &_.jeneng);
        printf("Input NIM : ");
        scanf("%s", &_.nim);
    }
    
    void conf(char na[20], char ni[10]){
        system("@cls || clear");
        gotoxy(30, 15);
        printf("Welcome %s\tId_Code %s", na, ni); 
        getch();
    }
 
    give();
    conf( _.jeneng, _.nim);
}

void _(){
    int j;

    system("@cls || clear");
    printf("Masukkan jumlah barang : ");
    scanf("%i", &j);
    struct ___ bar[j];

    for(int i=0; i<j; i++){
        printf("\nBarang Ke-%i\nID barang : ", i+1);
        scanf("%s", &bar[i].id);
        printf("Nama barang : ");
        scanf(" %[^\n]s", &bar[i].nambar);
        printf("Harga Barang : ");
        scanf("%i", &bar[i].rego);
        printf("Jumlah barang : ");
        scanf("%i", &bar[i].cacah);
    }

    void blank(){
        system("@cls || clear");
        getch();
    }

    void _____(int _){
        gotoxy(30, 20);
        printf("No.\tID\tNama Barang\t\tHarga\t\tJumlah");
        for(int i=0; i<_; i++){
            printf("\n\t\t\t\t%i\t%s\t%s\t\t%i\t\t%i", i+1, bar[i].id, bar[i].nambar, bar[i].rego, bar[i].cacah);
        }
    }

    blank();
    _____(j);
}

int main(){
    __();
    _();
    return 0;
}