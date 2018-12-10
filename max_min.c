#include <stdio.h>

short data[10]={9,7,5,4,2,1,30,24,8,3};

short getMaxNum(void);
short getMinNum(void);

int main(int argc, char* argv[]){
    printf("Data yang tersimpan : \n");
    for(short x=0;x<10;x++)
        printf("%d). %d\n",x+1,data[x]);
    printf("\nData Terbesar (Max) : %d\n",getMaxNum());
    printf("Data Terkecil (Min) : %d\n",getMinNum());

    return 0;
}

short getMaxNum(void){
    short temp=0,max=0;

    for(short scan=0;scan<10;scan++){
        temp=data[scan];
        if(temp>max)
            max=temp;
    }

    return max;
}
short getMinNum(void){
    short temp=0,min=getMaxNum();

    for(short scan=0;scan<10;scan++){
        temp=data[scan];
        if(temp<min)
            min=temp;
    }

    return min;
}