#include <sfngraphic.h>

void writeStatus(char* st){
    move(21,15);
    printf("\x1B[32m%s\x1B[0m",st);
}
void draw_bracket(int x1, int y1,int y2,short type){
    move(x1,y1-1);
    if(type==1) printf("\x1B[0m┌");
    else printf("\x1B[0m┐");
    for(int y=y1;y<=y2;y++){
        move(x1,y);
        printf("│");
    }
    move(x1,y2+1);
    if(type==1) printf("└");
    else printf("┘");
}
void clear(int x1, int y1,int y2){
    for(int y=y1-1;y<=y2+1;y++){
        move(x1,y);
        printf("\x1B[0m ");
    }
}
int main(void){
    system("clear");
    int a[3][3],b[3][3],out[3][3],temp,col=1,yline=0;
    char op[2];
    temp=22; 
    draw_box(19,1,51,17);
    draw_box(20,13,50,16);
    
    draw_bracket(20,4,6,1);
    draw_bracket(30,4,6,2);

    draw_bracket(40,4,6,1);
    draw_bracket(50,4,6,2);

    draw_bracket(29,9,12,1);
    draw_bracket(41,9,12,2);

    writeStatus("masukkan angka untuk matrix A");
    for(int y=4;y<7;y++){
        for(int x=0;x<3;x++){
            printf("\x1B[1m\x1B[3%dm",col);
            move(temp,y);
            scanf("%d",&a[y-4][x]);
            temp+=3;
            if(a[y-4][x]>9){
                printf("\x1B[1m\x1B[3%dm",col);            
                clear((30-y)+y,4,6);
                draw_bracket((30-y)+y+2,4,6,2);
                temp+=1;
            }
        }
        printf("\x1B[0m");
        temp=22;
        col++;
    }

    writeStatus("pilih operator *,+,-         ");
    move(35,4);
    scanf("%s",&op);
    if(strcmp("*",op)!=0 && strcmp("/",op)!=0 && strcmp("+",op)!=0 && strcmp("-",op)!=0){
        writeStatus("Kesalahan Input Operator!");
        move(0,20);
        exit(1);
    }

    temp=42;
    col=1;
    writeStatus("masukkan angka untuk matrix B");
    for(int y=4;y<7;y++){
        for(int x=0;x<3;x++){
            printf("\x1B[1m\x1B[3%dm",col);
            move(temp,y);
            scanf("%d",&a[yline][x]);
            printf("%d%d",a[yline][x],yline);
            if(a[y-4][x]>9){
                printf("\x1B[0m");
                    draw_box(19,1,53,17);
                    clear(51,4,10);
                    draw_box(20,13,52,16);
                writeStatus("masukkan angka untuk matrix B  ");
                printf("\x1B[0m");
                printf("\x1B[1m\x1B[3%dm",col);
                clear((50-y)+y,4,6);
                draw_bracket((50-y)+y+2,4,6,2);
                temp+=1;
            }
            yline++;
            temp+=3;
            col++;
        }
        printf("\x1B[0m");
        temp=42;
        col=1;
    }

    for(int y=0;y<3;y++){
        for(int x=0;x<3;x++)
            printf("%d\t",b[y][x]);
        printf("\n");
    }

    temp=0;
    if(strcmp("*",op)==0){
        writeStatus("Matrix A * Matrix B");
        for(int d=0;d<3;d++){
            for(int y=0;y<3;y++){
                for(int x=0;x<3;x++)
                    temp+=a[d][x]*b[x][y];
                out[d][y]=temp;
                printf("%d\n",out[d][y]);
                temp=0;
            }
        }
    }else if(strcmp("+",op)==0){
    }else if(strcmp("-",op)==0){
    }

    return 0;
}