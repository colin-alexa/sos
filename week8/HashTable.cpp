#include "HashTable.h"

template <class key_t, class value_t>
typename HashTable<key_t, value_t>::IndexException HashTable<key_t, value_t>::KeyError = *(new IndexException);


template <class key_t, class value_t>
HashTable<key_t, value_t>::Element::Element(key_t k, value_t v){
  key = k;
  value = v;
  del = false;
}

template <class key_t, class value_t>
HashTable<key_t, value_t>::Element::Element(const Element & rhs){
  key = rhs.key;
  value = rhs.value;
  del = rhs.del;
}


template <class key_t, class value_t>
HashTable<key_t, value_t>::HashTable(){
  elements = 0;
  storage = new Element*[11];
  size = 11;
  
  for (int i=0; i != size; i++) storage[i] = NULL;
}

template <class key_t, class value_t>
HashTable<key_t, value_t>::HashTable(const HashTable & rhs){
  elements = rhs.elements;
  storage = new Element*[rhs.size];
  size = rhs.size;
  
  for (int i=0; i != size; i++) 
    if (rhs.storage[i]) 
      storage[i] = new Element (*rhs.storage[i]);
    else
      storage[i] = NULL;
}

template <class key_t, class value_t>
HashTable<key_t, value_t>::~HashTable(){
  for (int i=0; i != size; i++){
    if (storage[i]) delete storage[i];
  }
}

template <class key_t, class value_t>
void HashTable<key_t, value_t>::print(){
  std::cout << "i: (key, value, del)" << std::endl;
  
  for (int i=0; i != size; i++){
    if (storage[i])
      std::cout << i << ": (" << storage[i]->key << ", " << storage[i]->value << ", " << storage[i]->del << ")" << std::endl;
    else
      std::cout << i << ": (empty)" << std::endl;
  }
  
}


template <class key_t, class value_t>
int HashTable<key_t, value_t>::hash(int k){
  return k % this->size;
}


template <class key_t, class value_t>
void HashTable<key_t, value_t>::insertAt(key_t k, value_t v){
  std::cout << "Inserting " << v << " at " << k << std::endl;
  Element *item = new Element(k, v);
  int index = hash(k);
  
  while (storage[index % size]){		   // technically index % size is equivalent to hash(index), but this way allows the hash function to be reimplemented easily, and is clearer

    if (storage[index % size]->key == k) throw KeyError;
    
    index++;
  }
  storage[index % size] = item;
  elements++;
  
  if (elements > (2 * size/3)) resize();
}

template <class key_t, class value_t>
value_t HashTable<key_t, value_t>::get(key_t k){
  std::cout << "Getting " << k << std::endl;
  int index = hash(k);
  Element *cur = storage[index % size];
  
  if ( cur == NULL ) throw HashTable::KeyError;
  
  while ((cur->key != k) || storage[index % size]->del) {           // forward-probing for the correct element
    index++;
    cur = storage[index % size];
    
    if (cur == NULL) throw HashTable::KeyError;    // If ever cur == NULL then the key isn't in the table
  }
  return cur->value;
}

template <class key_t, class value_t>
value_t HashTable<key_t, value_t>::get(key_t k, value_t def){
  std::cout << "Getting " << k << std::endl;
  int index = hash(k);
  Element *cur = storage[index % size];
  
  if ( cur == NULL ) return def;
  
  while ((cur->key != k) || storage[index % size]->del) {           // forward-probing for the correct element
    index++;
    cur = storage[index % size];
    
    if (cur == NULL) return def;    // If ever cur == NULL then the key isn't in the table
  }
  return cur->value;
}

template <class key_t, class value_t>
void HashTable<key_t, value_t>::remove(key_t k){
    std::cout << "Removing " << k << std::endl;
  int index = hash(k);
  Element *cur = storage[index % size];
  
  if ( cur == NULL ) throw HashTable::KeyError;
  
  while ((cur->key != k) || storage[index % size]->del) {           // forward-probing for the correct element
    
    index++;
    cur = storage[index % size];
    
    if (cur == NULL) throw HashTable::KeyError;    // If ever cur == NULL then the key isn't in the table
  }
  cur->del = true;
}

template <class key_t, class value_t>
void HashTable<key_t, value_t>::resize(){
  std::cout << "Resizing" << std::endl;
  
  int oldsize = size;
  size = size*2 + 1;
  Element** tmp = new Element*[size];
  
  for (int i=0; i != size; i++) tmp[i] = NULL;
  
  for (int i=0; i != oldsize; i++){
    
    if (storage[i]){
      if (storage[i]->del){
	delete storage[i];
	elements--;
      }
      else {
        tmp[hash(storage[i]->key)] = storage[i];
      }
    }
  }
  storage = tmp;
}