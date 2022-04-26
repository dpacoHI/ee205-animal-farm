///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"

/// A generic list-based collection class.
///
class List {
protected:
    // Protected Members
    Node* head = nullptr; // The head pointer for the collection
    unsigned int count = 0; // Maintains a count of the number of Node objects in the collection


public:
    // Static Methods
    static Node* get_next( const Node* currentNode );  // Gets the next Node in the List

    // Public Methods
    bool empty() const noexcept;         // Checks if List is empty
    unsigned int size() const noexcept;  // Gets the number of Node objects in the List
    bool isIn( Node* aNode ) const; // Checks if aNode is in the List
    bool isSorted() const noexcept; // Checks if the List is sorted
    Node* get_first() const noexcept;  // Gets the first Node in the List
    void deleteAllNodes() noexcept; // Deletes all of the nodes in the List

    // Abstract Methods
    virtual Node* pop_front() noexcept = 0;     // Removes and returns the first Node in the List
    virtual void dump() const noexcept = 0;      // Outputs the contents of this container
    virtual bool validate() const noexcept = 0;  // Checks to see if the container is valid
};