#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 unsigned int wintable[64], i, c;
 FILE *code_table, *tex_koi , *to;
 if (argc < 3)
 {
   if ((code_table = fopen(argv[1], "r")) == NULL)
     {
      printf("Oshibka\n"); exit(1);
     } 
  
   for (i = 0; i < 64; ++i)
     { 
   	  fscanf(code_table, "%x" , &wintable[i]);
     } 
   tex_koi = fopen(argv[2], "r");
   to =  fopen(argv[3], "w+");

   while ((c = fgetc(tex_koi)) != EOF)
     {
   	  if (c < 192)
        fputc(c,to);
      else
        fputc(wintable[c - 192],to);
     }
 }
}