#include <iostream>
#include "IC.cpp"

using namespace std;

int main(){

IntCell a[3];

for (int i = 0; i < 3; i++){
 int tmp;
 cout << "enter number: ";
 cin >> tmp;
 a[i].write(tmp);
 
}

cout << a[2].read() << ", " << a[1].read() << ", " << a[0].read() << endl;
cout << a[0].read() << ", " << a[1].read() << ", " << a[2].read() << endl;

int min = a[0].read();
int max = a[0].read();
int sum = a[0].read();

for (int i = 1; i < 3; i++) {
 if (a[i].read() < min){
  min = a[i].read();
 }
 else if (a[i].read() > max){
  max = a[i].read();
 }
 sum += a[i].read();
}

cout << max << " = max; " << min << " = min; " << sum/3 << " = avg. " << endl;

return 0;
}
