#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUF 40

int words (char character)
{
 static int simvl; 
 int raz = 0;
 if (isspace(character))
 	raz = 1;

 if (simvl > 0 && raz > 0)
  {
   simvl = 0;
   return 1;
  }
 simvl = 1 - raz;
 return 0;
}

struct new_word {
 char *only_word;
 struct new_word *previous; };

void output (struct new_word *current, FILE *fp)
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
 char character, *for_word ;
 struct new_word *for_struct , *current = NULL;
 if ( (fp = fopen(argv[1], "w+" )) == NULL )
      {	printf("Не удалось открыть файл\n"); exit (1);}
   
 while ((character = getchar()) != EOF)
   {
    if ( words(character) != 1 && i < BUF -1)
      {
       if (isalpha(character))
        buffer[i++] = character;
      }
    else 
      {
       if (i > 0)
         {
         buffer[i] = '\0';
         if ( (for_word = (char*)malloc( sizeof(char) * i))== NULL)
	        { printf("Error\n");  exit (1); }
	     strcpy(for_word , buffer);
	     i =0;
	     if ( (for_struct = malloc( sizeof(struct new_word)))==NULL)
	        { printf("Error\n");  exit (1); }
         for_struct -> only_word = for_word;
         for_struct -> previous  = current;
         current = for_struct;
        }
      }
   }
output(current, fp);
fclose(fp);
}
