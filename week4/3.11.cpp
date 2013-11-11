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
  List() : first( new node ) {}
  
  void pprint(){
    node * current = first;
    while (current->next->next){
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << current->data << endl;
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
    while (current->next){
      if (current->data == value)
        return;
      current = current->next;
    }
    current->next = new node();
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

};

int main(){
 List<int> l;
 for (int i = 0; i < 10; i++){
    l.append(i);
 }
 l.pprint();
 l.remove(5);
 l.pprint();
 l.remove(9);
 l.pprint();
 return 0;
}