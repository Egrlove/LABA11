#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Fraction {
  private:
    int nom; 
    int den; 
  public:
    Fraction(char*);
    Fraction(int n=0, int m=1) : nom(n), den(m) {};
    Fraction operator/(Fraction );
    Fraction operator=(Fraction);
    operator char*();
    void reduce();
}; 
//====================================================
int euclide(int n, int m)
{
 int r = 1; 
 while(n != 0) 
 {
   r = m % n;
   m = n; 
   n = r; 
 }
return(m); 
} 
//====================================================
Fraction::Fraction(char* s)
{
 char* p = strchr(s, '/'); 
 den = 1; 
 if(p != NULL)
   den = atoi(++p); 
 nom = atoi(s);
}
//====================================================
Fraction::operator char* ()
{
 static char s[32]; 
 sprintf(s, "%d/%d", nom, den); 
 return s; 
}
//====================================================
void Fraction::reduce() 
{
 int nod;    
 nod = euclide(abs(nom), den);
 nom /= nod; 
 den /= nod; 
}
//====================================================
Fraction Fraction::operator/(Fraction delit)
{
 den *= delit.nom;
 return *this;
}
//====================================================
Fraction Fraction::operator=(Fraction now)
{
 den = now.den;
 nom = now.nom;
 return *this;
}
//====================================================
int main(int argc, char* argv[])
{
 int num;
 if (argc < 3) 
   return(puts("Введите строку в формате 'числитель/знаменатель__целое число'."));

 if ((num = atoi(argv[2])) == 0)
   return(puts("На ноль делить нельзя, введите число"));

 Fraction x(argv[1]);  
 Fraction y(num, 1);      
 Fraction z;
 //cout <<"Z " << (char*)z     << endl;
 //cout << "-------------"     << endl;
 cout <<"Было " << (char*) x << endl;
 x.reduce();
 cout <<"Стало " << (char*)x << endl;
 cout << "-------------------------"     << endl;
 cout <<"Число в дробном виде " << (char*) y << endl;
 z = x / y;
 cout << "-------------------------"     << endl;
 cout <<"Результат " << (char*)z     << endl;
 return(0); 
} 