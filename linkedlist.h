/*
 * COSC 2436
 * Zachary Hall
 * Linked Lists Assignment 
 * 10/4/23
 */
 
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include "testdata.h"
#include "iostream"

class LinkedList {

public:
	
    LinkedList();
    ~LinkedList();
    int getCount();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    bool clearList();
    bool exists(int);
    void printList(bool = false);
    
private:
    Node *head;
    bool addHead(Node*, Node*);
    void assignNode(int, string*,Node* );
};

#endif 