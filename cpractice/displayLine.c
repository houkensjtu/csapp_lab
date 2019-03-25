#include <stdio.h>

void display_line(void);

int main(int argc, char const *argv[])
{
   display_line();
   printf("Teach yourself C in one hour a day! \n");
   display_line();
   return 0;
}

/* Print asterisk line */
void display_line(void){
   for(int i = 0; i < 36; i++) printf("*");
   printf("\n");
}