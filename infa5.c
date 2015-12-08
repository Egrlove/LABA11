#include <stdio.h>
#include <stdlib.h>
#define SIZE 64

FILE* opening (const char *name, int num, char* type)
{FILE* help;
 if ((help = fopen(name, type)) == NULL)
   {
    printf("Ошибка в файле номер: #%d \n", num);
    exit(num);
   } 
 else
 	return help;
}
int main(int argc, char const *argv[])
{
 unsigned int wintable[SIZE], i, c;
 FILE *code_table, *tex_koi , *to;
 if (argc > 3)
 {
   code_table = opening (argv[1], 1, "r");
   tex_koi = opening (argv[2], 2, "r");
   to =  opening (argv[3], 3, "w+");
  
   for (i = 0; i < SIZE; ++i)
     { 
   	  fscanf(code_table, "%x" , &wintable[i]);
     } 

   while ((c = fgetc(tex_koi)) != EOF)
     {
   	  if (c < 192)
        fputc(c,to);
      else
        fputc(wintable[c - 192],to);
     }
 }
 else
 	printf("Нет фалов\n");
}
