#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc<3)
		printf("Kekurangan argumen!\nUsage : %s [LITER] [KM]\n",argv[0]);
	else{
		printf("Jumlah Liter\t: %f\nJumlah KM\t: %f\n",atof(argv[1]),atof(argv[2]));
		printf("\nHasil ahir\nGallon\t: %f\nMil\t: %f\nTotal\t: %f\n",(atof(argv[1])*0.25),(atof(argv[2])*1.609),(atof(argv[1])*0.25)/(atof(argv[2])*1.609));
	}

	return 0;
}
