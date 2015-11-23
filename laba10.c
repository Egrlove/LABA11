
#define BUF 81
#include <stdio.h>

void spacerm (char *buffer)
{int i=0,simvol;
 do
 {
  simvol = buffer[i];
  if (simvol == '	' || simvol == ' ')
  {
   printf("Razdel '%c'\n",simvol ); 
  }
  i++;
 }while (simvol != '\0');
	
}

int main()
{ 
 char buffer[BUF];

 gets(buffer);
 spacerm(buffer);

 printf("%s\n",buffer);

}