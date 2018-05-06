// Author: Christian F. Sousa
// CSCI 2270 Data structures
#include<iostream>
#include"pat.hpp"
#include"HPQ.hpp"
#include<sstream>
#include<fstream>
using namespace std;
int hpq::parent(int i)
{
     return((i-1)/2);
}
int hpq::left(int i)
{
    return(2*i+1);
}
int  hpq::right(int i)
{
    return(2*1+1);
}
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
    datasize=num;
}
hpq::~hpq(){}

void hpq::heapify(int i);
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<=current && reg[l]<reg[i] )
    {
        smallest=l;
    }
    if(r<current && reg[r]<reg[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(reg[i], reg[smallest]);
        heapify(smallest);
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
    while(i>1 && comparison(reg[i],reg[parent(i)]))
    {
        // the the parent is greater than the child
        swap(reg[i], reg[parent(i)]);
        i= reg[paretn(i)];
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
    cout<<"Rank" << '\t'<< "patient,  Priority,  Treatment"<< endl;
    pat * temp;
    while()
    {
       temp=dequeue()
       if(temp==NULL)
       {
           return;
       }
       cout<<i<<":"<< '\t'<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
    }
}
pat * hpq::dequeue()
{
    if(current==0)
    {
        cout<< "Empty"<< endl;
        reutn NULL;
    }
    else if(current==1)
    {
        current--;
        return reg[1]:
    }
    pat * poppat= reg[1];
    reg[1]=reg[current];
    current--;
    heapify(1);
    return poppat;
}
void hpq::dequeueall()
{
    while(current!=0)
    {
        dequeue();
    }
}