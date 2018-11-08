#include <stdio.h>

int main(){
	int data;
	int *p;

    printf("alamat %p\n",p);
        printf("value %d\n",*p);
	p=&data;
	data=10;

	return 0;
}
