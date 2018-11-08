#include <stdio.h>

int main(){
    int x=0,y=0;

    while(x<10){
        while(y<x){
            printf("%i",y);
            y++;
        }
        printf("%i",x);
        printf("\n");
        x++;
    }
}