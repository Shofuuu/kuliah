#include <sfngraphic.h>
#include <locale.h>
#define grub(x) draw_grub(1,1,55,x,"Kalkulator Gaji Pegawai")
#define clear(y) for(int x=2;x<55;x++){ move(x,y); printf(" "); }

char getAnswer[100];
int getIntAnswer;
void ask(char* _p, int y, int cut, short type);

int main(){
    char nama[100];
    int gaji,n,l,k;

    setlocale(LC_ALL,"");
    grub(6);
    ask("Nama Anda",1,54,1);
    strcpy(&nama,&getAnswer);
    
    grub(9);
    ask("Berapa Kali Jam Kerja Normal (9 jam)",4,54,2);
    n=getIntAnswer;

    grub(12);
    ask("Berapa Kali Jam Kerja Lembur (>9 jam)",7,54,2);
    l=getIntAnswer;

    grub(15);
    ask("Berapa Kali Jam Kerja Kurang (<9 jam)",10,54,2);
    k=getIntAnswer;
    system("clear");

    grub(9);
    move(3,4);
    printf("\x1B[1mNama : \x1B[0m%s",&nama);
    move(3,5);
    printf("\x1B[1mGaji Bersih : \x1B[0mRp%'d",(n*30000)+(k*20000));
    move(3,6);
    printf("\x1B[1mGaji Lembur : \x1B[0mRp%'d",l*40000);
    move(3,7);
    printf("\x1B[1mTotal Gaji  : \x1B[0mRp%'d",(n*30000)+(k*20000)+(l*40000));

    move(0,30);
    return 0;
}

void ask(char* _p, int y, int cut, short type){
    char _ask[100];
    int temp;

    draw_box(2,1+y,5+strlen(_p),4+y);
    move(4,3+y);
    printf("\x1B[34m\x1B[1m%s\x1B[0m",_p);
    draw_box(5+strlen(_p),1+y,/*(((strlen(_p)*strlen(_p))/1.5))-(cut*cut)*/cut,4+y);
    move(strlen(_p)+7,3+y);

    if(type==1){
        gets(_ask);
        strcpy(getAnswer,_ask);
    }else{
        scanf("%i",&temp);
        getIntAnswer=temp;
    }
}