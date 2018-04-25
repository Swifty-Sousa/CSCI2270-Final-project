//Author: Christian F. Sosua
// CSCI 2270 data structures section 104;
#include<iostream>
#include<sstream>
#include<fstream>
#include"HPQ.hpp"
#include"LLPQ.hpp"
using namespace std;

int main(void)
{
    string infile;
    string outfile;
    string holder;
    int lines;
    cout<< "enter the file you would like to make a test case from"<< endl;
    getline(cin, infile);
    cout<< "enter the destination file name (if this files does not exist in the directory a new one will be made)"<< endl;
    getline(cin, outfile);
    cout<< "enter how many lines you would like to be copied to the new file"<< endl;
    cout<< "Please note if you are borrowing this, the first line in any file read in will be ignored"<< endl;
    getline(cin, holder);
    lines=stoi(holder);
    ifstream indata;
    string data[lines];
    indata.open(infile);
    if(indata.fail())
    {
        cout<< "File: "<< infile<< " unable to be located."<< endl;
        return 0;
    }
    getline(indata, holder);
    int readcounter=1;
    while(getline(indata, holder))
    {
        cout<<"reading line "<< readcounter<< " of "<< lines<< endl;
        data[readcounter]=holder;
        if(readcounter+1==lines)
        {
        cout<<"reading line "<< readcounter+1<< " of "<< lines<< endl;
            break;
        }
        readcounter++;
    }
    indata.close();
    cout<< "####################################"<< endl;
    cout<< " Reading complete"<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< "Wrting to file "<< outfile<< endl;
    ofstream out;
    out.open(outfile);
    out<<"Name,Priotiry,Treatment"<< endl;
    for(int i=0; i<lines;i++)
    {
       cout<< "writing line "<< i+1<< " of "<< lines<< endl;
       out<<data[i]<< endl;
    }
    cout<< "Process completed"<< endl;
    return 0;
}
