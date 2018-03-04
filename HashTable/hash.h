//Ryan Anderson & Brett Weicht
// hash.h

#ifndef HASH_H
#define HASH_H

#include "list.h"

template <class KeyType>
class HashTable
{
	public:
		HashTable(int numSlots);
		HashTable(const HashTable<KeyType>& h);
		~HashTable();
		
		KeyType* get(const KeyType& k) const;
		void insert(KeyType *k);
		void remove(const KeyType& k);
		
		bool empty();
		
		HashTable<KeyType>& operator=(const HashTable<KeyType>& h);
		
		std::string toString(int slot) const;
		
		int Slots;
		List<KeyType> *table;  // an array of List<KeyType>'s
		
		
};

template <class KeyType>
std::ostream& operator<<(std::ostream&, const HashTable<KeyType>& );


class NotFound { };

#include "hash.cpp"

#endif
