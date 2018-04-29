#include"LLPQ.hpp"
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include"pat.hpp"
using namespace std;
llpq::llpq(){
    head=NULL;
    tail=NULL;
} //default constutor

llpq::~llpq(){} // defualt destructor
 
void llpq::insert(pat *in)
{
    if(head==NULL)
    {
        // tail will also be NULL therefore the queue is empty
        head=in;
        tail=in;
        return;
    }
    pat* temp=head;
    while(temp->next!=NULL)
    {
        if(in->priority>temp->priority)
        {
            //test if at tail, insert
            //else, next
            if(temp==tail)
            {
                temp->next=in;
                in->prev=temp;
                tail=in;
                return;
            }
            // next
            temp=temp->next;
            continue;
        }
        else if(in->priority<temp->priority)
        {
            if(temp==head)
            {
                in->next=temp;
                temp->prev=in;
                head=in;
                return;
            }
            // insert before
            in->prev=temp->prev;
            temp->prev->next=in;
            in->next=temp;
            temp->prev=in;
            return;
        }
        else if(in->priority==temp->priority)
        {
            // then check for seondary priority
            if(in->treatment<temp->treatment)            
            {
                if(temp==head)
                {
                    in->next=temp;
                    temp->prev=in;
                    head=in;
                    return;
                }
                // insert before
                in->prev=temp->prev;
                temp->prev->next=in;
                in->next=temp;
                temp->prev=in;
                return;
            }
            else if(in->treatment>temp->treatment)
            {
                if(temp==tail)
                {
                    temp->next=in;
                    in->prev=temp;
                    tail=in;
                    return;
                }
                // next
                temp=temp->next;
                continue;
            }
            else
            {
                if(temp==tail)
                {
                    temp->next=in;
                    in->prev=temp;
                    tail=in;
                    return;
                }
                else
                temp->next->prev=in;
                in->next=temp->next;
                temp->next=in;
                in->prev=temp;
            }
            
        }
    }
}

void llpq::build(string filename)
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
        cout<< segment<< endl;
        nam=segment;
        getline(ss, segment, ',');
        cout<< segment<< endl;
        pri= stoi(segment);
        getline(ss,segment, ',');
        cout<< segment<< endl;
        treat= stoi(segment);
        pat temp(nam, pri, treat);
        insert(&temp);
    }
    datafile.close();
}
void llpq::printLLPQ()
{
    pat * temp=head;
    cout<<"Rank     patient, Priotity, Treatment"<< endl;
    int i=1;
    if(head!=NULL)
    {
        cout<< "head is not NULL"<< endl;
    }
    if(tail!=NULL)
    {
        cout<< "tail is not NULL"<< endl;
    }
    if(temp!=NULL)
    {
        cout<< "temp is not NULL"<< endl;
    }
    cout<<temp->name<<endl;
    return;
    //cout<< temp->priority<< endl;
    //cout<< temp->treatment<< endl;
    while(temp->next!=NULL)
    {
       cout<<i<<":"<< "      "<<temp->name<< ", "<<temp->priority<< ", "<< temp->treatment<< endl;
    }
}
void llpq::dequeue()
{
    pat* temp=head;
    if(temp->next==NULL)
    {
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    temp=temp->next;
    delete temp->prev;
    temp->prev=NULL;
    head=temp;
}
void llpq::remove()
{
    while(head!=NULL && tail!=NULL)
    {
        dequeue();
    }
}
