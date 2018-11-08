#include <stdio.h>

int main(){
	int data=0;
	int *p;
	p=&data;

	printf("address\t: %p\n",p);
	printf("value d\t: %d\n",data);
	printf("value p\t: %d\n",*p);

	*p=225;
	printf("\nvalue d\t: %d\n",data);
	printf("address\t: %p\n",p);

	return 0;
}
