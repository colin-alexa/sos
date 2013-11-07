#include "IntCell.cpp"
#include <iostream>

using namespace std;


int main() {
  IntCell m1(5);
  IntCell m2(6);
  IntCell m3 = m2.add(m1);
  cout << m2.read() << ", " << m3.read() << endl;
}
