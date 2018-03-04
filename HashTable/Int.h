// Brett Weicht and Ryan Anderson
//Int.h

#ifndef INT_H
#define INT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Int
{
public:
	Int(int i): x(i) { }
	
	int x;
	int hash(int m) const {return abs(x) % m;}	// simple hash function for testing
	bool operator==(Int i);
	string toString() const;	
};

ostream&  operator<<(ostream& stream, const Int& i);

bool Int::operator==(Int i)
{
	return x == i.x;	
}

string Int::toString() const
{
	stringstream s;
	s << x;
	return s.str();
}

ostream&  operator<<(ostream& stream, const Int& i) 
{
	return stream << i.toString();
}

#endif
