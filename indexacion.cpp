#include <iostream>
#include <fstream>
#include <string.h>
#include "Lista-Enlazada/clases.h"
class Record;
#include "Lista-Enlazada/listlink.h"

using namespace std;

class Record
{
  friend ostream & operator<< (ostream &,const Record &);
  friend bool operator == (const Record &,const Record &);
  char *key;
  long int address;
public:
  Record(char key[],long int address){
    this->key=key;
    this->address=address;
  }
  ~Record(){}
};
ostream & operator<< ( ostream &o,const Record &r)
{
  o<<r.address;
  return o;
}
bool operator == (const Record &r1,const Record &r2)
{
  return r1.key==r2.key;
}

int main(int argc,char *argv[])
{
  ListLink<Record> L;
  L.indexar("enfermedades.txt");
/*
  ListLink<int > L;
  for (int i =0;i<10;i++)
    L.add(i);
    */
  L.print();
  return 0;
}
