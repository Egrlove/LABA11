#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 26

struct Sword
{
 char * word;
 int counter ;
 struct Sword *next;
};

char* pointer_on_word (char character)
{
 char buf[BUFSIZE] ,*for_word;
 static int simvl,i = BUFSIZE;
 int raz = 0;

 if (i == BUFSIZE) i =0;
 if (isspace(character) != 0 || character == EOF)
  raz = 1;
 else
 {
  buf[i++]= character;
  buf[i] = '\0';  
  if (i == BUFSIZE)
	  {
	   for_word = (char*)malloc(i * sizeof(char));
	   strcpy(for_word,buf);
	   return for_word;
	  }
 }
 if (simvl > 0 && raz > 0)
  {
   simvl = 0;
   for_word = (char*)malloc(i * sizeof(char));
   strcpy(for_word,buf);
   i= BUFSIZE;
   return for_word;
  }
 simvl = 1 - raz;
 return  NULL;
}

void output (struct Sword *current)
{
 struct Sword *p , *shalom;
 for (p = current; p != NULL; p =shalom)
	{
	 printf("Повторений : %2d  %s \n", p -> counter,p -> word );
	 free(p -> word);
	 shalom = p -> next;
	 free(p);
	}
}


int main()
{
int a = 0, c, FLAG = 6, Final;
struct Sword  *for_struct, *beginning, *last, *p;
char *for_word;
 do
   {
    c = getchar();
    if ( (for_word = pointer_on_word(c)) != NULL  )
      {
      	Final = 1;
        for_struct = malloc(sizeof(struct Sword));
        for (p = beginning; p != NULL && Final == 1 ; p = p -> next)
	       {
	        if ( strcmp(p->word, for_word) == 0 )
    	      {
    	       p -> counter++;
    	       Final =0;
	          }
           }
        if (Final)
          {
      	   if (FLAG != 0)
      	     {
      	      last = beginning = for_struct;
              beginning -> word = for_word;
              beginning -> counter = 1;
      	      beginning -> next = NULL;
      	      FLAG = 0;
      	      continue;
      	     }
           for_struct -> word = for_word;
           for_struct -> counter = 1;
           for_struct -> next = NULL;
           last -> next = for_struct;
           last = for_struct;
          }
       }
    } while (c != EOF );

 output(beginning);
}
