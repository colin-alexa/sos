#ifndef HASHTABLE_H
#define HASHTABLE_H

#define NULL 0

#include <vector>
#include <exception>
#include <iostream>

template <class key_t, class value_t>
class HashTable {
protected:
  class IndexException: public std::exception {
    virtual const char* what() const throw() {
      return "Key Error";
    }
  };
  
  class Element{
  public:
    Element(key_t l, value_t v);
    Element( const Element & rhs);
    key_t key;
    value_t value;
    bool del;
  };
  
  void resize();
  void print();
  
private:
  int elements;
  int size;
  Element** storage;
  
//  int hash(string k);
  int hash(int k);

public:
  static IndexException KeyError;
  
  HashTable<key_t, value_t>();
  HashTable(const HashTable &rhs);
  ~HashTable();
  
  void insertAt( key_t k, value_t v);
  value_t get(key_t k);
  value_t get(key_t k, value_t def);
  void remove(key_t k);
//  friend std::ostream& operator<<(std::ostream s, HashTable<key_t, value_t> rhs);
};
#endif