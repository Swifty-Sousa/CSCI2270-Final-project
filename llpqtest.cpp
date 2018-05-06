//Author: Christian F. Sousa
// CSCI 2270 Data Structures
#include<iostream>
#include<fstream>
#include<sstream>
#include"LLPQ.hpp"
#include"pat.hpp"
#include<time.h>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        cout<< "Program requires a filename"<< endl;
    }
    clock_t  t1, t2;
    float holder[500];
    for(int i=0; i<500; i++)
    {
        t1=clock();
        llpq test;
        test.buildlimited(argv[1], 100);
        t2=clock();
        //cout<< "if you see this it is building"<< endl;
        //test.printLLPQ();
        holder[i]=((float)t2-(float)t1)/ CLOCKS_PER_SEC;
    }
    ofstream outfile;
    outfile.open("runtimetest.txt");
    for(int i=0; i<500; i++)
    {
        outfile<<holder[i]<<endl;
    }
    return 0;
}
