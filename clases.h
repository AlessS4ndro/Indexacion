#include <iostream>
using namespace std;

template<typename T>
struct NodeSimple
{
  T value;
  NodeSimple *left;
  int index;

  NodeSimple(T v):value(v),left(NULL){}
  ~NodeSimple(){}
};

template <typename U>
struct NodeDouble
{
  U value;
  NodeDouble *right;
  NodeDouble *left;
  int size;

  NodeDouble(U v):left(NULL),right(NULL),size(0),value(v){}
  ~NodeDouble(){}
};

template <typename T>
class ListLink
{
  NodeSimple<T> *head;
  NodeSimple<T> *tail;
  int size;
  bool find (T ,NodeSimple<T> **&);
public:
  ListLink():head(NULL),tail(NULL),size(0){}
  ~ListLink();
  void push_back(T );
  void push_front(T);
  T pop_back();
  T pop_front();
  bool add(T );
  void indexar(char * );
  void read(char *,char *);

  void print();
};

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
