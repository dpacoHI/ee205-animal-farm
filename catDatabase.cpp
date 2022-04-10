///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cassert>
#include "catDatabase.h"
#include "config.h"
using namespace std;

//char nameData[MAX_CATS][MAX_NAME_LENGTH];
//enum Gender genderData[MAX_CATS];
//enum Breed breedData[MAX_CATS];
//bool boolData[MAX_CATS];
//Weight weightData[MAX_CATS];

// Current Number of Cats initialized to 0
NumCats CURRENT_CATS = 0;

// Declare an array of the structure
struct catData array_catData[MAX_CATS];

// Printing out Enums as Strings...
const char* gender_str(enum Gender genderData)
{
    switch (genderData)
    {
        case UNKNOWN_GENDER: return "Unknown";
        case MALE: return "Male";
        case FEMALE: return "Female";
    }
    return 0;
}

const char* breed_str(enum Breed breedData)
{
    switch (breedData)
    {
        case UNKNOWN_BREED:  return "Unknown";
        case MAINE_COON:     return "Maine Coon";
        case MANX:           return "Manx";
        case SHORTHAIR:      return "Shorthair";
        case PERSIAN:        return "Persian";
        case SPHYNX:         return "Sphynx";
    }
    return 0;
}

const char* color_str(enum Color colorData)
{
    switch (colorData)
    {
        case BLACK: return "Black";
        case WHITE: return "White";
        case RED:   return "Red";
        case BLUE:  return "Blue";
        case GREEN: return "Green";
        case PINK:  return "Pink";
    }
    return 0;
}


bool Cat::checkName(const char newName[]) {
    if (newName == nullptr) { // Detects that name is not nullptr
        cout << "ERROR: Null Pointer Detected!\n";
        return false;
    }
    if (strlen(newName) <= 0) { // Detects that name is not empty
        cout << "ERROR: Cats need a name.\n";
        return false;
    }
    if (strlen(newName) > MAX_NAME_LENGTH) {
        cout << "ERROR: Inputted name is too long\n";
        return false;
    }
    return true;
}

bool Cat::checkGender(Gender newGender){
    if( newGender == UNKNOWN_GENDER ){
        cout << "ERROR: Gender must be known.\n";
        return false;
    }
    return true;
}

bool Cat::checkBreed(Breed newBreed){
    if( newBreed == UNKNOWN_BREED){
        cout << "ERROR: Breed must be known.\n";
        return false;
    }
    return true;
}

bool Cat::checkWeight(Weight newWeight){
    if(newWeight <= 0){
        cout << "ERROR: Cat's weight must be greater than 0.\n";
        return false;
    }
    return true;
}

bool Cat::validate(){
    try {
        checkName(name);
        checkGender(gender);
        checkBreed(breed);
        checkWeight(weight);
    }
    catch (exception) {
        return false;
    }
    return true;
}

bool Cat::print(){
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << getGender() << endl ;
    FORMAT_LINE( "Cat", "breed" ) << getBreed() << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << getFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}

