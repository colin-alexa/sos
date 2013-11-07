#include <list>
#include <iostream>

using namespace std;

void printLots(list<int> L, list<int> P){
 list<int>::iterator lit = L.begin();
 int i = 0;
 for (list<int>::iterator it = P.begin(); it != P.end(); it++){
  for (;i < (*it) && lit != L.end(); i++, lit++){;}
  cout << *lit << ", ";
 }
 cout << endl;
 return;
}

int main(){
 int l[] = {1,2,3,4,5,6,7,8};
 int p[] = {1,3,5};
 list<int> L (l, l+8);
 list<int> P (p, p+3);
 printLots(L,P);
 return 0;
}
