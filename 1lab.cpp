/*
Разработать объектно-ориентированную программу,
которая для каждой точки из заданного набора точек на плоскости ищет наиболее удаленную от нее точку этого набора.
Декартовые координаты его точек должны быть указаны парами целых чисел в аргументах командной строки вызова программы.
Координаты полученных пар точек и расстояния между ними должны отображаться строками стандартного вывода.
В программе должен быть реализован класс точки с приватными полями ее декартовых координат,
публичными методами доступа к ним и конструктором инициализации их значений.
Вычисление расстояния между парами точек должна обеспечивать дружественная функция этого класса.
Кроме того, в программе должно быть предусмотрено динамическое распределение памяти для всех заданных точек и массива их адресов.                                                                                                                                 
*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
class point
{
 private:
  int x;
  int y;
 public:
  point(int xo, int yo) : x(xo), y(yo) {};
  int get_x() {return x;}
  int get_y() {return y;}
  friend double distance (point*,point*);
};

double distance (point *first, point *sec)
{
 double dis = pow((first -> x - sec -> x),2) + pow((first -> y - sec -> y),2);
 return sqrt(dis);
}


int main (int argc,char const *argv[] )
{
 cout<< setprecision(2) << fixed;
 cout.fill('0');
 point **ad;
 int x,y, new_y, new_x;
 double max =-1, dis;
 if (argc < 3)
  {
   cout << "Введено недостаточное количество точек" << endl;
   return -1;
  }
 ad = new point*[argc];
 for (int i=0, j = 1; j < argc  ;  )
   {
     sscanf(argv[j++],"%d%*c%d", &x, &y);
     ad[i] = new point(x,y);
     ad[++i] = NULL;
   }
 for (int i=0,j =0 ; ad[j] != NULL; j++)
   {
    for(i= 0; (ad[i] != NULL) ; i++)
     { if(ad[i] != ad[j])
        {
         dis= distance (ad[j],ad[i]);
         if(max < dis)
           {
           max = dis;
           new_x = ad[i]->get_x ();
           new_y = ad[i]->get_y ();
           }
        }
   }
   cout <<"Максимальным расстоянием от точки (" << ad[j]->get_x ()<<';'<<ad[j]->get_y ()
       <<") является расстояние  " <<max<< " до точки (" << new_x <<';' <<new_y<<") " << endl
       << "-------------------------------------------------------------------------------------"<< endl;
   max =-1;
   }
 for (int i=0 ; ad[i] != NULL; i++)
   {delete ad[i];}
 delete ad;
 return 0;
}


