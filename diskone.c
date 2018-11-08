#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc<4)
		printf("kekurangan argumen!\nFormat : %s [PENSIL] [BALLPEN] [PENGHAPUS] [RAUTAN] [NAMA]\n",argv[0]);
	else{
		printf("Nama pembeli\t\t: %s\n",argv[5]);
		printf("Harga (sebelum diskon)\t: %i\n",(((atoi(argv[1])*2000))+(atoi(argv[2])*3000)+(atoi(argv[3])*1500)+(atoi(argv[4])*1000)));
		printf("Harga (setelah diskon)\t: %i\n",(((atoi(argv[1])*(2000-(2000*10/100))))+((atoi(argv[2])*(3000-(3000*(5/100)))))+(atoi(argv[3])*1500)+(atoi(argv[4])*1000)));
	}
}
