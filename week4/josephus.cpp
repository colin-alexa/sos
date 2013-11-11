#include <iostream>

using namespace std;

struct node{
    node * next;
    node * prev;
    int id;
    node(int *n): next(0), prev(0), id(++(*n)) {}
    
    ~node(){
     prev->next = next;
     next->prev = prev;
    }
};

node * makeCircle( int size ){
  int nodes = 0;
  node * current = new node( &nodes );
  node * first = current;
  for (int i = 0; i < size-2; i ++){
    current->next = new node ( &nodes );
    current->next->prev = current;
    current = current->next;
  }
  node * last = new node( &nodes );
  last->next = first;
  first->prev = last;
  last->prev = current;
  current->next = last;
  return first;
}

int josephus(int players, int hops, int * turns){
  node * first = makeCircle( players );
  node * current = first;
  //cout << "Josephus game start. Player "<< current->id << " has the ball." << endl;
  while ( current->next != current ){
    for (int i = 0; i < hops; i++){
      current = current->next;
      *turns = (*turns) + 1;
    }
    node * tmp = current;
    current = current->next;
    //cout << "Player " << tmp->id << " out after " << *turns << " turns.";
    delete tmp;
    //cout << " Play resumes on player "  << current->id << "." << endl;
  }
  return current->id;
}

int main(){
 int n = 10000000;
 int m = 2;
 int turns = 0;
 int winner = josephus(n,m, &turns);
 printf("With %d players, and %d hops between players, the game ends on player %d after %d passes.\n", n, m, winner, turns);
 return 0;
}