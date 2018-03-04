

//======================================
//Ryan Anderson& Brett Weicht
//Movies.cpp
//======================================

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include "Movie.h"
#include "dict.h"

using namespace std;

int main()
{
	ifstream titles("movies_mpaa.txt");
	string l;
	Movie* m;
	Dict<Movie> dict;
	
	timeval timeBefore, timeAfter;
	long diffSeconds, diffUSeconds;
	
	gettimeofday(&timeBefore, NULL);
	
	while(getline(titles, l))
	{
		m = new Movie;
		
		char c;
		int x = l.find('\t');
		
		m->title=l.substr(0, x);
		m->cast = l.substr(x+1);
		dict.insert(m);
	}
	
	gettimeofday(&timeAfter, NULL);
	
	diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
	diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
	cout << diffSeconds + diffUSeconds/1000000.0 << " seconds" << endl;
	
	cout<< "input title: ";
	while(getline(cin, l) && l!="exit")
	{
		Movie m;
		m.title = l;
		if(l.length()<3){
			m.title="empty";
		}
		Movie* mov = dict.get(m);
		if(mov == NULL)
			cout<<"Movie not found, Please try again(or exit to quit): ";
		else{
		cout<< *(mov)<<endl;
		cout << "Please input another title (or exit to quit): ";
		}
	}	
	
	return 0;
} 
