#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	float volume,luas;

	if(argc<4)
		printf("Kekurangan argumen!\nformat : %s [TP] [A] [TS]\n",argv[0]);
	else{
		volume=(atof(argv[1])*atof(argv[3])*atof(argv[2]))/2;
		luas=(atof(argv[1])*atof(argv[2])*3)+(atof(argv[2])*atof(argv[3]));
		printf("Volume\t= %f\n",volume);
		printf("Luas\t= %f\n",luas);
	}
}
