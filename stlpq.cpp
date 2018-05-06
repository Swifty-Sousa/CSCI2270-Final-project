//Author: Christian F. Sousa
// CSCI 2270 Data Structures
#include<iostream>
#include<fstream>
#include<sstream>
#include<time.h>
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
void printstl(priority_queue <pat*, vector<pat*>,compare> &minstl)
{
	if(minstl.empty())
	{
		cout<< "Vector is empty"<< endl;
		return;
	}
	pat *temp;
    cout<<"Rank" << "      "<< "patient,  Priority,  Treatment"<< endl;
	int i=1;
	while(!minstl.empty())
	{
		temp=minstl.top();
		minstl.pop();
        cout<<i<<":"<< "      "<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
 	    i++;
	}
	
}
void buildlimited(string filename, priority_queue< pat*, vector<pat*>,compare> &minstl, int n)
{
	ifstream datafile;
	int i=0;
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
		if(i==n)
		{
			break;
		}
		stringstream ss(line);
		getline(ss, holder, ',');
		getline(ss, holder2, ',');
		getline(ss, holder3, ',');
		pat * temp= new pat(holder, stoi(holder2), stoi(holder3));
		minstl.push(temp);
		i++;
	}
}
void build(string filename, priority_queue< pat*, vector<pat*>,compare> &minstl)
{
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
}
void removeall(priority_queue <pat*, vector<pat*>, compare> &minstl)
{
	while(!minstl.empty())	
	{
		minstl.pop();
	}
}
int main(int argc, char * argv[])
{
	if( argc!= 2)
	{
		cout<< "program requres filename as command line argument"<< endl;
	}
	priority_queue <pat*, vector<pat*>, compare> minstl;	
	string filename=argv[1];
	float holder[500];
	clock_t t1,t2;
	for(int i=0; i<500; i++)
	{
		t1=clock();
		buildlimited(filename, minstl, 800);
		removeall(minstl);
		t2=clock();
        holder[i]=((float)t2-(float)t1)/ CLOCKS_PER_SEC;
		t1=0;
		t2=0;
	}
    ofstream outfile;
    outfile.open("stlT800.txt");
    for(int i=0; i<500; i++)
    {
        outfile<<holder[i]<<endl;
    }
    return 0;

}

