//Author: Christain F. Sousa
// CSCI 2270
#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include"HPQ.hpp"
using namespace std;

int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        cout<< "filename please"<< endl;
    }
    string filename=argv[1];
    float holder [500];
    clock_t t1, t2;
    for(int i=0; i<500; i++)
    {
        hpq kmp(800);
        t1=clock();
        kmp.build(filename);
        kmp.dequeueall();
        t2=clock();
        holder[i]=((float)t2-(float)t1)/ CLOCKS_PER_SEC;
    }
    ofstream outfile;
    outfile.open("hpqT800.txt");
    for(int i=0; i<500; i++)
    {
        outfile<<holder[i]<<endl;
    }
    return 0;
}