#include <sfngraphic.h>
#include <string.h>
#include <locale.h>

struct DATA{
    unsigned char jam_kerja[26];
    char getAnswer[100];
}Data;
void ask(char* _p, int y, int cut);
void questioner(void);
void kalkulasi(char* nama,int jam, int lembur);

int main(void){
    setlocale(LC_ALL,"");
    for(short fill=0;fill<26;fill++)
        Data.jam_kerja[fill]=9;

    questioner();

    move(0,25);
    return 0;
}

void ask(char* _p, int y, int cut){
    char _ask[100];

    draw_box(2,1+y,5+strlen(_p),4+y);
    move(4,3+y);
    printf("\x1B[34m\x1B[1m%s\x1B[0m",_p);
    draw_box(5+strlen(_p),1+y,(((strlen(_p)*strlen(_p))/1.5))-(cut*cut),4+y);
    move(strlen(_p)+7,3+y);
        gets(_ask);
    strcpy(Data.getAnswer,_ask);
}
void questioner(void){
    char* kerja;
    char* lembur;
    char nama[100];
    
    draw_grub(1,1,60,16,"Kalkulator Gaji Pegawai");
    ask("Nama Anda",1,0);
    strcpy(nama,Data.getAnswer);
    move(3,7);
    printf("\x1B[1mMasukkan jam kerja anda per harinya");
    ask("Input Anda",6,6);
    strcpy(kerja,Data.getAnswer);
    move(3,12);
    printf("\x1B[1mMasukkan berapa kali anda lembur dalam sebulan\x1B[0m");
    ask("Input Anda",11,6);
    strcpy(lembur,Data.getAnswer);
    
    kalkulasi(nama,atoi(kerja),atoi(lembur));
}
void kalkulasi(char* nama,int jam, int lembur){
    system("clear");
    int r=0;
    for(int rata=0;rata<(26)-lembur;rata++)
        Data.jam_kerja[rata]=jam;
    draw_grub(1,1,70,16,"Kalkulator Gaji Pegawai");
    draw_box(2,3,35,15);

    move(4,4);
    printf("\x1B[34m\x1B[1mData Pegawai\x1B[0m");
    move(3,5);
    printf("\x1B[1mNama :\x1B[0m %s",nama);
    move(3,8);
    for(int rata=0;rata<(26)-lembur;rata++)
        r+=Data.jam_kerja[rata];
    printf("\x1B[1mRata-Rata Jam Kerja\t: \x1B[0m%d jam",r/(26-lembur));
    move(3,7);
    printf("\x1B[1mLembur\t\t: \x1B[0m%i kali",lembur);
    move(3,10);
    for(int x=1;x<=32;x++)
        printf("\x1B[1m-\x1B[0m");
    move(3,12);
    for(int t=0;t<26;t++){
        if(jam==9) r+=30000;
        else if(jam<9) r+=20000;
        else if(jam>9) r+=40000;
    }
    printf("\x1B[1mGaji Bersih : \x1B[0mRp%'d",r);
    move(3,13);
    printf("\x1B[1mGaji Lembur : \x1B[0mRp%'d",(lembur*40000));
    move(3,14);
    printf("\x1B[1mGaji Total  : \x1B[0mRp%'d",(lembur*40000)+r);
}