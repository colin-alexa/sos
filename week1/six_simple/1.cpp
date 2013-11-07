#include <iostream>

using namespace std;

int main(){

int a[3];

for (int i = 0; i < 3; i++){
 cout << "enter number: ";
 cin >> a[i];
}

cout << a[2] << ", " << a[1] << ", " << a[0] << endl;
cout << a[0] << ", " << a[1] << ", " << a[2] << endl;

int min = a[0];
int max = a[0];
int sum = a[0];

for (int i = 1; i < 3; i++) {
 if (a[i] < min){
  min = a[i];
 }
 if (a[i] > max){
  max = a[i];
 }
 sum += a[i];
}

cout << max << " = max; " << min << " = min; " << sum/3 << " = avg. " << endl;

return 0;
}
