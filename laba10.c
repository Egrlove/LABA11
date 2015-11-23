#define BUF 82
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int spacerm (char *buffer)
{int i=0,simvol, razdel = 0;
 do
 {
  simvol = buffer[i];
  if (simvol == '	' || simvol == ' ')
    {
     razdel++;
    }
  i++;
 }while (simvol != '\0');
 return razdel;
}

void copy (char *buffer,char *p,int simvol )
{int  i;
 char *a, some_char ;
 for (a = p , i = 0;  i < simvol - 1 ; i++)
   { 
   	some_char = buffer[i];
   	if ((some_char != ' ') && (some_char != '	'))
   	  {*a = some_char;
   	  	a++;
   	  }
   }
   *a = '\n';   
   a++;
   *a = '\0';
}

int main()
{
 char *p, *a ;
 int razdel, simvol, i=0,j;
 char buffer[BUF];
 char *strings[10];
 
 printf("Вводите строки длиной до 80 символов\n");
 printf("Для окончания ввода , введите пустую строку\n");
 do{
 fgets(buffer,BUF,stdin);
 razdel = spacerm(buffer);
 simvol = strlen(buffer) + 2;
 simvol -= razdel;
 if ( (p = (char*)malloc( sizeof(char) * simvol)) == NULL)
	{printf("Error\n"); return 0;}
 copy(buffer, p , simvol);
 strings[i] = p;
 i++;
 }while (buffer[0] != '\n' );
 printf("------------------------------\n");
 for (j = 0; j < i - 1; ++j)
   {
 	printf("Строка #%d : \n%s",j + 1, strings[j] );
   }
}
