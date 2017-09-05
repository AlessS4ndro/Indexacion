#include <iostream>
#include <fstream>
#include <string.h>
#include "clases.h"

class Record;
#include "listlink.h"

using namespace std;

class Record
{
  friend ostream & operator<< (ostream &,const Record &);
  friend bool operator == (const Record &,const Record &);    ////////   clase record la cual almacena el nombre
  char key[100];                                              /////////  y la posicion donde se encuentra
  long int address;                                           ///////7    dentro del texto
public:
  Record(char key[],long int address){
    for(int i=0;key[i]!='\0';i++)
      this->key[i]=key[i];
    this->address=address;
  }
  ~Record(){}
  long int get_address(){return address;}
};
ostream & operator<< ( ostream &o,const Record &r)
{
  o<<r.address;o<<"->->";
  for(int i=0;i<100;i++)
    o<<r.key[i];
  return o;
}
bool operator == (const Record &r1,const Record &r2)
{
  for(int i=1;i<6;i++){
    if(r1.key[i]!=r2.key[i]){
      return false;
    }
  }
  return true;

}

int main(int argc,char *argv[])
{
  ListLink<Record> L;
  L.indexar("enfermedades.txt");

  L.read("Cáncer","enfermedades.txt");

  return 0;
}
