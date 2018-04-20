#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
    string infile;
    stirng outfile;
    string holder;
    int lines;
    cout<< "enter the file you would like to make a test case from"<< endl;
    getline(cin, infile);
    cout<< "enter the destination file name (if this files does not exist in the directory a new one will be made)"<< endl;
    getline(cin, outfile);
    cout<< "enter how many lines you would like to be copied to the new file"<< end;
    getline(cin, holder);
    lines=stoi(holder);

}