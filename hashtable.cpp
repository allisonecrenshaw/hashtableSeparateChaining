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
    bool dupe = false;
    bool positive = false;
    int loop = 0;

    // check for positive and non-duplicate ids
    cout << "Starting insert entry." << endl;
    if (id > 0)
        positive = true;
    while (dupe == false && loop < HASHTABLESIZE) {
        dupe = hashtable[loop]->exists(id);
        loop++;
    }
    if (positive == true && dupe == false) {
        ok = true;
        cout << "Inserting data..." << endl;
        hashtable[hash(id)]->addNode(id, info);
    } else {
        cout << "ID " << id << " invalid." << endl;
    }
    return ok;
}

string HashTable::getData(int id) {
    Data *newData;
    bool found = false;
    int i = 0;
    string data;

    // utilize getNode to find data
    while (found == false && i < HASHTABLESIZE) {
        found = hashtable[i]->getNode(id, newData);
        i++;
    }
    data = newData->data;
    return data;
}

bool HashTable::removeEntry(int) {
    bool ok = false;
    return ok;
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
        }
        else {
            hashtable[i]->printListAsLine();
        }
    }
    cout << "End of Hash Table." << endl << line;
}


/*******************************
 * private helper functions
*******************************/
// private helper method for hashing
int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
