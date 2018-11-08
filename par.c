#include <stdio.h>


int main()
{
float R = 0.;
float r = 0.;

printf("Please enter the resistors value (enter zero to stop):\n");

do {
    scanf("%f", &r);

    if (r != 0.) {
        R += (1/r);
    }
}
while(r != 0.);

if (R != 0.) {
    R = 1/R;
}

printf("\nTotal: %.2f", R);

return 0;
}
