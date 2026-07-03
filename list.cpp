#include<iostream>
#include "list.h"

using namespace std;
 
List::List(){
    size = 0;
    sentinel_head = new Node();
    sentinel_tail = new Node();
    sentinel_head -> next = sentinel_tail;
    sentinel_head -> prev = NULL;
    sentinel_tail -> prev = sentinel_head;
    sentinel_tail -> next = NULL;
}

List:: ~List(){
    Node* temp = sentinel_head;
    while(temp->next!=NULL){
        temp = temp -> next;
        delete temp -> prev;
    }
    delete temp;
}

void List::insert(int v){
    Node* temp = new Node(v,sentinel_tail,sentinel_tail -> prev);
    sentinel_tail -> prev -> next = temp;
    sentinel_tail -> prev = temp;
    size++;
}

int List::delete_tail(){
    if(!sentinel_tail -> prev -> is_sentinel_node()){
        Node* temp = sentinel_tail->prev;
        int d = temp -> get_value();
        temp -> prev -> next = sentinel_tail;
        temp -> next = NULL;
        sentinel_tail -> prev = sentinel_tail -> prev -> prev;
        temp -> prev = NULL;
        size--;
        delete temp;   
        return d;
    }
    return 0;
}

int List::get_size(){
    return size;
}

Node* List::get_head(){
    return sentinel_head;
}
