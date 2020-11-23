/*********************
Name: Allison Crenshaw
Coding 06
Purpose: Hashmap program using
 embedded linked list.
**********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASHTABLESIZE 15

#include "linkedlist.h"

#include <iostream>
using std::cout;
using std::endl;

class HashTable {

public:
    HashTable(); // constructor
    ~HashTable(); // destructor

    bool insertEntry(int, string);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    int hash(int);
    int count;
    Data *hashtable[HASHTABLESIZE];
};


#endif