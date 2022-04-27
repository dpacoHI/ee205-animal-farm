///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include "config.h"

class Node {

    friend class List;
    friend class SinglyLinkedList;

protected:
    // Protected Members
    Node* next = nullptr;  // Points to the next Node in the list or `nullptr`

    // Static Methods
    static bool compareByAddress ( const Node* node1, const Node* node2 ) {
        if( node1 > node2 )
            return true;
        return false;
    } // Checks that node1 is greater than node 2, if not return false.


public:
    // Public Methods
    virtual void dump() const {
        PRINT_HEADING_FOR_DUMP;
        FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl ;
    } // Print contents of node

    virtual bool validate() const noexcept {
        if( next == nullptr ) {
            return true;
        }

        if( next == next->next ) {
            std::cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
            return false;
        }

        return true;
    } // Checks if node is valid

    virtual bool operator>(const Node& rightSide) {
        return compareByAddress( this, &(Node&)rightSide );
    } // Compares leftside > rightside

}; // class Node
