#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define I 5
#define J 4


void output (int array[][J] )
{int i,j;
 for (i = 0; i < I; ++i)
   {
	for (j = 0; j < J; ++j)
	  {
        printf("%3d",array[i][j] );
	  }
	printf("\n");
   }
}


void obnyl (int array[][J])
{int i, j;
  for (i = 0; i < I; ++i)
   {
 	for (j = 0;j < J; ++j)
 	  {
 	   array[i][j]=0;
 	  }
   }
}

int input(void)
{int s;
 return( (s = rand() % 10) + 1);
}

void arry_input (int array[][J])
{int i, j;
 for (i = 0; i < I; ++i)
   {

   	for (j = 0; j < J; ++j)
   	  {
       array[i][j] = input();
   	  }
   }
}

void plusplus(int array[][I])
{int i, j,a;
 for (i = 0; i < I; ++i)
   {
   	a=0;
   	for (j = 0; j < J; ++j)
   	  {
       a += array[i][j];
   	  }
   	printf("Сумма элементов строки %d = %d\n",i+1, a );
   }
}

void changing(int array[][J], int crab[][I])
{int i, j;
 for (i = 0; i < I; ++i)
   {
   	for (j = 0; j < J; ++j)
   	  {
       crab[j][i] = array[i][j];
   	  }
   }
}


void output_second (int array[][I] )
{int i,j;
 for (i = 0; i < J; ++i)
   {
	for (j = 0; j < I; ++j)
	  {
        printf("%4d",array[i][j] );
	  }
	printf("\n");
   }
}


int main()
{
 srand(time(NULL));
 int array[I][J];
 int crab[J][I];
 arry_input(array);
 output(array);
 // plusplus(array);
 changing(array, crab);
 printf("\n\n\n");
 output_second(crab);

}