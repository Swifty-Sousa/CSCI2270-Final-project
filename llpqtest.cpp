//Author: Christian F. Sousa
// CSCI 2270 Data Structures
#include<iostream>
#include<fstream>
#include<sstream>
#include"LLPQ.hpp"
#include"pat.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        cout<< "Program requires a filename"<< endl;
    }
    llpq test;
    cout<<"1"<< endl;
    test.build(argv[1]);
    cout<< "2"<< endl;
    test.printLLPQ();
    //cout<< "3"<< endl;
    return 0;
}