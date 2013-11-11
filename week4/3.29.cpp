#include <iostream>
using namespace std;
template <typename T>
class List{
 struct node{
    node * next = NULL;
    T data;
 };
 
 private:
    node * first;
    
 public:
  List() : first( NULL ) {}
  
  void pprint(){
    node * current = first;
    cout << "Head";
    while (current){
      cout << " -> " << current->data;
      current = current->next;
    }
    cout << endl;
  }
  
  int size(){
    int s = 0;
    node * current = first;
    while (current->next){
      s++;
      current = current->next;
    }
    return s;
  }
  
  bool contains(T value){
    node * current = first;
    while (current->next){
      if (current->data == value)
        return true;
      current = current->next;
    }
    return false;
  }
  
  void append(T value){
    node * current = first;
    node * prev = NULL;
    while (current){
      if (current->data == value)
        return;
      prev = current;
      current = current->next;
    }
    current = new node();
    if (prev)
      prev->next = current;
    else
      first = current;
    current->data = value;
  }
  
  bool remove(T value){
    node * current = first;
    while (current->next){
      if (current->next->data == value){
        node* tmp = current->next;
        current->next = current->next->next ? current->next->next : NULL;
        delete tmp;
        return true;
      }
      current = current->next;
    }
    return false;
  }
  
///////////
// Problem 3.29
///////////
  void reverse(){
    node * current = first;
    node * tmp;
    node * prev = NULL;
    while (current){
      tmp = current->next;
      current->next = prev;
      prev = current;
      current = tmp;
    }
    first = prev;
  }
/* I don't think there's a way to do this in constant space with a const method */
  void reverseprint(){
    reverse();
    pprint();
    reverse();
  }

};

int main(){
 List<int> l;
 for (int i = 0; i < 10; i++){
    l.append(i);
 }
 l.pprint();
 l.reverseprint();
 l.pprint();
 return 0;
}