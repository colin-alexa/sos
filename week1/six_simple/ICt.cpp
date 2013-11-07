#include <iostream>
#include "IC.cpp"

using namespace std;

int main () {
 
 IntCell m1(7);
 IntCell m2(4);
 
 cout << "m2 is: " << m2.read() << endl;
 cout << "m2 + m1 = " << m2.add(m1).read() << endl;
 cout << "m2 += m1; m2 == " << (m2.add_to(m1.read()), m2.read()) << endl;
 cout << "m2 - 3 = " << m2.sub(3).read() << endl;

return 0;
}
