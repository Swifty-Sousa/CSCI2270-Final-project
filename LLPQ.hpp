// Author: Christian F. Sousa
// CSCI 2270 Data structures
#include "pat.hpp"
#ifndef LLPQ_H
#define LLPQ_H

class llpq 
{
    public:
        llpq(){}
        void insert(pat);// takes in patient struct
        void build(string); // filename
        void dequeue(); // removes from head;
        *pat head;
        *pat tail; 
};
#endif;