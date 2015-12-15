#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define  TRUE 1
#define  FALSE 0
#define  NOTANUM '*'
#define  EVEN 0
#define  ODD  1

typedef struct lis
{
 int num;
 struct lis *next;
}list;

list *first_list_beginning = NULL;
 FILE *go;



int getnum (char );  
void doing_list (int);
list* forming_list (int);
void output (list* ,int);

int main(int argc, char const *argv[])
{
 int digit, c;
 list* sec_list_start = NULL ,* third_list_start= NULL;
 if (argc > 1) 
   {
    if ((go = fopen (argv[1], "w+"))== NULL)
     {
      printf("Ошибка открытия файла.\n");
      exit(1);
     }
   }
 else
   {
   	printf("Не указано имя файла, закрытие программы.\n");
   	return;
   }

 fprintf(go, "Введены цисла:  ");
 do
   {
   	c = getchar();
   	if ((digit = getnum(c) )!= NOTANUM )
   	  {
   	   fprintf(go,"%10d",digit );
       doing_list(digit);
   	  }// end of if
   }while (c != EOF);
 if (first_list_beginning == NULL)
   fprintf(go, "входные данные отсутвуют \n" );
 sec_list_start = forming_list(EVEN);
 third_list_start = forming_list(ODD);
 output(first_list_beginning, 1);
 output(sec_list_start, 2);
 output(third_list_start, 3);

 fclose(go);
}












void output (list *current , int number)
{
 int t =0;
 list *p , *help;
 if (current != NULL)
   fprintf(go,"\n--Список---номер---%d---\n", number);
 for (p = current; p != NULL; p =help)
	{
	 fprintf(go , "Число: %d \n", p -> num );
	 help = p -> next;
	 free(p);
	}
}


list* forming_list (int chetnost)
{
 char NOT_END = 1;
 list *p, *for_struct, *list_start;
 if ((p = first_list_beginning) == NULL)
 	return;
 while (NOT_END)
   {
   	if (p -> num %2 == chetnost)
   	  {
   	   list_start = malloc(sizeof(list));
   	   list_start -> num = p -> num ;
   	   for_struct = list_start;
   	   NOT_END = 0;
   	  }//end of if
   	p = p-> next;
   }//end of while
 while (p != NULL)
   {
   	if (p -> num %2 == chetnost)
   	  {
       for_struct -> next = malloc(sizeof(list));
       for_struct = for_struct -> next;
       for_struct -> num = p -> num;
   	  }//end of if
   	p = p -> next;
   }//end of while
 return list_start;
}//end of func

void doing_list ( int digit)  
{
 list *prev = NULL, *for_struct, *p;
 if (first_list_beginning == NULL)
   { 
    first_list_beginning = malloc(sizeof(list));
    first_list_beginning -> num = digit;
    first_list_beginning -> next = NULL;
    return;
   }
 for_struct = malloc(sizeof(list));
 for_struct -> num = digit;
 for_struct -> next = NULL;
 p = first_list_beginning;
 while (p != NULL)
   {
    if (p -> num >= digit  )
      {

      	for_struct -> next = p;
      	if (prev == NULL)
      	  first_list_beginning = for_struct;
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
       if (p -> next -> num > digit)
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
