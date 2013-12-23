#include "HashTable.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
  HashTable<int, string> t;
  for (int k=0; k < 100; k++){
    int l = k*42;
  for (int i=l; i < l+42; i++)
    t.insertAt(i, "Foo");
  
  for (int i=l; i < l+42; i +=2)
    t.remove(i);
  }
  for (int i=0; i < 4200; i+=5)
    cout << t.get(i, "None");
  
  cout << "Done!" << endl;
  
}