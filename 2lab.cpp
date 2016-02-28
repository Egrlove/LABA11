#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Magic {
  private:
    unsigned** tab;
    int row;
    int col;
    int degree;
  public:
    Magic(int);
    ~Magic();
    void print();
    void moscopul();
    int reflect(int);
};



Magic::Magic(int n) {
  degree = n;
  tab = new unsigned* [degree];
  for(row=0; row < degree; row++)
    {
     tab[row] = new unsigned [degree];
     memset(tab[row], 0 , degree );
    }
}


Magic::~Magic() {
  for(row=0; row < degree; row++)
    delete [] tab[row];
  delete [] tab;
}


void Magic::print() {
  int degree2;
  int len = 0;
  degree2 = (degree * degree);
  while(degree2 > 0) {
      degree2 /= 10;
      len++;
    }
  for(row=0; row < degree; row++)
    {
     for(col=0; col < degree; col++)
       cout<< setfill('0')<< setw(len)<< tab[row][col]<<"  ";
     cout << endl;
    }
}

int Magic::reflect(int k) {
  if(k < 0)
    return(k + degree);
  if(k > (degree - 1))
    return(k - degree);
  return(k);
}


void Magic::moscopul() {
  int i;
  int j;
  int degree2 = (degree*degree);
  int z = 1;
  row = (0);
  col = (degree / 2);
  tab[row][col] = z;
  while(z < degree2) {
      i = reflect(row + 2);
      j = reflect(col - 1);
      if(tab[i][j] > 0) {
          i = reflect(row + 4);
          j = reflect(col);
        } // if
      row = i;  col = j;
      tab[row][col] = ++z;
    } // while
  return;
}

int main(int argc, char* argv[]) {
  if(argc < 2)
   { cout << "Введите степень квадрата"<< endl;  return -1; }

  int n = atoi(argv[1]);
  if((n % 2) == 0)
    { cout <<"Введите нечетное число" <<endl;  return n; }
  Magic mag(n);
  mag.moscopul();
  mag.print();
  return(0);
}
