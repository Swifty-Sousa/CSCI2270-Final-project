// Author: Christian F. Sousa
// CSCI 2270 Data structures
#include<iostream>
#include"pat.hpp"
#include"HPQ.hpp"
#include<sstream>
#include<fstream>
int hpq::parent(int i)
{
    return((i-1)/2);
}
int hpq::right(int i)
{
    return(2*i+2);
}
int hpq::left(int i)
{
    return(2*i+1);
}
hpq::hpq(int num)
{
    datasize=num;
}
hpq::~hpq(){}
void hpq::heapify()
{

}
void hpq::swap(pat * x, pat *y)
{
    pat *temp=x;
    x=y;
    y=temp;
}
void hpq::insert(int i, pat *temp)
{
    reg[i]=temp;// insert at the end
    while(i!=0 && reg[parent(i)>reg[i])
    {
        swap(reg[i], reg[parent(i)]);
        i=parent(i);
    }
}
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
    int i=1;// becasue of the convetion to start binary minheaps at 1
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
        reg[i]=temp;
        int k=datasize-1;
        while(i!=0 && reg[(k-1)/2]>reg[k])
        {
            swap(reg[k], reg[(k-1)/2]);
            k=(k-1)/2 
        }
        i++;
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
    for(in i=0; i<datasize; i++)
    {
        dequeue();
    }
}