#include "ICP.cpp"
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

 cout << n[2]->read() << endl;
 n[2]->write(5);
 cout << n[2]->read() << ", " << m[2].read() << endl;
 
}
