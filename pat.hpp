//Author: Christian F. Sousa
// CSCI 2270 data structures
// definition file for the patient struct;
#ifndef pat_h
#define pat_h

#include<string>
struct pat
{
    std::string name;
    int priority;
    int treatment;
    // next and prev only for LL implementation;
    pat * next=NULL;
    pat * prev=NULL;
    pat(){}
    pat(std::string n, int p, int e)
    {
        name=n;
        priority=p;
        treatment=e;
    }
};
#endif