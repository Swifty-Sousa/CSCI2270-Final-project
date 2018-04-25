#include<iostream>
#include"LLPQ.hpp"
#include<fstream>
#include<sstream>
#include"pat.hpp"

llpq::llpq(){
    head=NULL;
    tail=NULL;
} //default constutor

llqp::~llpq(){} // defualt destructor
 
void llpq::insert(pat temp)
{

}
void llpq::build(string filename)
{
    string holder;
    ofstream datafile;
    string nam;
    int pri;
    int treat;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File: "<< filename<< " does not exisit in current directory"<< endl;
    }
    getline(datafile, holder);
    string segment;
    while(getline,holder)
    {
    stringstream ss(holder);
    getline(ss,segment, ',');
    nam=segment;
    getline(ss, segment, ',');
    pri= stoi(segment);
    getline(ss,segment, ',');
    treat= stoi(segment);
    pat temp(nam, pri, treat);
    insert(a);
    }

}
void llqp::dequeue()
{

}