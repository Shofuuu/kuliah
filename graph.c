#include <stdio.h>
#include <sfngraphic.h>

int main(){
	draw_grub(1,1,30,10,"Design Grub");
		writes("inside the grub");
	draw_box(31,1,61,10);
		writes("inside the 2nd box");
	move(0,12);
}
