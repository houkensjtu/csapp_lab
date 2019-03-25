#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
   char buffer[256];

   printf("Enter your name and press [Enter]:\n");
   fgets ( buffer, 256 , stdin );

   printf("Your name has %d characters and spaces!\n",
           strlen( buffer ));

   return 0;
}
