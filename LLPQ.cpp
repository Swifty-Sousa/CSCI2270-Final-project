#include"LLPQ.hpp"
#include<fstream>
#include<sstream>
#include"pat.hpp"

llpq::llpq(){
    head=NULL;
    tail=NULL;
} //default constutor

llqp::~llpq(){} // defualt destructor
 
void llpq::insert(pat in)
{
    if(head ==NULL)
    {
        // tail will also be NULL therefore the queue is empty
    }
    * pat temp=head;
    if(head==tail)
    {
        if(in->priority>temp->priority)
        {
            // insert after head
        }
        else if(in->priority<temp->priority)
        {
            // insert before
        }
        else if(in->priority==temp->priority)
        {
            // then check for seondary priority
            if(in->treatment>temp->treatment)            
            {
                // insert infront of temp
            }
            else if(in->treatment<temp->treatment)
            {
                //insert after temp
            }
            // case where secondary checks are the same.
        }
    }
    while(in->next!=NULL)
    {
        if(in->priority>temp->priority)
        {
            temp=temp->next;
        }
        else if(in->priority<temp->priority)
        {

        }
        else
        {
            // priorities are the same, 
            // move to seconday checks
        }
    }
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
    * pat temp=head;
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