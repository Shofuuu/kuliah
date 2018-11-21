#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	float s=0,p=0;
    float res[100];
    short count=0;

    printf("PERHITUNGAN RANGKAIAN RESISTOR\n");
    printf("Masukkan nilai resistor masukkan -1 jika sudah selesai: \n");
    for(int c=0;c<100;c++){
        printf(" R%i\t: ",c);
        scanf("%f",&res[c]);

        if(res[c]<0) break;
    }

    for(int range=0;range<count;range++){
        s+=(res[range]);
        if((res[range])!=0)
            p+=(1/(res[range]));
    }
    
    printf("\nHasil Perhitungan\nSeri\t: %0.1f ohm\tPresisi\t: %f ohm\n",s,s);
    printf("Pararel\t: %0.1f ohm\tPresisi\t: %f ohm\nTotal\t: %0.1f ohm\tPresisi\t: %f ohm\n",(1/p),(1/p),(s+(1/p)),(s+(1/p)));
}
