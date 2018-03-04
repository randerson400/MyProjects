//Movie.h




#ifndef Movie_H
#define Movie_H

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;


class Movie
{
  public:   
  	  Movie();
  	  Movie(const Movie &m);  
  	  Movie(string title, string cast);	          
  	  
  	  
  	  bool operator<(Movie m);
  	  bool operator<=(Movie m);
  	  bool operator==(Movie m);
  	  int hash(int Slots) const;
  	  
  	  string toString() const;  
  	  
  	  string title; 
  	  string cast;
};

template <class KeyType>
ostream&  operator<<(ostream& stream, const Movie& m);

Movie::Movie()
{
	title = "";
	cast = "";
}

Movie::Movie(const Movie &m)
{
	title = m.title;
	cast=m.cast;	
}
Movie::Movie(string s1, string s2)        
{
 	 title = s1;
 	 cast = s2;
}
bool Movie::operator<(Movie m)
{
	return (title.substr(2)<m.title.substr(2));
}	  

bool Movie::operator<=(Movie m)
{
	return (title.substr(2)<=m.title.substr(2));
}

bool Movie::operator==(Movie m)
{
	return (title.substr(2)==m.title.substr(2));
}

string Movie::toString() const
{
	return cast;
}

ostream&  operator<<(ostream& stream, const Movie& m)
{
	return stream << m.toString();
}

int Movie::hash(int Slots) const
{
	int i=0, sum=0, prevsum=0;
	bool overflow = false;
	int size = title.size();
	while((i<size) && !overflow)
	{
		sum += title[i]*pow(3,i);
		if(prevsum>sum)
			overflow= true;
		else
		{
			prevsum = sum;
			i++;
		}
	}
	
	if(overflow)
		sum = prevsum;
	return sum%Slots;
	//return 1;
}

#endif

