// Разработать программу, которая запоминает в двумерном массиве,
// имеющем 5 строк и 4 столбца, числа от 1 до 10, получаемые случайным образом. 
// Заполнить двумерный массив, имеющий 4 строки и 5 столбцов следующим образом:
// элементы строки первого массива становятся столбцами второго массива. 
// Определить суммы элементов строк для каждого массива.

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
        printf("%4d",array[i][j] );
	  }
	printf("\n");
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

void sum_of_strings(int array[][J])
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

void sum_of_strings_for2(int array[][I])
{int i, j,a;
 for (i = 0; i < J; ++i)
   {
    a=0;
    for (j = 0; j < I; ++j)
      {
       a += array[i][j];
      }
    printf("Сумма элементов строки %d = %d\n",i+1, a );
   }
}

void changing(int array[][J], int secray[][I])
{int i, j;
 for (i = 0; i < I; ++i)
   {
   	for (j = 0; j < J; ++j)
   	  {
       secray[j][i] = array[i][j];
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
 int secray[J][I];
 arry_input(array);
 printf("\n*********************\n");
 printf("Вывод первого массива\n");
 printf("*********************\n");
 output(array);
 sum_of_strings(array);
 changing(array, secray);
 printf("\n\n");
 printf("*********************\n");
 printf("Вывод второго массива\n");
 printf("*********************\n");
 output_second(secray);
 sum_of_strings_for2(secray);

}