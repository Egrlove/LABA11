#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 40

//=====================================================
typedef struct lis
{
 char * word;
 int len_of_word;
 struct lis *next;
}list;
//=====================================================
void doing_list (char*, int*);
char* pointer_on_word (char,int*);
void output (list *current)
{
 list *p , *help;
 int max_len = current-> len_of_word;
 for (p = current; p != NULL; p =help)
	{
	 if (p->len_of_word == max_len)
	   printf( "Слово: %s %d \n", p -> word, p->len_of_word );
	 help = p -> next;
	 free(p);
	}
}
//=====================================================

list *list_beginning = NULL;

int main(int argc, char const *argv[])
{
 FILE *fp; 
 char *for_word;
 int len1, c;
 int *len = &len1;

 if ( (fp = fopen(argv[1], "r+" )) == NULL )
   { printf("Не удалось открыть файл\n"); exit (1); }
 do
   {
   	c = fgetc(fp);
   	if ( (for_word = pointer_on_word(c,len)) != NULL  )
   	  {
       doing_list(for_word, len);
   	  }// end of if
   }while (c != EOF);
 output(list_beginning);
}//end of main

//=====================================================
char* pointer_on_word (char Ncharacter, int* len)
{
 char buf[BUFSIZE] ,*for_word,character;
 static int simvl,i = 0, flag = 0;
 int raz = 0;
 character = tolower(Ncharacter);
 if (isspace(character) != 0 || character == EOF)
  raz = 1;
 else
 {
  if ((strchr(buf,(int)character)!= 0 )||(isalpha(character) == 0) )
  	flag =1 ;
  buf[i]= character;
  *len = ++i;
  buf[i] = '\0';
 } 
 if (simvl > 0 && raz > 0)
  {
   simvl = 0;
   i=0;
   if (flag ==0)
   	 {
      for_word = (char*)malloc(i * sizeof(char));
      strcpy(for_word,buf);
      return for_word;
     }
   flag =0;
  }
 simvl = 1 - raz;
 return  NULL;
}
//=====================================================
void doing_list ( char* new_word, int *len)  
{
 list *prev = NULL, *for_struct, *p;
 if (list_beginning == NULL)
   { 
    list_beginning = malloc(sizeof(list));
    list_beginning -> word = new_word;
    list_beginning -> len_of_word = *len;
    list_beginning -> next = NULL;
    return;
   }
 for(p = list_beginning; p != NULL; p =p-> next)
   {if(strcmp(new_word,p->word)== 0)
      {
      free(new_word);	
      return;}}
 for_struct = malloc(sizeof(list));
 for_struct -> word = new_word;
 for_struct -> len_of_word = *len;
 for_struct -> next = NULL;
 p = list_beginning;
 while (p != NULL)
   {
    if (p -> len_of_word <= *len  )
      {
      	for_struct -> next = p;
      	if (prev == NULL)
      	  list_beginning = for_struct;
      	else
      	  { prev -> next = for_struct; }
      	return;
      }
    else
      {
       if (p -> next == NULL)
       	 {
       	  p -> next = for_struct;
       	  return;
       	 }
       if (p -> next -> len_of_word < *len)
         {
          for_struct ->next = p -> next;
          p -> next = for_struct;
          return;
         }
      }
    prev = p;
    p = p -> next;
    }//end of while    
} // end of func
//=====================================================