#include <stdio.h>

int main(){
	int x=4;
	char data='c';

	switch(data){
		case 'a': printf("SENIN\n"); break;
		case 'b': printf("SELASA\n"); break;
		default: printf("Tidak Dikenali\n"); break;
	}

	if(data=='a') printf("SENIN");
	else if(data=='b') printf("SELASA");
	else printf("Tidak Dikenali");

	printf("\n");
}
