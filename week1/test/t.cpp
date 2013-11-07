#include <iostream>
#include <fstream>
using namespace std;


int main(){
  ifstream f;
  f.open("file2");
  cout << f << endl;
  return 0;
}
