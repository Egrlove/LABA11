/*
Если выбрано некоторое универсальное множество U, то возникает новая теоретико-множественная операция — дополнение.
Для всякого множества М (при этом подразумевается, что М — подмножество универсального множества U его дополнение,
обозначаемое через М, — это множество всех элементов универсума, которые не принадлежат множеству М
*/

#include <ctype.h>
#include <iostream>

using namespace std;


class Alpha{
private:
	unsigned bin; 
public:
	Alpha() {bin=0;};
	Alpha(Alpha& y) {bin=y.bin;};
	Alpha(char*);
	Alpha operator +(Alpha&);	
	Alpha operator ~();
	operator char*();
	friend ostream& operator << (ostream&,Alpha&);
};
//====================================================
Alpha::Alpha(char* s)
{ 
	bin=0;
	while(*s)
	  {
		bin |= (1 << (tolower(*s)-'a'));
		s++;
	  }
}
//====================================================
Alpha Alpha:: operator~()
{
 unsigned int b = bin;
 Alpha z;
 z.bin = ~b;
 return (z);
}
//====================================================
Alpha Alpha:: operator+(Alpha& y)
{ 
	Alpha z;
	z.bin=bin | y.bin;
	return(z);
}
//====================================================
ostream& operator << (ostream& out,Alpha& z)
{ 
	unsigned  bit=1;
	int i;
	for(i=0; i<26;i++){
		if((z.bin& bit)>0)
			out<<(char)('a'+i);
		bit=bit<<1;
	}
	return out;
}
//====================================================
Alpha::operator char*(){ 
	static  char s[32];
	unsigned  b=bin;
	int i=0,j=0,w;
	while(w>0)
	  {
	   if(w & 1)
	     s[j++]='a'+i;
	   i++;
	   w>>1;
	  }//while
	s[j]='\0';
	return (s);
}
//====================================================
int main (int argc,char* argv[])
{ 
 if (argc < 3)
   {
 	cout << "Введено недостаточное количество аргументов" << endl;
    return (-1);
   }

 Alpha x(argv[1]); 
 Alpha y(argv[2]); 
 Alpha z; 
 z = ~x;
 cout<<z<<endl; 
 return (0);
}