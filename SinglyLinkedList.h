///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"
#include "List.h"

class SinglyLinkedList : public List {
public:
    // Public Constructor
    SinglyLinkedList(); // Makes a new SinglyLinkedList

    // Public Methods
    void  push_front(Node* newNode);  // Inserts newNode to the beginning of the List
    Node* pop_front() noexcept override; // Removes and returns the first Node in the List
    void insert_after( Node* currentNode, Node* newNode ); // Inserts newNode after currentNode
    void dump() const noexcept override; // Outputs the contents of this container
    bool validate() const noexcept override; // Checks to see if the container is valid
};
