///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "SinglyLinkedList.h"
#include "config.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() {

}

void SinglyLinkedList::push_front(Node *newNode) {
    if (newNode == nullptr){
        throw invalid_argument("Error: newNode is nullptr");
    }
    if (!newNode -> validate()){
        throw domain_error("Error: newNode is invalid");
    }
    if(isIn(newNode)){
        throw logic_error("Error: newNode in container already");
    }

    if (head != nullptr){
        newNode -> next = head;
        head = newNode;
    } else {
        newNode -> next = nullptr;
        head = newNode;
    }

    count++;
    validate();
}

Node* SinglyLinkedList::pop_front() noexcept {
    if(head == nullptr){
        return nullptr;
    }
    Node* value = head;
    head = head->next;
    count--;
    validate();
    return value;
}

void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {

    if(List::empty()){
        throw logic_error("Error: List is empty");
    }
    if(currentNode == nullptr){
        throw invalid_argument("Error: currentNode is nullptr");
    }
    if(isIn(newNode)){
        throw logic_error("Error: newNode in container already");
    }
    if(!isIn(currentNode)){
        throw logic_error("Error: currentNode not in list");
    }
    if(newNode == nullptr){
        throw invalid_argument("Error: newNode is nullptr");
    }

    newNode -> next = currentNode -> next;
    currentNode -> next = newNode;
    count++;
    validate();
}

void SinglyLinkedList::dump() const noexcept {
    Node* printNode = head;
    while (printNode != nullptr){
        printNode -> dump();
        printNode = printNode -> next;
    }
}

bool SinglyLinkedList::validate() const noexcept {
   if(!List::validate()){
       return false;
   }

    unsigned int n_count = 0;
    Node* currentNode = head;

    while( currentNode != nullptr){
        n_count++;
        currentNode = currentNode -> next;
    }
    return true;
}

