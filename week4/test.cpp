#include "myVector.cpp"
#include <iostream>

using namespace std;

int main(){
 int m[10];
 int * a = m;
 int * b = &m[9];
 cout << (a++ == b) << endl;
 return 0;
}
