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
    return(2*1+2);
}
bool hpq::comparison(pat *a, pat *b)
{/*
    cout<< "in compare"<< endl;;
    for(int i=0; i<cap; i++)
    {
        if(reg[i]==NULL)
        {
            cout<<" reg[] at "<< i<< " is NULL"<< endl;
        }
    }
    cout<< "a"<< endl;
    if(a==NULL)
    {
        cout<< "a is NULL";
    }
    cout<< a->name<<  " "<< a->priority<< " "<<a->treatment<< endl;
    cout<< "b"<< endl;
    if(b!=NULL)
    {
    cout<< b->name<<  " "<< b->priority<< " " <<b->treatment<< endl;
    }
    if(reg[0]!=NULL)
    {
        cout<< " 0 is not NUll and I wanna cry"<< endl;
    }
    cout<< b->name<<  " "<< b->priority<< " " <<b->treatment<< endl;
    */
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
            return true;
        }
    }
}
hpq::hpq(int num)
{
    current=0;
    cap=num;
    for(int i=0; i<cap; i++)
    {
        reg[i]=NULL;
    }
}
hpq::~hpq(){}


void hpq::swap(int child, int parent)
{
    pat *temp;
    temp=reg[child];
    reg[child]= reg[parent];
    reg[parent]=temp;
}
void hpq::insert(pat *temp)
{
    if(current==cap)
    {
        cout<< "array is full"<< endl;
        return;
    }
    current++;
    int i = current-1; 
    reg[i]=temp;// insert at the end
    while(i>0 && comparison(reg[i],reg[parent(i)]))
    {
        //cout<< "this comparison is actually happening at some point"<< endl;
        // the the parent is greater than the child
        swap(i, parent(i));
        i= parent(i);
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
    //int k=1;
    while(getline(datafile,holder, '\r'))
    {
        //cout<<k<< ": "<< holder<< endl;
        //k++;
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
    if(reg[1]==NULL)
    {
        cout<< "problem is here"<< endl;
    }
    /*
    for(int i=0; i<cap;i++)
    {
        cout<<"Rank: "<<i<< " "<< reg[i]->name<< " " << reg[i]->priority<<endl;
    }
    */
    datafile.close();
}
void hpq::printhpq()
{
    cout<<"Rank" << '\t'<< "patient,  Priority,  Treatment"<< endl;
    pat * temp;
    int i=1;
    while(true)
    {
       temp=dequeue();
       if(temp==NULL)
       {
           return;
       }
       cout<<i<<":"<< '\t'<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
       i++;
    }
}
void hpq::heapify(int i)
{

    //cout<< "reached heapify"<< endl;
    int l=left(i);
    int r=right(i);
    int smallest=i;
    cout<< "got numbers"<< endl;
    cout<<"left: "<< l<<endl;
    cout<<"right: "<<r<<endl;
    cout<< "smallest: "<< smallest<< endl;
    cout<< "attempting comparision of l and smallest"<< endl;
    for(int i=0; i<current; i++)
    {
        if(reg[i]==NULL)
        {
            cout<<"NULL at "<< i<< endl;
        }
    }
    //cout<< "printing true"<< true<< endl;
    //cout<< comparison(reg[l],reg[i]);
    //cout<< "completed"<< endl;
    if(l<current && comparison(reg[l],reg[i]))
    {
        //cout<< "one"<< endl;
        smallest=l;
    }
    if(r<current && comparison(reg[r],reg[smallest]))
    {
        //cout<<"two"<< endl;
        smallest=r;
    }
    if(smallest!=i)
    {
        cout<<"three"<< endl;
        swap(i, smallest);
        heapify(smallest);
    }
}
pat * hpq::dequeue()
{
    cout<< "reached dequeue"<< endl;
    if(current==0)
    {
        cout<< "Empty"<< endl;
        return NULL;
    }
    else if(current==1)
    {
        current--;
        return reg[0];
    }
    pat * poppat= reg[0];
    reg[0]=reg[current-1];
    current--;
    cout<<"attempting heapify"<< endl;
    heapify(0);
    cout<<endl;
    cout<<"completed"<<endl;
    return poppat;
}
void hpq::dequeueall()
{
    int i=1;
    while(current!=0)
    {
        cout<< "trying "<< i<< endl;
        dequeue();
    }
}