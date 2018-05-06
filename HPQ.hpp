//Author: Christian F. Sousa
// CSCI 2270 Data structures
#ifndef hpq_h
#define hpq_h

#include<iostream>
#include"pat.hpp"

class hpq
{
    int datasize; // will be a max size for the testcases;
    pat * reg[881];//becasuse we are starting at 1;
    // next three fuctions to make my life easy
    // will return the idex of the parent or child based
    // on what is input
    // credit to Geeks for Geeks for this idea
    int parent(int);
    int right(int);
    int left(int);
    hpq(int);
    ~hpq();
    void insert(int, pat*);
    void swap(pat *, pat *);
    void build(std::string);
    void printhpq();
    void dequeue();
    void dequeueall();
};
#endif