#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int p=2000, b=3000,
		pn=1500, r=1000, hasil;
	int disc;
	char nama[30];

	if(argc<4)
		printf("kekurangan argumen!\nFormat : %s [PENSIL] [BALLPEN] [PENGHAPUS] [RAUTAN]\n",argv[0]);
	else{
		printf("Masukkan nama anda : ");
		gets(nama);
		hasil = (((atoi(argv[1])*p))+(atoi(argv[2])*b)+(atoi(argv[3])*pn)+(atoi(argv[4])*r));
		disc = (((atoi(argv[1])*(p-(p*10/100))))+((atoi(argv[2])*(b-(b*(5/100)))))+(atoi(argv[3])*pn)+(atoi(argv[4])*r));

		printf("\nNama pembeli\t\t: %s\n",nama);
		printf("Harga (sebelum diskon)\t: %i\n",hasil);
		printf("Harga (setelah diskon)\t: %i\n",disc);
	}
}
