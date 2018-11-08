#include <stdio.h>

int main(){
	float data[10]={220,641,53,80,11,33,903};
	float *pointer;

	for(int x=0;x<7;x++){
		pointer=&data[x];
		printf("Value %0.1f at address %p\n",*pointer/*untuk mengganti value*/,pointer/*untuk menampilkan alamat*/);
		printf("Value %0.1f at address %p\n\n",(*pointer+1),pointer+1);
	}

	return 0;
}
