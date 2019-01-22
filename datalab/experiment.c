#include <stdio.h>

int main (void){
    int x = 0x80000000;
    int y = 0x7fffffff;

    long int xx = x;
    long int yy = y;

  long int crt1 = (xx + (~yy+1)) >> 63;

  // If x - y ==0; then crt2 will equal to 0
  long int crt2 = xx + ~yy + 1;

    printf("crt1 = %lx \n",crt1);
    printf("crt2 = %ld \n",!!!crt2);
    printf("My result = %d \n", !!(!!crt1 + !!!crt2));
  return 0;
}