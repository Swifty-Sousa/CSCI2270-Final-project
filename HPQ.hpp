//Author: Christian F. Sousa
// CSCI 2270 Data structures
#ifndef hpq_h
#define hpq_h

#include<iostream>
#include"pat.hpp"

class hpq
{
    int datasize;
    pat * reg[880];
    // pointer to the highest priority;
    hpq(int);
    ~hpq();
    void swap(pat *, pat *);
    void build(std::string);
    void printhpq();
    void dequeue();
    void dequeueall();
};
#endif