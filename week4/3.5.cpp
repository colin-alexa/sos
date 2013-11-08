#include <iostream>
#include <list>

using namespace std;

bool in(int a, list<int> & b){
  for (list<int>::iterator Li = b.begin(); Li != b.end(); Li++){
   if (*Li==a)
    return 1;
  }
  return 0;
}

list<int> u(list<int> L, list<int> R){
 list<int> ret;
 for (list<int>::iterator Li = L.begin(); Li != L.end(); Li++){
  ret.push_back(*Li);   
 }
 for (list<int>::iterator Ri = R.begin(); Ri != R.end(); Ri++){
   if (in(*Ri, ret))
    continue;
   ret.push_back(*Ri);
 }
 return ret;
}

int main(){
 list<int> L;
 list<int> R;
 for (int i=0; i < 10; i++){
  L.push_back(i);
 }
 for (int i=5; i < 15; i++){
  R.push_back(i);
 }
 list<int> tmp = u(L,R);
 //cout << tmp.size()<<endl;
 for (list<int>::iterator itr = tmp.begin(); itr!=tmp.end(); itr++)
  cout << *itr << endl; 
 
 return 0;
}
