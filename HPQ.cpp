// Author: Christian F. Sousa
// CSCI 2270 Data structures
#include<iostream>
#include"pat.hpp"
#include"HPQ.hpp"
#include<sstream>
#include<fstream>

hpq::hpq(int num)
{
    datasize=num;
}
hpq::~hpq(){}

void hpq::build(string filename)
{
    string holder;
    ifstream datafile;
    string nam;
    int pri;
    int treat;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File: "<< filename<< " does not exisit in current directory"<< endl;
    }
    getline(datafile, holder, '\r');
    string segment;
    while(getline(datafile,holder, '\r'))
    {
        stringstream ss(holder);
        getline(ss,segment, ',');
        nam=segment;
        getline(ss, segment, ',');
        pri= stoi(segment);
        getline(ss,segment, ',');
        treat= stoi(segment);
        pat *temp= new pat(nam, pri, treat);
        insert(temp);
    }
    datafile.close();
}
void hpq::printhpq()
{
    
}
void hpq::dequeue()
{

}
void hpq::dequeueall()
{
    for()
    {
        dequeue();
    }
}