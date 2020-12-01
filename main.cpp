/*********************
Name: Allison Crenshaw
Coding 06
Purpose: Hashmap program using
 embedded linked list.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int *ids = new int[testdatasize];
    string *strs = new string[testdatasize];

    char *buffer = new char[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << endl;
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    cout << endl;
    cout << "Creating new table." << endl;
    HashTable table;
    
    // show it is empty by calling getCount and printTable
    cout << "Current count: " << table.getCount() << endl;
    cout << "Calling print table..." << endl;
    table.printTable();

    // try and put ALL the data into the table and show what happens
    for (int i = 0; i < testdatasize; i++) {
        table.insertEntry(ids[i], strs[i]);
    }
    table.printTable();
    cout << "Current count: " << table.getCount() << endl;

    // continue using and testing your table, add and remove data,
    // make more test data if you need to.

    // testing getData on known present data
    int shortTest = testdatasize/2;
    if (shortTest > 5)
        shortTest = 5;
    // starting output
    cout << endl;
    cout << "Testing getData w/ known present items..." << endl;
    for (int i = 0; i < shortTest; i++) {
        cout << "Getting ID: " << ids[i] << "... ";
        cout << "Data: " << table.getData(ids[i]);
        cout << endl;
    }

    // testing getData on data that does not exist in list
    int fakeIDs[] = {200, -1, -5, 300, 500};
    cout << endl;
    cout << "Testing getData w/ known NOT present items..." << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Iteration " << i << " of for loop..." << endl;
        cout << "Getting ID " << fakeIDs[i] << "... ";
        cout << "Data: " << table.getData(fakeIDs[i]);
        cout << endl;
    }

    // testing removeEntry on known present items
    bool success = false;
    cout << endl;
    cout << "Testing removeEntry w/ known present items..." << endl;
    for (int i = 0; i < shortTest; i++) {
        cout << "Removing ID " << ids[i] << "..." << endl;
        success = table.removeEntry(ids[i]);
        if (success) {
            cout << "ID " << ids[i] << " successfully removed." << endl;
        }
        else {
            cout << "ID " << ids[i] << " could not be removed." << endl;
        }
        cout << endl;
    }

    // print table to test if correctly removed
    table.printTable();
    cout << "Current count: " << table.getCount() << endl;


    // testing removeEntry on items known NOT to be present
    cout << endl;
    cout << "Testing removeEntry w/ known NOT present items..." << endl;
    for (int i = 0; i < shortTest; i++) {
        cout << "Removing ID " << fakeIDs[i] << "..." << endl;
        success = table.removeEntry(fakeIDs[i]);
        if (success) {
            cout << "ID " << fakeIDs[i] << " successfully removed." << endl;
        }
        else {
            cout << "ID " << fakeIDs[i] << " could not be removed." << endl;
        }
        cout << "Current count: " << table.getCount() << endl;
        cout << endl;
    }
    // print table to ensure table remained the same
    table.printTable();
    cout << "Current count: " << table.getCount() << endl;

    // end of program reached
    cout << endl << "testing complete." << endl;
    cout << "fin." << endl;
    return 0;
}
