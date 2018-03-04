// test_hash.cpp

#include <iostream>

#include "hash.h"
#include "Int.h"
#include <cassert>

using namespace std;


void testConstructors()
{
	HashTable<Int> one(15);
	
	Int Intptr = 10;
	Int *Int1 = &Intptr;
	Int Intptr2 = 2;
	Int *Int2 = &Intptr2;
	Int Intptr3 = 7;
	Int *Int3 = &Intptr3;
	Int Intptr4 = 7;
	Int *Int4 = &Intptr4;
		
	assert(one.empty());
	one.insert(Int1);
	assert(!one.empty());
	
	assert(one.get(2)==NULL);
	
	one.insert(Int2);
	one.insert(Int3);
	one.insert(Int4);
	
	
	assert(*(one.get(2))==2);
	assert(*(one.get(10))==10);
	assert(*(one.get(7))==7);
	assert(one.get(12)==NULL);
	
	HashTable<Int> two(one);
	
	assert(*(two.get(2))==*(one.get(2)));
	assert(two.get(2)==&Intptr2);
	assert(*(two.get(7))==*(one.get(7)));
	assert(*(two.get(10))==*(one.get(10)));

	HashTable<Int> three = two;
	
	for (int i=0; i<15; i++)
	{
		assert(one.toString(i) == two.toString(i));
		assert(one.toString(i) == three.toString(i));
	}
	
	cout << "====================Constructors & Insert Work====================" << endl<<endl;
}

void testRemove()
{
	cout <<"test0"<<endl;
	HashTable<Int> one(15);
	Int Intptr4 = 8;
	Int *Int4 = &Intptr4;
	Int Intptr5 = 1;
	Int *Int5 = &Intptr5;
	Int Intptr6 = -5;
	Int *Int6 = &Intptr6;
	
	Int Intptr7 = 9;
	Int *Int7 = &Intptr7;
	Int Intptr8 = 23;
	Int *Int8 = &Intptr8;
	Int Intptr9 = 4;
	Int *Int9 = &Intptr9;
		
	cout <<"test1"<<endl;
	
	one.insert(Int4);
	one.insert(Int5);
	one.insert(Int6);
	one.insert(Int7);
	one.insert(Int8);
	one.insert(Int9);
	

	cout <<"test1"<<endl;
	assert(*(one.get(9))==9);
	one.remove(9);
	cout <<"test2"<<endl;
	assert(one.get(9)==NULL);
	cout <<"test3"<<endl;
	one.remove(23);
	one.remove(-5);
	one.remove(1);
	one.remove(4);
	one.remove(8);
	cout <<"test4"<<endl;
	assert(one.empty());
	
	one.insert(Int7);
	assert(!one.empty());	
	cout <<"test5"<<endl;
		
	cout << "====================Remove Works====================" << endl<<endl;


}



int main()
{
	testConstructors();
	testRemove();
	
	return 0;
}


