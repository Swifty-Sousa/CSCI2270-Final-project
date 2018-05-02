//Author: Christian F. Sousa
// CSCI 2270 Data Structures
#include<iostream>
#include<fstream>
#include<sstream>
#include"pat.hpp"
#include<queue>
#include<vector>
struct compare
{
	bool operator () (const pat &a, const pat &b)
	{
		if(a->priority > b->priority)
		{
			return false;
		}
	}
};
void hpqbuild(string filename);
{
	priority_queue <type, vector<pat>, compare> minheap;	
	ofstream datafile;
	datafile.open(filename);	
	if(datafile.fail())
	{
		cout<< "File "<< filename << " not found in current derectory"<< endl;
	}
	string line;
	sirng holder;
	string holder2;
	string holder3;
	getline(datafile, line);
	while(getline(datafile, line))
	{
		stirngstream ss(line);
		getline(ss, holder, '\r');
		getline(ss, holder2, '\r');
		getline(ss, holder3, '\r');
		pat * temp= new pat(holder, stoi(holder2), stoi(holder3));
		minheap.push(temp);
	}
}
int main(int argc, char * argv[])
{
	if( argc!= 2)
	{
		cout<< "program requres filename as command line argument"<< endl;
	}
	filename=argv[1];
	hpqbuild(filename);
}

