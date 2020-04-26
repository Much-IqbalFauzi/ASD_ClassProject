/*
    Muchamad Iqbal Fauzi
    672018382
*/

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "windows.h"
#define ENTER 13
#define BKSP 8

void show_menu(), lojin();
int data_len, hst_len=0;
char temp;

struct bahasa{
    char ind[50], ing[50], jaw[50], jap[50], mly[50];
}bhs[100001], trash;

struct history{
    char option[100];
}hst[100001];

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setCo(unsigned short color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void cls(){
    system("@cls || clear");
}

void loading(int x, int y){
    char load[]={'l','o','a','d','i','n','g','.','.','.'};
    short g=11;

    for(int xx=0; xx<2; xx++){
        for(int yy=0; yy<10; yy++){
            setCo((yy%5+3)*2);
            gotoxy(x+yy, y); printf("%c", load[yy]); Sleep(100);
        }
        Sleep(200);
        gotoxy(x, y); while(g--){ printf(" "); Sleep(3);}
        g=11;
    }
}

void make_word(){
    int *a, i, *s;
    short d=50, e=50, f=28;
    char res[10], wad[]="Membuat data sebanyak ";
    a = &data_len;
    s = &hst_len;

    cls();
    gotoxy(30, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(30, 7); printf("  Inputkan kata ke dalam masing-masing bahasa...");
    gotoxy(30, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(30, 11); printf("Masukkan jumlah data : "); scanf("%i", a);
    gotoxy(30, 11); while(f--){printf(" "); Sleep(5);}

    sprintf(res, "%i", *a);
    strcat(wad, res);
    strcpy(hst[*s].option, wad);
    *s += 1;

    for(i=0; i<*a; i++){
        gotoxy(30, 11+(i*6)); printf("::%2.i:: Bahasa Indonesia   : ", i+1); scanf(" %[^\n]s", &bhs[i].ind);
        gotoxy(30, 12+(i*6)); printf("::%2.i:: Bahasa Inggris \t: ", i+1); scanf(" %[^\n]s", &bhs[i].ing);
        gotoxy(30, 13+(i*6)); printf("::%2.i:: Bahasa Jawa \t: ", i+1); scanf(" %[^\n]s", &bhs[i].jaw);
        gotoxy(30, 14+(i*6)); printf("::%2.i:: Bahasa Jepang \t: ", i+1); scanf(" %[^\n]s", &bhs[i].jap);
        gotoxy(30, 15+(i*6)); printf("::%2.i:: Bahasa Melayu \t: ", i+1); scanf(" %[^\n]s", &bhs[i].mly);
    }

    loading(45, 11+(i*6));

    gotoxy(30, 11+(i*6));printf("Data telah diinputkan, Silakan tekan ENTER...");
    temp = getch();
    show_menu();
}

void list_word(){
    int *a, *s, i;
    short d=120, e=120, f=120;
    char res[]="Menampilkan daftar kosakata";
    a = &data_len;
    s = &hst_len;
    
    cls();
    gotoxy(10, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(10, 7); printf("\t\tDaftar kosakata");
    gotoxy(10, 9); while(e--){printf("="); Sleep(5);}

    strcpy(hst[*s].option, res);
    *s += 1;

    if(*a==0){
        gotoxy(10, 11); printf("WARNING! Belum ada data yang bisa ditampilkan!");
        gotoxy(10, 12); printf("Tekan ENTER untuk ke menu utama...");
        temp = getch();
        show_menu();
    }else{
        gotoxy(5, 11); printf("<NO>%15.sIndonesia | %15.sInggris | %15.sJawa | %15.sJepang | %15.sMelayu |");
        gotoxy(10, 12); while(f--){printf("_"); Sleep(5);}
        for(i=0; i<*a; i++){
            gotoxy(5, 13+i); printf("<%2.i>%24s |%23s |%20s |%22s |%22s |",
                                i+1, bhs[i].ind, bhs[i].ing, bhs[i].jaw, bhs[i].jap, bhs[i].mly);
            Sleep(10);
        }
    }

    gotoxy(10, 13+i+1); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
    
}

void add_word(){
    int *start, *s, f, i;
    short d=50, e=50, g=50;
    char res[10], wad[]="Menambahkan kata sebanyak ";
    start = &data_len;
    s = &hst_len;

    cls();
    gotoxy(30, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(30, 7); printf(" Tambahkan kata ke dalam masing-masing bahasa...");
    gotoxy(30, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(30, 11); printf("Masukkan jumlah data yang ingin ditambahkan : "); scanf("%i", &f);
    gotoxy(30, 11); while(g--){printf(" "); Sleep(5);}

    sprintf(res, "%i", f);
    strcat(wad, res);
    strcpy(hst[*s].option, wad);
    *s += 1;

    for(i=0; i<f; i++){
        gotoxy(30, 11+(i*7)); printf("Input data ke-%i", i+*start+1);
        gotoxy(30, 12+(i*7)); printf("++%2.i:: Bahasa Indonesia   : ", i+1); scanf(" %[^\n]s", &bhs[i+*start].ind);
        gotoxy(30, 13+(i*7)); printf("++%2.i:: Bahasa Inggris \t: ", i+1); scanf(" %[^\n]s", &bhs[i+*start].ing);
        gotoxy(30, 14+(i*7)); printf("++%2.i:: Bahasa Jawa \t: ", i+1); scanf(" %[^\n]s", &bhs[i+*start].jaw);
        gotoxy(30, 15+(i*7)); printf("++%2.i:: Bahasa Jepang \t: ", i+1); scanf(" %[^\n]s", &bhs[i+*start].jap);
        gotoxy(30, 16+(i*7)); printf("++%2.i:: Bahasa Melayu \t: ", i+1); scanf(" %[^\n]s", &bhs[i+*start].mly);
    }
    *start += f;

    loading(45, 11+(i*7));

    gotoxy(30, 11+(i*7)); printf("Data Berhasil ditambahkan!");
    gotoxy(30, 12+(i*7)); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void del_word(){
    char words[50], yes, load[]={'l','o','a','d','i','n','g','.','.','.'}, resu[]="Menghapus kata ", resi[]="Batal menghapus data", res[20];
    int *a, *s, i, j, tru=0, n=data_len;
    short d=50, e=50, g=50, h=6, l_u=29, l_d=29;
    a = &data_len;
    s = &hst_len;

    cls();
    gotoxy(10, 5); while(l_u--){printf("="); Sleep(5);}
    gotoxy(10, 7); printf("      KosaKata Indonesia.");
    gotoxy(10, 9); while(l_d--){printf("="); Sleep(5);}

    for(int err=0; err<*a; err++){
        gotoxy(10, 11+err); printf("--%2.i:: %-21s|", err+1, bhs[err].ind);
    }

    gotoxy(40, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(40, 7); printf("\tHapus kata berdasarkan bahasa Indonesia");
    gotoxy(40, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(40, 11); printf("Masukkan kata : "); scanf(" %[^\n]s", &words);
    

    for(i=0; i<*a; i++){
        if((strcmp(bhs[i].ind, words))==0){
            strcpy(res, bhs[i].ind);
            tru=1;
            break;
        }
    }

    if(tru==0){
        gotoxy(40, 13); printf("WARNING! Kata tidak ditemukan!");
        gotoxy(40, 14); printf("Tekan ENTER untuk mengulang...");
        temp = getch();
        del_word();
    }

    gotoxy(40, 13); printf("-- Bahasa Inggris : %s", bhs[i].ing);
    gotoxy(40, 14); printf("-- Bahasa Jawa    : %s", bhs[i].jaw);
    gotoxy(40, 15); printf("-- Bahasa Jepang  : %s", bhs[i].jap);
    gotoxy(40, 16); printf("-- Bahasa Melayu  : %s", bhs[i].mly);
    gotoxy(40, 18); printf("Apakah yakin akan menhapus data tersebut? y/n : "); scanf(" %c", &yes);

    if(yes=='N' || yes=='n'){
        strcpy(hst[*s].option, resi);
        *s += 1;

        gotoxy(40, 20); printf("Tekan ENTER untuk ke menu utama...");
        temp = getch();
        show_menu();
    }

    if(tru){
        *a -= 1;
        for(j=i; j<*a; j++){
            bhs[j]=bhs[j+1];
        }
    }

    loading(55, 19);

    for(int err=0; err<n; err++){
        gotoxy(10, 11+err); printf("%29.s", ' ');
    }

    for(int err=0; err<*a; err++){
        gotoxy(10, 11+err); printf("--%2.i:: %-21s|", err+1, bhs[err].ind);
    }
    
    strcat(resu, res);
    strcpy(hst[*s].option, resu);
    *s += 1;

    gotoxy(40, 20); printf("Data berhasil dihapus!");
    gotoxy(40, 21); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void rev_word(){
    char words[50], ops, res[]="Melakukan perubahan pada bahasa ";
    int *a, *s, i, j, tru=0, n=data_len;
    short d=50, e=50, l=50, l_u=29, l_d=29;
    a = &data_len;
    s = &hst_len;

    cls();
    gotoxy(10, 5); while(l_u--){printf("="); Sleep(5);}
    gotoxy(10, 7); printf("     Kosakata Indonesia.");
    gotoxy(10, 9); while(l_d--){printf("="); Sleep(5);}

    for(int err=0; err<*a; err++){
        gotoxy(10, 11+err); printf("-+%2.i:: %-21s|", err+1, bhs[err].ind);
    }

    gotoxy(40, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(40, 7); printf("\tEdit kata berdasarkan bahasa Indonesia");
    gotoxy(40, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(40, 11); printf("1. Bahasa Inggris\t\t3. Bahasa Jepang");
    gotoxy(40, 12); printf("2. Bahasa Jawa\t\t\t4. Bahasa Melayu");
    gotoxy(40, 14); printf("Masukkan opsi, bagian yang ingin di edit : "); 
    gotoxy(40, 15); printf("Masukkan kata : "); 
    gotoxy(84, 14); scanf(" %c", &ops);
    gotoxy(56, 15); scanf(" %[^\n]s", &words);
    gotoxy(40, 16); while(l--){printf("_"); Sleep(5);}

    for(i=0; i<*a; i++){
        if((strcmp(bhs[i].ind, words))==0){
            tru=1;
            break;
        }
    }

    if(tru==0){
        gotoxy(40, 18); printf("WARNING! Kata tidak ditemukan!");
        gotoxy(40, 19); printf("Tekan ENTER untuk mengulang...");
        temp = getch();
        rev_word();
    }

    switch(ops){
        case '1':
            gotoxy(40, 18); printf("Data saat ini : %s", bhs[i].ing);
            gotoxy(40, 19); printf("Data baru : "); scanf(" %[^\n]s", &bhs[i].ing);
            strcat(res, "Inggris");
            strcpy(hst[*s].option, res);
            *s += 1;
            break;
        case '2':
            gotoxy(40, 18); printf("Data saat ini : %s", bhs[i].jaw);
            gotoxy(40, 19); printf("Data baru : "); scanf(" %[^\n]s", &bhs[i].jaw);
            strcat(res, "Jawa");
            strcpy(hst[*s].option, res);
            *s += 1;
            break;
        case '3':
            gotoxy(40, 18); printf("Data saat ini : %s", bhs[i].jap);
            gotoxy(40, 19); printf("Data baru : "); scanf(" %[^\n]s", &bhs[i].jap);
            strcat(res, "Jepang");
            strcpy(hst[*s].option, res);
            *s += 1;
            break;
        case '4':
            gotoxy(40, 18); printf("Data saat ini : %s", bhs[i].mly);
            gotoxy(40, 19); printf("Data baru : "); scanf(" %[^\n]s", &bhs[i].mly);
            strcat(res, "Melayu");
            strcpy(hst[*s].option, res);
            *s += 1;
            break;
        default:
            gotoxy(40, 27);printf("WARNING! inputan tidak sesuai!");
            temp = getch();
            rev_word();
    }

    loading(55, 21);
    
    gotoxy(40, 21); printf("Data berhasil diedit!");
    gotoxy(40, 22); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void sea_word(){
    int i, *a, *s, tru=0;
    short d=50, e=50, l=50, m=120, b=120, f=120;
    char sea[50], ops, res[]="Melakukan pencarian kata bahasa ";
    a = &data_len;
    s = &hst_len;

    cls();
    gotoxy(30, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(30, 7); printf(" Tambahkan kata ke dalam masing-masing bahasa...");
    gotoxy(30, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(30, 11); printf("1. Bahasa Indonesia\t\t3. Bahasa Jepang");
    gotoxy(30, 12); printf("2. Bahasa Inggris\t\t\t4. Bahasa Melayu");
    gotoxy(30, 13); printf("3. Bahasa Jawa");
    gotoxy(30, 14); printf("Pilih bahasa yang dicari : "); scanf(" %c", &ops);
    gotoxy(30, 15); printf("Kata yang dicari : "); scanf(" %[^\n]s", &sea);
    
    loading(45, 17);

    switch(ops){
        case '1':
            for(i=0; i<*a; i++){
                if((strcmp(bhs[i].ind, sea))==0){
                    tru=1;
                    break;
                }
            }
            break;
        case '2':
            for(i=0; i<*a; i++){
                if((strcmp(bhs[i].ing, sea))==0){
                    tru=1;
                    break;
                }
            }
            break;
        case '3':
            for(i=0; i<*a; i++){
                if((strcmp(bhs[i].jaw, sea))==0){
                    tru=1;
                    break;
                }
            }
            break;
        case '4':
            for(i=0; i<*a; i++){
                if((strcmp(bhs[i].jap, sea))==0){
                    tru=1;
                    break;
                }
            }
            break;
        case '5':
            for(i=0; i<*a; i++){
                if((strcmp(bhs[i].mly, sea))==0){
                    tru=1;
                    break;
                }
            }
            break;
        default:
            gotoxy(40, 27);printf("WARNING! inputan tidak sesuai!");
            temp = getch();
            sea_word();
    }

    if(tru==0){
        strcpy(hst[*s].option, "Gagal melakukan pencarian");
        *s += 1;

        gotoxy(40, 17); printf("WARNING! Kata tidak ditemukan!");
        gotoxy(40, 18); printf("Tekan ENTER untuk ke menu utama...");
        temp = getch();
        show_menu();
    }

    strcat(res, sea);
    strcpy(hst[*s].option, res);
    *s += 1;

    cls();
    gotoxy(10, 5); while(m--){printf("="); Sleep(5);}
    gotoxy(10, 7); printf("\t\tHasil pencarian kata");
    gotoxy(10, 9); while(b--){printf("="); Sleep(5);}

    gotoxy(5, 11); printf("<::>%15.sIndonesia | %15.sInggris | %15.sJawa | %15.sJepang | %15.sMelayu |");
    gotoxy(10, 12); while(f--){printf("_"); Sleep(5);}
    gotoxy(5, 13+i); printf("<::>%24s |%23s |%20s |%22s |%22s |",
                                 bhs[i].ind, bhs[i].ing, bhs[i].jaw, bhs[i].jap, bhs[i].mly);

    gotoxy(40, 21); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void so_word(){
    int *a, *s, i, j, d=120, e=120, f=120;
    char ops;
    a = &data_len;
    s = &hst_len;

    cls();
    gotoxy(10, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(10, 7); printf("\t\tPengurutan Kata berdasarkan bahasa");
    gotoxy(10, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(30, 11); printf("1. Bahasa Indonesia\t\t3. Bahasa Jepang");
    gotoxy(30, 12); printf("2. Bahasa Inggris\t\t\t4. Bahasa Melayu");
    gotoxy(30, 13); printf("3. Bahasa Jawa");
    gotoxy(30, 14); printf("Pilih bahasa yang disorting : "); scanf(" %c", &ops);

    strcpy(hst[*s].option, "Melakukan sorting kata");
    *s += 1;

    switch(ops){
        case '1':
            for(i=2; i<=*a+1; i++){
                for(j=0;j<=*a-i;j++){
                    if (strcmp(bhs[j].ind, bhs[j + 1].ind) > 0) {
                        trash = bhs[j];
                        bhs[j] = bhs[j + 1];
                        bhs[j + 1] = trash;
                    }
                }
            }
            break;
        case '2':
            for(i=2; i<=*a+1; i++){
                for(j=0;j<=*a-i;j++){
                    if (strcmp(bhs[j].ing, bhs[j + 1].ing) > 0) {
                        trash = bhs[j];
                        bhs[j] = bhs[j + 1];
                        bhs[j + 1] = trash;
                    }
                }
            }
            break;
        case '3':
            for(i=2; i<=*a+1; i++){
                for(j=0;j<=*a-i;j++){
                    if (strcmp(bhs[j].jaw, bhs[j + 1].jaw) > 0) {
                        trash = bhs[j];
                        bhs[j] = bhs[j + 1];
                        bhs[j + 1] = trash;
                    }
                }
            }
            break;
        case '4':
            for(i=2; i<=*a+1; i++){
                for(j=0;j<=*a-i;j++){
                    if (strcmp(bhs[j].jap, bhs[j + 1].jap) > 0) {
                        trash = bhs[j];
                        bhs[j] = bhs[j + 1];
                        bhs[j + 1] = trash;
                    }
                }
            }
            break;
        case '5':
            for(i=2; i<=*a+1; i++){
                for(j=0;j<=*a-i;j++){
                    if (strcmp(bhs[j].mly, bhs[j + 1].mly) > 0) {
                        trash = bhs[j];
                        bhs[j] = bhs[j + 1];
                        bhs[j + 1] = trash;
                    }
                }
            }
            break;
        default:
            gotoxy(40, 17);printf("WARNING! inputan tidak sesuai!");
            temp = getch();
            so_word();
    }

    loading(45, 16);

    for(int ww=0; ww<4; ww++){
        for(int qq=0; qq<50; qq++){
            gotoxy(30+qq, 11+ww); printf(" "); Sleep(1);
        }
    }

    gotoxy(5, 11); printf("<NO>%15.sIndonesia | %15.sInggris | %15.sJawa | %15.sJepang | %15.sMelayu |");
    gotoxy(10, 12); while(f--){printf("_"); Sleep(5);}
    for(i=0; i<*a; i++){
        gotoxy(5, 13+i); printf("<%2.i>%24s |%23s |%20s |%22s |%22s |",
                            i+1, bhs[i].ind, bhs[i].ing, bhs[i].jaw, bhs[i].jap, bhs[i].mly);
        Sleep(10);
    }

    gotoxy(40, 13+i+1); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void historycal(){
    int *s, i, d=50, e=50;
    s = &hst_len;
    
    cls();
    strcpy(hst[*s].option, "Melihat riwayat pemakaian");
    *s += 1;

    gotoxy(40, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(40, 7); printf("\tRiwayat penggunaan software");
    gotoxy(40, 9); while(e--){printf("="); Sleep(5);}
    
    for(i=0; i<*s; i++){
        gotoxy(35, 11+i); printf("::%2.i:: %s", i+1, hst[i].option);
        Sleep(100);
    }

    gotoxy(40, 11+i+1); printf("Tekan ENTER untuk ke menu utama...");
    temp = getch();
    show_menu();
}

void author(){
    char name[]={"Muchamad Iqbal Fauzi"}, nim[]={"672018382"};
    short nm=0, ni=0;
    int w=39, h=5, t=5, a=39, v=5;

    cls();
    loading(45, 17);

    gotoxy(38, 8); printf("+"); while(w--){printf("-"); Sleep(5);} printf("+");
    while(t--){gotoxy(78, 13-t); printf("|"); Sleep(5);}
    gotoxy(78, 14); printf("+");
    while(a--){gotoxy(39+a, 14); printf("-"); Sleep(5);} 
    gotoxy(38, 14); printf("+");
    while(v--){gotoxy(38, 9+v); printf("|"); Sleep(5);}

    while(nm<20){gotoxy(48+nm, 10); printf("%c", name[nm]); Sleep(15); nm++;}
    while(ni<9){gotoxy(53+ni, 12); printf("%c", nim[ni]); Sleep(15); ni++;}

    Sleep(1000);
    for(int i=5; i>-1; i--){
        gotoxy(43, 17);printf("Program will end in %i seconds!", i); Sleep(1000);
    }
    for(int i=0; i<40; i++){
        gotoxy(38+i, 17); printf(" "); Sleep(5);
    }
    
    nm=0, ni=0;
    w=39, h=5, t=5, a=39, v=5;

    while(nm<20){gotoxy(48+nm, 10); printf(" "); Sleep(15); nm++;}
    while(ni<9){gotoxy(53+ni, 12); printf(" "); Sleep(15); ni++;}

    gotoxy(38, 8); printf(" "); while(w--){printf(" "); Sleep(5);} printf(" ");
    while(t--){gotoxy(78, 13-t); printf(" "); Sleep(5);}
    gotoxy(78, 14); printf(" ");
    while(a--){gotoxy(39+a, 14); printf(" "); Sleep(5);} 
    gotoxy(38, 14); printf(" ");
    while(v--){gotoxy(38, 9+v); printf(" "); Sleep(5);}
}

void switch_set(char set){
    int *a;
    a = &hst_len;

    switch(set){
        case '1':
            make_word();
            break;
        case '2':
            list_word();
            break;
        case '3':
            add_word();
            break;
        case '4':
            del_word();
            break;
        case '5':
            rev_word();
            break;
        case '6':
            sea_word();
            break;
        case '7':
            so_word();
            break;
        case '8':
            historycal();
            break;
        case '9':
            author();
            exit(0);
            break;
        default:
            gotoxy(40, 27);printf("WARNING! inputan tidak sesuai!");
            temp = getch();
            show_menu();
    }
}

void show_menu(){
    char set;
    short d=40, e=40, f=40, g=40;
    cls();
    gotoxy(40, 5); while(d--){printf("="); Sleep(5);}
    gotoxy(40, 7); printf("\t\tMain Kamus");
    gotoxy(40, 9); while(e--){printf("="); Sleep(5);}
    gotoxy(40, 11); printf("1. Membuat data baru.");
    gotoxy(40, 12); printf("2. Menampilkan daftar kosakata.");
    gotoxy(40, 13); printf("3. Menambah kata baru.");
    gotoxy(40, 14); printf("4. Menghapus kata.");
    gotoxy(40, 15); printf("5. Melakukan revisi kata.");
    gotoxy(40, 16); printf("6. Mencari kata.");
    gotoxy(40, 17); printf("7. Mengurutkan kata.");
    gotoxy(40, 18); printf("8. Riwayat aktivitas.");
    gotoxy(40, 19); printf("9. Keluar dari program.");
    gotoxy(40, 21); while(f--){printf("="); Sleep(5);}
    gotoxy(40, 23); printf("Masukkan pilihan : ");
    gotoxy(40, 25); while(g--){printf("="); Sleep(5);}
    gotoxy(60, 23); scanf(" %c", &set);
    switch_set(set);
}

void get_pw(char id[]){
    char c, pw[10];
    int i=0;
    while(1){
        c = getche();
        
        if(c == ENTER){
            pw[i] = '\0';
            break;
        }else if(c == BKSP ){
            if(i > 0){
                i--;
                gotoxy(61+i, 12);printf(" ");
            }
        }else{
            Sleep(50);
            gotoxy(61+i, 12); printf("*");
            pw[i++]=c;
        }
    }

    if((strcmp(id,"admin"))==0 && (strcmp(pw, "admin"))==0){
        loading(50, 17);
        show_menu();
    }else{
        loading(50, 17);
        gotoxy(36, 17);printf("WARNING! Username dan Password tidak sesuai!");
        temp = getch();
        lojin();
    }
}

void lojin(){
    char id[10];
    int i=0, w=39, h=5, t=5, a=39, v=5;

    cls();
    gotoxy(38, 8); printf("+"); while(w--){printf("-"); Sleep(5);} printf("+");
    while(t--){gotoxy(78, 13-t); printf("|"); Sleep(5);}
    gotoxy(78, 14); printf("+");
    while(a--){gotoxy(39+a, 14); printf("-"); Sleep(5);} 
    gotoxy(38, 14); printf("+");
    while(v--){gotoxy(38, 9+v); printf("|"); Sleep(5);}

    gotoxy(48,10); printf("Username : ");
    gotoxy(48,12); printf("Password : ");
    gotoxy(61, 10); scanf(" %[^\n]s", &id);
    gotoxy(61, 12); get_pw(id);

}

int main(){
    cls();
    loading(50, 17);
    lojin();
    return 0;
}