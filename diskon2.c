/*
COMPILED ON LINUX
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 9
#define pause() char x; scanf("%c",&x)

void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
void draw_box(int x1, int y1,int x2,int y2,char* title);

int main(int argc, char* argv[]){
    char* mm[MAX]={
        "bakso", "mie ayam", "soto",
        "sate", "sop", "es buah",
        "es teh", "es jeruk", "jus"
    };
    short hr[MAX]={
        9000,7000,3000,
        12000,5000,8000,
        2500,2500,3000
    };
    int total=0,temp=0,pad;
    setlocale(LC_ALL,"");

    if(argc<2)
        printf("[\x1B[31m\x1B[1mError\x1B[0m] Kekurangan argumen!\nUsage : %s [makanan/minuman] [jumlah makanan/minuman] [...] [..]\n",argv[0]);
    else{
        printf("\033[H\033[J");
        int num=1,pos=3;
        for(int scan=1;scan<argc;scan++){
            gotoxy(4,pos);
            for(short check=0;check<9;check++){
                if(strcmp(argv[scan],mm[check])==0){
                    temp=hr[check]*atoi(argv[scan+1]);
                    total+=temp;
                    if(check<=5)
                        printf("\x1B[1m%i. \x1B[34m%s\x1B[0m\t%i mangkok\tRp%'d\n",num,mm[check],atoi(argv[scan+1]),temp);
                    else
                        printf("\x1B[1m%i. \x1B[34m%s\x1B[0m\t%i gelas\t\tRp%'d\n",num,mm[check],atoi(argv[scan+1]),temp);
                    num++;
                    pos++;
                }
            }
        }
        for(int show=0;show<MAX;show++){
            gotoxy(51,show+3);
            printf("\x1B[1m%i. \x1B[34m%s\x1B[0m\tRp%'i",show+1,mm[show],hr[show]);
        }
        
        if(pos<12) pad=12;
        else pad=pos;

        if(total<100000){
            gotoxy(4,pad+2);
            printf("\x1B[1mRp%'d\x1B[0m",total);
            gotoxy(42,pad+2);
            printf("\x1B[33mDiskon minimal pembelian Rp100.000\x1B[0m");
        }else{
            gotoxy(4,pad+2);
            printf("\x1B[1mRp%'d\x1B[0m",total);
            gotoxy(42,pad+2);
            printf("\x1B[1mRp%'0.2f\x1B[0m",total-((total)*5.0/100.0));
        }

        draw_box(2,1,48,pad,"Makanan & Minuman");
        draw_box(49,1,79,12,"Daftar Harga");
        draw_box(2,pad,39,pad+3,"Total Harga");
        draw_box(40,pad,79,pad+3,"Harga Diskon");
        printf("\n\n");
        pause();
    }

    return 0;
}
void draw_box(int x1, int y1,int x2,int y2,char* title){
    x1+=1; y1+=1;
    gotoxy(x1-1,y1);
    printf("┌");
    for(int _x=x1;_x<x2;_x++){
        gotoxy(_x,y1);
        printf("─");
    }
    gotoxy(x1+2,y1);
    printf("┤\x1B[1m\x1B[32m%s\x1B[0m├",title);
    gotoxy(x2,y1);
    printf("┐");
    for(int _y=y1+1;_y<y2;_y++){
        gotoxy(x1-1,_y);
        printf("│");
    }
    gotoxy(x1-1,y2);
    printf("└");
    for(int _y=y1+1;_y<y2;_y++){
        gotoxy(x2,_y);
        printf("│");
    }
    gotoxy(x2,y2);
    printf("┘");
    for(int _x=x1;_x<x2;_x++){
        gotoxy(_x,y2);
        printf("─");
    }
}