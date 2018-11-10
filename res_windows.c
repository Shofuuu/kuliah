#include <stdio.h>
#include <stdlib.h> // atof(const char*)
#define pause() char x;scanf("%c",&x)

int main(int argc, char* argv[]){
	double s=0,p=0;

	if(argc<2)
		printf("Kekurangan argumen!\nUsage\t: %s [R1] [R2] [..]\n",argv[0]);
	else{
		printf("PERHITUNGAN RANGKAIAN RESISTOR\n\n");
		for(int range=1;range<argc;range++){
			s+=atof(argv[range]);
			if(atof(argv[range])!=0)
				p+=(1/atof(argv[range]));
			printf(" R%i\t: %0.1f ohm\n",range,atof(argv[range]));
		}
		
		printf("\nHasil Perhitungan\nSeri\t: %0.1f ohm\tPresisi\t: %f ohm\n",s,s);
		printf("Pararel\t: %0.1f ohm\tPresisi\t: %f ohm\nTotal\t: %0.1f ohm\tPresisi\t: %f ohm\n",(1/p),(1/p),(s+(1/p)),(s+(1/p)));
	}
	pause();
}
