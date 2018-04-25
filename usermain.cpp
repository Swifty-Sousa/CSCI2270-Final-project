//Author Christian F. Sousa
// CSCI 2270 section 104
#include<iostream>
#include<time.h>
using namespace std;

int mainmen()
{
    int x;
    string l;
    cout<< "1. Build LL priority queue."<< endl;
    cout<< "2. Build Heap Priority Queue."<< endl;
    cout<< "3. Deque LL"<< endl;
    cout<< "4. Deque HPQ"<< endl;
    cout<< "5. Deque all LL"<< endl;
    cout<< "6. Deque all HPQ"<< endl;
    getline(cin,l);
    try
    {
        x=stoi(l);
    }
    catch(int n)
    {
        cout<< "please only enter a number 1-6";
        return 0;
    }
    return x;
}
int main(int argc, char * argv[])
{
    // handle all the file reading and the such 
    int command= mainmen();
    if(command==1)
    {

    }
    if(command==2)
    {

    }
    if(command==3)
    {

    }
    if(command==4)
    {

    }
    if(command==5)
    {

    }
    if(command==6)
    {

    }
    return 0;
} 