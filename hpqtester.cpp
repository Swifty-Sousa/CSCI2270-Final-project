//Author: Christain F. Sousa
// CSCI 2270
#include<iostream>
#include<string>
#include"HPQ.hpp"
using namespace std;

int main(int argc, char * argv[])
{
    if(argc!=2)
    {
        cout<< "filename please"<< endl;
    }
    string filename=argv[1];
    hpq kmp(881);
    kmp.build(filename);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "build completed"<< endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    kmp.printhpq();
    return 0;
}