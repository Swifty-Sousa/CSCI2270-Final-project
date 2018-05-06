//Author: Christian F. Sousa
// CSCI 2270 Data structures
#ifndef hpq_h
#define hpq_h

#include<iostream>
#include"pat.hpp"

class hpq
{
public:
    int cap; // will be a max size for the testcases;
    int current; // current size of the array 
    pat * reg[881];//becasuse we are starting at 1;
    int left(int );
    int right(int);
    int parent(int);
    hpq(int);
    ~hpq();
    bool comparison(pat*,pat*);
    void heapify(int );
    void insert( pat*);
    void swap(pat *, pat *);
    void build(std::string);
    void printhpq();
    pat * dequeue();
    void dequeueall();
};
#endif