/*********************
Name: Allison Crenshaw
Coding 06
Purpose: Hashmap program using
 embedded linked list.
**********************/

#include "hashtable.h"

/*******************************
 * constructor and destructor
*******************************/
HashTable::HashTable() {
    count = 0;
    for (int i=0; i < HASHTABLESIZE; i++) {
        hashtable[i] = new LinkedList;
    }
}

HashTable::~HashTable() {
    for (int i=0; i < HASHTABLESIZE; i++) {
        hashtable[i]->clearList();
    }
}

/*******************************
 * insert, get, remove
*******************************/
bool HashTable::insertEntry(int id, string info) {
    bool ok = false;
    int hashNum = hash(id);
    ok = hashtable[hashNum]->addNode(id, info);
    if (ok) {count++;}
    return ok;
}

string HashTable::getData(int id) {
    string dataString = "";
    if (id > 0) {
        Data *newData = new Data;
        int hashNum = hash(id);
        hashtable[hashNum]->getNode(id, newData);
        dataString = newData->data;
    }
    return dataString;
}

bool HashTable::removeEntry(int id) {
    bool found = false;
    if (id>0) {
        int hashNum = hash(id);
        found = hashtable[hashNum]->deleteNode(id);
        if (found) {count--;}
    }
    return found;
}


/*******************************
 * getCount and printTable
*******************************/
int HashTable::getCount() {
    return count;
}

void HashTable::printTable() {
    string line = "******************************\n";
    cout << line << "Printing Hash Table: " << endl;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << i << ": ";
        hashtable[i]->printListAsLine();
    } // end for loop
    cout << "End of Hash Table." << endl << line;
}

/*******************************
 * private helper functions
*******************************/
// private helper method for hashing
int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
