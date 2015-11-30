#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUF 40

int words (char charcter)
{
 static int simvl; 
 int raz = 0;
  switch (charcter)
 {
   case 9 : case 10 : case 11 : case 32 :
     raz = 1; break; 
   default :
     raz = 0; break;
 }
 if (simvl > 0 && raz > 0)
  {
   simvl = 0;
   return 1;
  }
 simvl = 1 - raz;
 return 0;
}

struct new_word
{
 char *only_word;
 struct new_word *previous;
};

void out (struct new_word *current, FILE *fp)
{
	    struct new_word *p;
 for (p = current; p != NULL; p = p -> previous)
	{
	 fprintf(fp,  "%s\n",p -> only_word );
	 free(p);
	}
}

int main(int argc, char const *argv[])
{
 FILE *fp;
 char buffer[BUF];
 int  i = 0  ;
 char charcter, *for_word ;
 struct new_word *for_struct , *current = NULL;
   if ( (fp = fopen(argv[1], "w+" )) == NULL )
      {	printf("Error\n"); return 0;}
   
 while ((charcter = getchar()) != EOF)
   {
    if ( words(charcter) != 1)
      {
       if (isalpha(charcter))
        buffer[i++] = charcter;
      }
    else 
      {
       buffer[i] = '\0';
       if ( (for_word = (char*)malloc( sizeof(char) * i)) == NULL)
	      { printf("Error\n"); return 0; }
	   strcpy(for_word , buffer);
	   i =0;
	   if ( (for_struct = malloc( sizeof(struct new_word))) == NULL )
	      {	printf("Error\n"); return 0; }
       for_struct -> only_word = for_word;
       for_struct -> previous  = current;
       current = for_struct;
      }
   }
out(current, fp);
}