/*
 * COSC 2436
 * Zachary Hall
 * Linked Lists Assignment 
 * 10/4/23
 */

#include "linkedlist.h"
LinkedList::LinkedList(){
	head = NULL;
}

	bool LinkedList::addHead(Node* current, Node* newNode){
		bool added = false;
		
		if (current->data.id == newNode->data.id){
			added = false;
		}
		else if (current->data.id > newNode->data.id){
			if(!current->prev){
				head->prev = newNode;
				newNode->prev = NULL;
				newNode->next = head;
				head = newNode;
				added = true;
			} else {
				newNode->next = current;
				newNode->prev = current->prev;
				current->prev->next = newNode;
				current->prev - newNode;
				added = true;
			}
		}
		else if (current->next){
			added = addHead(current->next, newNode);
		} else {
			newNode->next = NULL;
			newNode->prev = current;
			current->next = newNode;
			added = true;
		}
		return added;
	}

	
	bool LinkedList::addNode(int id, std::string* data) {
        bool working = false;
				
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
       bool deletion = false;

        Node* current = head;
        if (current != NULL) {
           while (current && current->next && current->data.id == id){
           	current = current->next;
					 }
        if (current->prev == NULL && current->data.id == id){
        	head = current->next;
        	current->next = NULL;
        	delete current;
        	deletion = true;
				}
        else if (current->prev && current->next){
        	current->prev->next = current->next;
        	current->next->prev = current->prev;
        	delete current;
        	deletion = true;
				}
				else if (current->next == NULL && current->data.id == id){
					current->prev->next = NULL;
					delete current;
					deletion = true;
				}
  }
  return deletion;
}
    
    bool LinkedList::getNode(int id, Data* data) {
        bool nodeAquired = false;
        if (head != NULL) {
          Node* current = head;
          while (current != NULL){
          	if (current->data.id == id){
          		data->id = current->data.id;
          		data->data = current->data.data;
          		nodeAquired = true;
						}
						current = current->next;
				}
		}
		return nodeAquired;	
  }
    
    void LinkedList::printList(bool backwards) {
    		Node* current = head;
        int printcount = 0;
    
    if (!backwards) {
        while (current != NULL) {
            std::cout << printcount << "(" << current->data.id << ", " << current->data.data << ") " << std::endl;
            current = current->next;
            printcount++;
    	}
    }
    
    if (backwards){
    	printcount = this->getCount()-1;
    	while(current->next){
    		current = current->next;
			}
			while(current){
				std::cout << printcount << "(" << current->data.id << ", " << current->data.data << ") " << std::endl;
				printcount--;
				current = current->prev;
			}
		}
}

	void LinkedList::assignNode(int id, string* data, Node* newNode){
		Data* newData = new Data{id, *data};
		newNode->data = *newData;
	}
    
    int LinkedList::getCount() {
       int count = 0;
       Node* current = head;
       while (current != NULL){
       	count++;
       	current = current->next;
			 }
			 return count;
    }
    
       bool LinkedList::clearList() {
        bool listCleared = false;
          if(head != NULL){
          	Node *current = head;
						while (current != NULL){
							if(current->next != NULL){
							head = current->next;
						}
						current->prev = NULL;
						Node* temp = current->next;
						delete current;
						current = temp;
					}
					}
            head = NULL;
            listCleared = true;
          	return listCleared;       
}

 
     bool LinkedList::exists(int id) {
        bool does_exist = false;
        if (head != NULL) {
        		Node* current = head;
        	while(current != NULL){
            if (current->data.id == id) {
                does_exist = true;
            }
            current = current->next;
        }
    }
      return does_exist;
}
    

LinkedList::~LinkedList() {
	clearList();
}
	