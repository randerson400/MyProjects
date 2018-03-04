/*=================================
 Ryan Anderson & Brett Weicht
 dict.h
 =================================*/


#include <iostream>
#include "hash.h"

template <class KeyType> 
class Dict: public HashTable<KeyType>
{
  public:
  	  Dict():HashTable<KeyType>(1000) {}
  	  Dict(const Dict &d):HashTable<KeyType>(d){}
  	 // ~Dict() {HashTable<KeyType>::~HashTable();}
  	  
  	  void insert(KeyType *k) {if (get(*k)==NULL){HashTable<KeyType>::insert(k);}}
  	  void remove(KeyType k) {HashTable<KeyType>::remove(k);}
  	  KeyType* get(const KeyType k) {return HashTable<KeyType>::get(k);}
  	  bool empty() {return HashTable<KeyType>::empty();}
  	    
};

