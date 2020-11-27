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
    LinkedList hashtable[HASHTABLESIZE];
}

HashTable::~HashTable() {

}

/*******************************
 * insert, get, remove
*******************************/
bool HashTable::insertEntry(int, string) {
    bool ok = false;
    return ok;
}

string HashTable::getData(int) {
    string data = "";
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
    cout << "End of Hash Table." << endl << line;
}


/*******************************
 * private helper functions
*******************************/
// private helper method for hashing
int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
