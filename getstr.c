#include <stdio.h>

int main(int argc, char* argv[]){
	if(argc<2)
		printf("Kekurangan argumen!\nUsage: %s [NAMA]\n",argv[0]);
	else
		printf("Hai, %s\n",argv[1]);
	return 0;
}
