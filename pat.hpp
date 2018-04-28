//Author: Christian F. Sousa
// CSCI 2270 data structures
// definition file for the patient struct;

struct pat
{
    string name;
    int priority;
    int treatment;
    // next and prev only for LL implementation;
    *pat next;
    *pat prev;
    pat(){}
    pat( string n, int p, in e)
    {
        name=n;
        priority=p;
        treatment=e;
    }
}