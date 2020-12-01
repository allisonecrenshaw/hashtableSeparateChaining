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
    int i = 0;

    while (!found && i < HASHTABLESIZE) {
        found = hashtable[i]->deleteNode(id);
        if (found) {count--;}
        i++;
    } // end while
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
        if (hashtable[i]->getCount() == 0) {
            cout << "Empty" << endl;
        } else
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
