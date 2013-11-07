#include "MemoryCell.cpp"
#include <iostream>
using namespace std;

int main(){
 MemoryCell<int> m1,m2;
 m1.write(37);
 m2.write(2);
 cout << m2 << endl << (m2 <= m1) << endl;
 

return 0;
}
