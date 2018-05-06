// Author: Christian F. Sousa
// CSCI 2270 Data structures
#include<iostream>
#include"pat.hpp"
#include"HPQ.hpp"
#include<sstream>
#include<fstream>

bool hpq::comparison(pat *a, pat *b)
{
    if(a->priority<b->priority)
    {
        return true;
    }
    else if(a->priority>b->priority)
    {
        return false;
    }
    else
    {
        // case where the priorities are the same
        if(a->treatment<b->treatment)
        {
            return true;
        }
        else if(a->treatment>b->treatment)
        {
            return false;
        }
        else
        {
            //case where both mesures are the same
            return false;
        }
    }
}
hpq::hpq(int num)
{
    datasize=0;
}
hpq::~hpq(){}

void hpq::heapify(int i);
{
    pat *l=reg[left(i)];
    pat *r=reg[right(i)];
    pat *parent= reg[i];
    if(l<datasize && reg[l]<reg[i])
    {
        smallest=i;
    }
    if(r<datasize && reg[r]<reg[smallest] )
    {
        smallest=r;
    }
    
}
void hpq::swap(pat * x, pat *y)
{
    pat *temp=x;
    x=y;
    y=temp;
}
void hpq::insert(pat *temp)
{
    if(current=cap)
    {
        cout<< "array is full"<< endl;
        return;
    }
    datasize++;
    int i =datasize; 
    reg[i]=temp;// insert at the end
    while(i>1 && comparison(reg[i],reg[i/2]))
    {
        // the the parent is greater than the child
        swap(reg[i], reg[i/2]);
        i= i/2;
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
    datasize=1;// becasue of the convetion to start binary minheaps at 1
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
pat * hpq::dequeue(int i)
{
    if(current==0)
    {
        cout<< "Empty"<< endl;
        reutn NULL;
    }
    else if(current==1)
    {
        return reg[1]:
    }
    
}
void hpq::dequeueall()
{
    for(in i=0; i<datasize; i++)
    {
        dequeue();
    }
}