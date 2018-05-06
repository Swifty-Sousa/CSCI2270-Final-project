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
        return 0;
    }
    clock_t  t1, t2;
    float holder[500];
    for(int i=0; i<500; i++)
    {
        t1=clock();
        llpq test;
        test.buildlimited(argv[1], 700);
        test.remove();
        t2=clock();
        //cout<< "if you see this it is building"<< endl;
        //test.printLLPQ();
        holder[i]=((float)t2-(float)t1)/ CLOCKS_PER_SEC;
        t1=0;
        t2=0;
    }
    ofstream outfile;
    outfile.open("llpqT700.txt");
    for(int i=0; i<500; i++)
    {
        outfile<<holder[i]<<endl;
    }
    return 0;
}
