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
