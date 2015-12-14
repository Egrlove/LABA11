#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define  TRUE 1
#define  FALSE 0
#define  NOTANUM '*'

typedef struct lis
{
 int num;
 struct lis *next;
}list;

list *beginning = NULL;
 FILE *go;



int getnum (char cur)
{
 char static prev =' ', chislo_idet = 0, chislo_moget_start = 0, est_chislo =0 , i =0 ;
 char  it_will_be_num[20];
 
 if (isspace(prev) != 0 || ispunct(prev) != 0)
    chislo_moget_start = TRUE;
 else 
 	chislo_moget_start = FALSE;


 if ((isdigit(cur) != 0) && (chislo_moget_start || chislo_idet) )
 	{
 	 it_will_be_num[i++] = cur;
 	 chislo_idet = TRUE;
 	}
 else 
    {
     if ((i > 0) && (isdigit(prev) != 0)  && (isalpha(cur) == 0 ))
       {
       	it_will_be_num[i] = '\0';
       	est_chislo = 1;
       	i =0;
       }
     else 
       {
       	i = 0;
       	chislo_moget_start = 0;
       	chislo_idet =0;
       }
    }
    prev = cur;

    if (est_chislo)
      {
       est_chislo =0;
       return atoi(it_will_be_num);
      }
    return NOTANUM ;
}


void output (list *current)
{
	int t =0;
 list *p , *shalom;
 for (p = current; p != NULL; p =shalom)
	{
	 
	 
	 fprintf(go , "Число: %d \n", p -> num );
	 //free(p -> word);
	 shalom = p -> next;
	 t++;
	 //free(p);
	
	}
}


void search ( int dig)  
{
 list *prev = NULL, *for_struct, *p;

 if (beginning == NULL)
   { 
 printf("ошибка 0  %d \n", dig);
    beginning = malloc(sizeof(list));
    beginning -> num = dig;
    beginning -> next = NULL;

    return;
   }
 for_struct = malloc(sizeof(list));
 for_struct -> num = dig;
 for_struct -> next = NULL;
 printf("ошибка 1 \n");
 p = beginning;
 while (p != NULL)
   {
    if (p -> num >= dig  )
      {
      	 printf("ошибка 2 \n");

      	for_struct -> next = p;
      	if (prev == NULL)
      	  beginning = for_struct;
      	else
      	  { prev -> next = for_struct; }
      	return;
      	
      }
    else
      {
       if ( p -> next -> num > dig)

      }
       printf("ошибка 3 \n");

        prev = p;
      	p = p -> next;



    }//end of while





// end of func
}

int main(int argc, char const *argv[])
{
 int  i =0 , first_one = 1;
list *for_struct;
 int lol, c;
 go = fopen ("gig", "w+");
 do
   {
   	c = getchar();
   	if ((lol = getnum(c) )!= NOTANUM )
   	  {
   	   fprintf(go,"%d\n",lol );
   	   //for_struct = malloc(sizeof(list));
       // if ( first_one )
       //   {	
    	  //  beginning -> num = lol;
       // 	   beginning -> next = NULL;
       // 	   first_one = 0;
       // 	   continue;
       // 	 }
       	search(lol);


   	  }






   }while (c != EOF);


  
  printf("------------------------\n");
  output(beginning);

}
/* 
void search (list *beginning, int lol)  
{
 list *prev = NULL, for_struct;
 for (p = beginning; p != NULL  ;prev =p,  p = p -> next)
    {
     if (p -> num >= lol  )
       {
       	for_struct = malloc(sizeof(list));
       	for_struct -> next = p;
       	if (prev != NULL)
       	prev -> next = for_struct;

       }


    }
// end of func
}

*/