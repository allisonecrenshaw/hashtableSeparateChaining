/*********************
Name: Allison Crenshaw
Coding 05
Purpose: This program constructs a fully
 functional doubly linked list class.
**********************/

// include only header file directly
#include "linkedlist.h"

// all linked list methods go here

/*******************************
 * constructor and destructor
*******************************/
LinkedList::LinkedList() {
    head = NULL;
}
LinkedList::~LinkedList() {
    clearList();
}






/*******************************
 * addNode, compareNodes
*******************************/
bool LinkedList::addNode(int passedID, string passedString) {
    bool ok = false;

    // check if given id is negative
    if (passedID > 0) {
        if (head == NULL) { // if head null, assign passed args to head
            ok = true;
            head = new Node;
            head->data.id = passedID;
            head->data.data = passedString;
            head->prev = NULL;
            head->next = NULL;
            //cout << "First head added...";
        }
        else { // if not negative and head exists
            ok = compareNodes(passedID, passedString);
        } // end outer else (for valid data that is not the first node added)
    } // end of if value is non-negative

    return ok;
} // end addNode



bool LinkedList::compareNodes(int passedID, string passedString) {
    bool ok = false;
    bool stop = false;
    Node *current;
    Node *previous;
    int loopCount = 0;

    // start with head
    current = head;

    // while not ok and next still exists
    //cout << "Begin while loop." << endl;
    while (current && stop == false) {
        loopCount++;
        //cout << "Loop #" << loopCount << "...current ID is " << current->data.id << endl;
        if (passedID < current->data.id) {
            //cout << "Passed ID < current ID, changing stop to true." << endl;
            stop = true;
        }
        else {
            //cout << "Moving to next item." << endl;
            //cout << "Changing previous to current"<< endl;
            previous = current;
            //cout << "Changing current to next." << endl;
            current = current->next;
        }
    } // end while

    // head case: current not null (haven't reached tail) + less than head
    if (current && passedID < current->data.id && !current->prev) {
        ok = true;
        addHeadNode(passedID, passedString);
        //cout << "Head added...";
    } // else if we're less than current, but not head (prev), and not equal to the prev
    else if (current && passedID < current->data.id && passedID != previous->data.id) {
        ok = true;
        addMiddleNode(passedID, passedString, previous, current);
        //cout << "Middle added...";
    } // else if we are at the tail
    else if (!current && passedID > previous->data.id) {
        ok = true;
        addTailNode(passedID, passedString, previous);
        //cout << "Tail added...";
    }

    return ok;
} // end compareNodes





/*******************************
 * addHeadNode, addMiddleNode,
 * addTailNode
*******************************/
void LinkedList::addHeadNode(int passedID, string passedString) {
    // allocate mem for a new node
    Node *newNode = new Node; // will hold passed data
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign next and prev as needed
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode; // moves current head up in list
    head = newNode; // gives new value to head
} // end addHeadNode()

void LinkedList::addMiddleNode(int passedID, string passedString,
                               Node* previous, Node* current) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign previous and next vals so that links are not lost
    previous->next = newNode;
    newNode->prev = previous;
    current->prev = newNode;
    newNode->next = current;
} // end addMiddleNode()

void LinkedList::addTailNode(int passedID, string passedString, Node* previous) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign current to new tail, make tail point to current as its prev
    newNode->next = NULL;
    newNode->prev = previous;
    previous->next = newNode;
} // end addTailNode()




/*******************************
 * deleteNode, getNode
*******************************/
bool LinkedList::deleteNode(int id) {
    bool found = false;
    Node *current;

    current = head;
    while (current && !found) {
        if (id == current->data.id)
            found = true;
        else
            current = current->next;
    }

    if (found && current) {
        if (!current->prev && !current->next) {
            head = NULL;
            delete current;
        }
        else if (!current->prev) {
            head = current->next;
            head->prev = NULL;
            delete current;
        } else if (!current->next) {
            current->prev->next = NULL;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
    return found;
} // end deleteNode()

bool LinkedList::getNode(int id, Data* newData) {
    bool found = false;
    Node *current;

    current = head;
    while (current && !found) {
        if (id == current->data.id) {
            found = true;
        } else
            current = current->next;
    }

    if (found) {
        newData->id = current->data.id;
        newData->data = current->data.data;
    } else {
        newData->id = -1;
        newData->data = "";
    }
    return found;
} // end getNode()





/*******************************
 * remaining functions
*******************************/
void LinkedList::printList(bool order) {
    Node *current;
    bool tailReached = false;
    current = head;
    string line = "******************************";

    if (order == false) { // if false, print list forward (default)
        cout << endl << line << endl;
        cout << "Printing linked list..." << endl;
        while (current) {
            cout << current->data.id << endl;
            current = current->next;
        }
        cout << "End of linked list." << endl << line << endl;
    }
    else { // if true, print list backwards
        cout << endl << line << endl;
        cout << "Printing linked list backwards..." << endl;
        while (!tailReached) {
            if (!current->next) {
                tailReached = true;
            }
            else
                current = current->next;
        }
        while (current) {
            cout << current->data.id << endl;
            current = current->prev;
        }
        cout << "End of linked list." << endl << line << endl;
    }
}

int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList() {
    Node *current;
    Node *next;

    current = head;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    return true;
}

bool LinkedList::exists(int id) {
    bool exists = false;
    Node *current;
    current = head;
    while (current && !exists) {
        if (id == current->data.id)
            exists = true;
        else
            current = current->next;
    }
    return exists;
}



