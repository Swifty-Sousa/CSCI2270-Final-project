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
        head=in;
        tail=in;
        return;
    }
    * pat temp=head;
    * while(temp->next!=NULL)
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
            temp->pre->next=in;
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
                temp->pre->next=in;
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
void llpq::printLLPQ()
{
    *pat=head;
    cout<<"Rank     patient, Priotity, Treatment"<< endl;
    int i=1;
    while(temp->next!=NULL)
    {
       cout<<i<<":"<< "      "<<pat->name<< ", "<<pat->priority<< ", "<< pat->treatment<< endl;
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
