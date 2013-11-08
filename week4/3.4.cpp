#include <iostream>
#include <list>

using namespace std;

list<int> intersection(list<int> L, list<int> R){
 list<int> ret;
 for (list<int>::iterator Li = L.begin(); Li != L.end(); Li++){
  for (list<int>::iterator Ri = R.begin(); Ri != R.end(); Ri++){
   if (*Ri == *Li)
    ret.push_back(*Ri);
  }
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
 list<int> tmp = intersection(L,R);
 //cout << tmp.size()<<endl;
 for (list<int>::iterator itr = tmp.begin(); itr!=tmp.end(); itr++)
  cout << *itr << endl; 
 
 return 0;
}
