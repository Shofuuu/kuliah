#include <stdio.h>

int main(int argc, char*  argv[]){
	if(argc<2)
		printf("Kekurangan argumen!\nUsage: %s [PANJANG] [LEBAR]\n", argv[0]);
	else
		printf("Panjang\t: %i\nLebar\t: %i\nLuas\t: %i\n",atoi(argv[1]),atoi(argv[2]),atoi(argv[1])*atoi(argv[2]));

	return 0;
}
