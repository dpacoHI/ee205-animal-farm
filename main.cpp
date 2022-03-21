/////////////////////////////////////////////////////////////////////////////
//
/// University of Hawaii, College of Engineering
/// @brief Lab 08d - Animal Farm 1 Conversion to CLion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.1
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date 20_Mar_2022
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
// #include "config.h"

int main ( ) {

    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106) ;

    printAllCats();

    int kali = findCat( "Kali" ) ;

    updateCatName( kali, "Chili" ) ; // this should fail
    printCat( kali );
    updateCatName( kali, "Capulet" ) ;
    updateCatWeight( kali, 9.9 ) ;
    fixCat( kali ) ;
    printCat( kali );

    printAllCats();

    deleteAllCats();
    printAllCats();
#ifdef DEBUG
    // Testing Empty Name
   assert( addCat( "", MALE, PERSIAN, false, 19.0, BLACK, BLACK, 101 ) == false );
   // Testing Max Name
   assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) == false );
   // Testing Long Name
   assert( addCat( ILLEGAL_NAME, MALE, MANX, false, 22.0, WHITE, RED, 135 ) == false );
   // Testing Duplicate Name
   assert( addCat( "Trin", MALE, MANX, false, 34.0, BLUE, BLUE, 213 ) == false );
   // Testing Illegal Weight
   assert( addCat( "David", MALE, SPHYNX, true, -4, BLUE, RED, 211 ) == false );
#endif

}
