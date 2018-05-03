//Author: Christian F. Sousa
// CSCI 2270 Data Structures
#include<iostream>
#include<fstream>
#include<sstream>
#include"pat.hpp"
#include<queue>
#include<string>
#include<vector>
using namespace std;
struct compare
{
bool operator()(const pat *a, const pat* b)
	{
		if(a->priority< b->priority)
		{
			return false;
		}
		else if(a->priority> b->priority)
		{
			return true;
		}
		else
		{
			//for the priority equal;
			if(a->treatment< b->treatment)
			{
				return false;
			}
			else if(a->treatment>b->treatment)
			{
				return true;
			}
			else
			{
				// for when both are equal
				return true;
			}
		}
	}
};
/*
void printstl(priority_queue<vector<pat>,compare> & minstl)
{
	pat *temp;
    cout<<"Rank" << '\t'<< "patient,  Priority,  Treatment"<< endl;
	int i=0;
	while(!minstl.empty())
	{
		temp=minstl.top();
		minstl.pop();
        cout<<i<<":"<< '\t'<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
 	    i++;
	}
	
}
*/
void build(string filename)
{
	priority_queue <pat*, vector<pat*>, compare> minstl;	
	ifstream datafile;
	datafile.open(filename);	
	if(datafile.fail())
	{
		cout<< "File "<< filename << " not found in current derectory"<< endl;
	}
	string line;
	string holder;
	string holder2;
	string holder3;
	getline(datafile, line, '\r');
	while(getline(datafile, line, '\r'))
	{
		stringstream ss(line);
		getline(ss, holder, ',');
		getline(ss, holder2, ',');
		getline(ss, holder3, ',');
		pat * temp= new pat(holder, stoi(holder2), stoi(holder3));
		minstl.push(temp);
	}
	pat *temp;
    cout<<"Rank" << '\t'<< "patient,  Priority,  Treatment"<< endl;
	int i=1;
	while(!minstl.empty())
	{
		temp=minstl.top();
		minstl.pop();
        cout<<i<<":"<< '\t'<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
 	    i++;
	}
	
	//printstl(minstl);
}
int main(int argc, char * argv[])
{
	if( argc!= 2)
	{
		cout<< "program requres filename as command line argument"<< endl;
	}
	string filename=argv[1];
	build(filename);
}

