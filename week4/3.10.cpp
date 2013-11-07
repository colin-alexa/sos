#include "myVector.cpp"
#include <iostream>

using namespace std;

int main(){
 Vector<int> a (10);
 for (int i = 0; i < 10; i++){
  a.push_back(i);
 }
 Vector<int>::iterator b = a.begin();
 for (int i = 0; i < 10; i++){
  cout << *b << endl;
  b += 1;
 }
 return 0;
}
