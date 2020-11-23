/*********************
Name: Allison Crenshaw
Coding 05
Purpose: This program constructs a fully
 functional doubly linked list class.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"
#include <iostream>     /* cout, endl */

using std::cout;
using std::endl;


class LinkedList {

public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool=false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    // private vars or method prototypes go here
    Node *head;
    bool compareNodes(int, string);
    void addHeadNode(int, string);
    void addMiddleNode(int, string, Node*, Node*);
    void addTailNode(int, string, Node*);

}; // end class

#endif //LINKED_LIST_H