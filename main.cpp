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

#include "Cat.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
#include <iostream>
using namespace std;
// #include "config.h"

int main ( ) {
    cout << "Starting " << PROGRAM_NAME << "\n";
  /*  addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101) ;
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
    printAllCats();*/

/* OLD DEBUG STATEMENTS (PRE-OOP)
 * #ifdef DEBUG
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
#endif*/
/*#ifdef DEBUG
    {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == Gender::UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(!testCat.isFixed());
      assert(!testCat.validate());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatInDatabase(&testCat)) ;
   }
#endif

    addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
    addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
    addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
    addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
    addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // Verify that Bella's not there
      } catch (exception const &e) {}

      bella = nullptr;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;*/
    cout << "Ending " << PROGRAM_NAME << "\n";
}
