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
    llpq test;
    test.build(argv[1]);
    //cout<< "if you see this it is building"<< endl;
    test.printLLPQ();
    cout<< "testcase complete"<< endl;
    return 0;
}
