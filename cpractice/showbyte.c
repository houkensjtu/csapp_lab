#include <stdio.h>
typedef char* bytepointer;
int main(void)
{
   int x = 1111111;
   bytepointer bp = &x;
   for (int i = 0; i < 4; i++){
   printf("%.2x ", bp[i]);
   }
   printf("\n");
   return 0;
}
