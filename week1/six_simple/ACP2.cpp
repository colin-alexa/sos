#include "ICPointers2.cpp"
#include <iostream>
#include <array>

using namespace std;

int main() {
  IntCell m[5];
  IntCell *n[5];

for (int i =0; i < 5 ; i ++){
  m[i] = IntCell(i);
  n[i] = &m[i];
}

 cout << *n[2] << endl;
 n[2]->write(5);
 cout << *n[2] << ", " << m[2] << endl;
 
}
