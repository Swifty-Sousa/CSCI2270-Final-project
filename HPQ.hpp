//Author: Christian F. Sousa
// CSCI 2270 Data structures
#ifndef hpq_h
#define hpq_h

#include<vector>
#include<iostream>
#include"pat.hpp"

class hpq
{
    //remmber to put in holder vector here
    std::vector<pat*> minheap;
    hpq();
    ~hpq();
    void heapify();
    void build(std::string);
    void print();
    void dequeue();
    void dequeueall();
};
#endif