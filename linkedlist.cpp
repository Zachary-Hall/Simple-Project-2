/*
 * COSC 2436
 * Zachary Hall
 * Linked Lists Assignment 
 * 10/4/23
 */

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr;
}

bool LinkedList::addHead(Node* current, Node* newNode) {
		bool added = false;
		if (current->data.id == newNode->data.id) {
    added = false;
    }
    else if (current->data.id > newNode->data.id) {
        if (!current->prev) {
            head->prev = newNode;
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
            added = true;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        added = true;
    }
    else if (current->next) {
        added = addHead(current->next, newNode);
    } else {
        newNode->next = nullptr;
        newNode->prev = current;
        current->next = newNode;
        return added = true;
    }
    return added;
}

	
	bool LinkedList::addNode(int id, std::string* data) {
				bool working = false;
				if(id <= 0 || *data == ""){
        working = false;
			}
				if(id > 0 && *data != ""){
        if (!head) {
        		Node* newNode = new Node;
        		assignNode(id, data, newNode);
        		head = newNode;
            newNode->next = NULL;
            head->prev = NULL;
            working = true;
        } else {
        		Node *newNode = new Node;
        		assignNode(id, data, newNode);
        		working = addHead(head, newNode);
        }
    }
        return working;
  }

bool LinkedList::deleteNode(int id) {
    Node* current = head;
		bool deletion = false;
    while (current) {
        if (current->data.id == id) {
            if (current->prev == nullptr) {
                head = current->next;
                if (current->next) {
                    current->next->prev = nullptr;
                }
                delete current;
                deletion = true;
            } else if (current->next) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                deletion = true;
            } else {
                current->prev->next = nullptr;
                delete current;
                deletion = true;
            }
        }
        current = current->next;
    }
    return deletion;
}

bool LinkedList::getNode(int id, Data* data) {
    Node* current = head;
		bool nodeAquired = false;
    while (current) {
        if (current->data.id == id) {
            data->id = current->data.id;
            data->data = current->data.data;
            nodeAquired = true;
        }
        current = current->next;
    }

    return nodeAquired;
}

void LinkedList::printList(bool backwards) {
    Node* current = head;
    int printCount = 0;
    if (!backwards) {
        while (current) {
            std::cout << printCount << "(" << current->data.id << ", " << current->data.data << ") " << std::endl;
            current = current->next;
            printCount++;
        }
    }

    if (backwards) {
        printCount = this->getCount() - 1;
        while (current->next) {
        	current = current->next;
				}
        while(current){
					std::cout << printCount << "(" << current->data.id << ", " << current->data.data << ") " << std::endl;
        	current = current->prev;
					printCount--;
        }
    }
}

void LinkedList::assignNode(int id, std::string* data, Node* newNode) {
    Data newData{id, *data};
    newNode->data = newData;
}

int LinkedList::getCount() {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList() {
    Node* current = head;
    bool cleared = false;
    while (current) {
        if (current->next) {
            head = current->next;
        }
        current->prev = nullptr;
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    return cleared;
}

bool LinkedList::exists(int id) {
    Node* current = head;
		bool exists = false;
    while (current) {
        if (current->data.id == id) {
            exists = true;
        }
        current = current->next;
    }

    return exists;
}

LinkedList::~LinkedList() {
    clearList();
}