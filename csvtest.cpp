#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
// was having issues handling the csv files so I made this 
// to figure it out
struct pat
{
    string name;
    int pri;
    int treat;
    pat(){}
    pat( string some, int one, int two)
    {
        name=some;
        pri=one;
        treat=two;
    }
};
void doit(string filename)
{
    ifstream datafile;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "file failed to open"<< endl;
    }
    string line;
    string holder;
    string holder2;
    string holder3;
    int one;
    int two;
    getline(datafile,line,'\r');
    getline(datafile,line,'\r');
        stringstream ss(line);
        getline(ss,holder, ',');
        getline(ss,holder2, ',');
        one=stoi(holder2);
        getline(ss,holder3, ',');
        two=stoi(holder3);
        pat  *hello= new pat(holder,one,two);
    cout<<hello->name<< endl;
}
int main(int argc, char * argv[])
{
    doit(argv[1]);
}