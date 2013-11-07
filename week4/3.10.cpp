#include "myVector.cpp"
#include <iostream>

using namespace std;

int main(){
 Vector<int> a (10);
 Vector<int>::iterator b = a.begin();
 for (int i = 0; i < 100; i++, b++){
  a.push_back(i);
  if (!(i % 5)){
   cout << *b << endl;
  }
 }
 return 0;
}
