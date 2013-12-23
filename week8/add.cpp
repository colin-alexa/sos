#include "add.h"
template <class T>
Adder<T>::Adder(int a){
  x = a;
}
template <class T>
int Adder<T>::add(int a){
 return a+ this->x;
}