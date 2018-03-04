// Ryan Anderson & Brett Weicht
// April 12, 2017
// hash.cpp


#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "list.h"

using namespace std;

// default constructor
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
	Slots = numSlots;
	table = new List<KeyType>[Slots];
}

// copy constructor
template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h)
{
	Slots = h.Slots;
	table = new List<KeyType>[Slots];
	for (int i=0; i<Slots; i++)
		table[i] = h.table[i];		
}

// destructor
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
	delete [] table;
}
	
// get 
// precondition: k is in the hash table, returns NULL otherwise
// postcondition: k is returned from the hash table
template <class KeyType>	
KeyType* HashTable<KeyType>::get(const KeyType& k) const
{
	// getItem will return NULL if the item is not found, therefore
	//  get will also return NULL if the item is not found.
	KeyType* key = table[k.hash(Slots)].getItem(k);
	
	return key;	
}

// insert
// precondition: k is of the same KeyType as the hash table
// postcondition: the hash table contatains k 
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{
	table[k->hash(Slots)].insert(0, k);
}

// remove
// precondition: k is in the hash table, if not does nothing
// postcondition: k is no longer in hash table
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{
	table[k.hash(Slots)].remove(k);
}

// empty
// precondition: 
// postcondition: returns true if no elements in hash table, false otherwise
template <class KeyType> 
bool HashTable<KeyType>::empty()
{
	for(int i = 0; i<Slots; i++)
	{
		if(table[i].length() != 0)
			return false;
	}		
	return true;
}

// assignment operator
// precondition: h is a valid hash table 
// postcondition: 
template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h)
{
	delete this;
	Slots = h.Slots;
	table = new List<KeyType>[Slots];
	for (int i=0; i<Slots; i++)
		table[i] = h.table[i];
	return *this;
}

// to String method
// precondition: slot must be within m
template <class KeyType>
string HashTable<KeyType>::toString(int slot) const
{
	// loops around to prevent index out of range
	if (slot > Slosts)
		slot = slot - Slots;
	stringstream s;
	s << table[slot];
	return s.str();
	
}

// cout << overload
template <class KeyType>
ostream& operator<<(ostream& os, const HashTable<KeyType>& h)
{
	for(int i=0; i<h.Slots; i++)
		os << h.toString(i);
	return os;
}
	


