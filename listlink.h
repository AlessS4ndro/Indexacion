template <typename U>
void ListLink<U>::print()
{
    NodeSimple<U> *n=head;
    while(n){
      cout<<n->value<<"--";
      n=n->left;
    }
    cout<<endl;
}

template<typename T>
void ListLink<T>::push_back(T val)
{
  NodeSimple<T> *n=new NodeSimple<T>(val);

  if(head){
    tail->left=n;
    tail=tail->left;
  }
  else{
    head=n;
    tail=n;
  }
  size++;
}

template <typename T>
void ListLink<T>::push_front(T val)
{
  NodeSimple<T> *n=new NodeSimple<T>(val);

  if(head==NULL){
    tail=n;
  }
  n->left=head;
  head=n;
  size++;
}

template<typename T>
T ListLink<T>::pop_front()
{
  if(head){
    NodeSimple<T> *n=head;
    T retornable;
    head=head->left;
    retornable=n->value;    //////7   para no perder  el valor
    delete n;
    size--;
    return retornable;
  }
}
template<typename T>
T ListLink<T>::pop_back()
{
  if(head){
    NodeSimple<T> *n=head;
    T retornable;
    while(n->left!=tail)
      n=n->left;
    retornable=tail->value;   ////////    para no perder el valor
    delete tail;
    tail=n;
    n->left=NULL;
    size--;
    return retornable;
  }
}
template<typename T>
bool ListLink<T>::find(T d,NodeSimple<T> **& p)
{
  p=&head;
  while(*p){

    //if((*p)->value>d) return false;   comentamos para indexacion
    p=&(*p)->left;
  }
  return false;
}

template<typename T>
bool ListLink<T>::add(T val)
{
  NodeSimple<T> **p;
  if(!find(val,p)){
    NodeSimple<T> *nuevo=new NodeSimple<T>(val);
    nuevo->left=(*p);
    *p=nuevo;
    size++;
    return true;
  }
  return false;
}

template<typename T>
void ListLink<T>:: indexar(char * filename)
{
  ifstream file(filename);
  long int address = 0;
  char information[5000];
  char key[100];


  while(!file.eof()){
    file.getline(key,100,'#');
    file.getline(information,5000,'@');
    Record R(key,address);
    add(R);
    address=address + strlen(key)+strlen(information)+3;

  }
  file.close();
}

template<typename T>
void ListLink<T>::read(char * key,char * filename)
{
  NodeSimple<T> **p;
  if(find(Record(key,0),p)){
    char info[10000];
    long int address=(*p)->value.get_address();
    ifstream file(filename);
    file.seekg(ios::beg);
    file.seekg(address);
    file.getline(info,10000,'@');
    file.close();
  }
}
template<typename T>
ListLink<T>::~ListLink()
{
  NodeSimple<T> *n;
  do{
    if(!head) return;
    n=head;
    head=head->left;  ////////  apuntas ,saltas ,borras
    delete n;
  }while(head);
  head=tail=NULL;
}
