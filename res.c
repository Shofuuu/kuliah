#include <stdio.h>
#include <stdlib.h> // atof(const char*)
//#define pause() char x;scanf("%c",&x)

int main(int argc, char* argv[]){
	double s=0,p=0;

	if(argc<2)
		printf("\x1B[1m\x1B[31mKekurangan argumen!\x1B[0m\nUsage\t: %s [R1] [R2] [..]\n",argv[0]);
	else{
		printf("\x1B[1m\x1B[32mPERHITUNGAN RANGKAIAN RESISTOR\n\n\x1B[0m");
		for(int range=1;range<argc;range++){
			s+=atof(argv[range]);
			if(atof(argv[range])!=0)
				p+=(1/atof(argv[range]));
			printf(" \x1B[1m\x1B[34mR%i\x1B[0m\t: %0.1f ohm\n",range,atof(argv[range]));
		}
		
		printf("\n\x1B[1m\x1B[32mHasil Perhitungan\x1B[0m\nSeri\t: %0.1f ohm\tPresisi\t: %f ohm\n",s,s);
		printf("Pararel\t: %0.1f ohm\tPresisi\t: %f ohm\nTotal\t: %0.1f ohm\tPresisi\t: %f ohm\n",(1/p),(1/p),(s+(1/p)),(s+(1/p)));
	}
	//pause();
}
