///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <iostream>
#include <iomanip>
#pragma once

#include "config.h"

using namespace std;

#define MAX_NAME_LENGTH 50
#define MAX_CATS 1024
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

// Declare Enums for Gender and Breed
enum class Gender {UNKNOWN_GENDER = 0, MALE, FEMALE};
enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};
enum class Color {UNKNOWN_COLOR = 0, BLACK, BROWN, WHITE, RED, BLUE, GREEN, GINGER, CREAM, CINNAMON, CALICO};

// Converting Enum classes to printing as strings

inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender ) {
    switch( rhs_Gender ) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
        case Gender::MALE:
            lhs_stream << "Male";
            break;
        case Gender::FEMALE:
            lhs_stream << "Female";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }

    return lhs_stream;
}

inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ) {
    switch( rhs_Color ) {
        case Color::UNKNOWN_COLOR:
            lhs_stream << "Unknown color";
            break;
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::BROWN:
            lhs_stream << "Brown";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::GINGER:
            lhs_stream << "Ginger";
            break;
        case Color::CREAM:
            lhs_stream << "Cream";
            break;
        case Color::CINNAMON:
            lhs_stream << "Cinnamon";
            break;
        case Color::CALICO:
            lhs_stream << "Calico";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
    }

    return lhs_stream;
}
// Typedefs
typedef float Weight;
typedef int NumCats;

// Global Variables
//extern char nameData[MAX_CATS][MAX_NAME_LENGTH];
//extern enum Gender genderData[MAX_CATS];
//extern enum Breed breedData[MAX_CATS];
//extern bool boolData[MAX_CATS];
//extern float weightData[MAX_CATS];
extern NumCats CURRENT_CATS;

// Conversion from 5 Arrays to 1 Array of a Structure

/*extern struct catData
{
    char nameData[MAX_NAME_LENGTH];
    enum Gender genderData;
    enum Breed breedData;
    bool boolData;
    Weight weightData;
    enum Color collar1;
    enum Color collar2;
    unsigned long long license;
} array_catData[MAX_CATS];*/

// Implementation of Cat Class
class Cat : public Mammal {

protected:
    // Members
    char name[MAX_NAME_LENGTH];
    enum Gender gender;
    enum Breed  breed;
    bool        isCatFixed;
    Weight      weight;
public:
    // Only Public Member
    Cat* next;

    // Getters and Setters (with Validations)
    char* getName() {
        return name;
    }
    void setName (const char newName[]){
        checkName(newName);
        memset(name, 0, MAX_NAME_LENGTH);
        strcpy(name, newName);
    }

    Gender getGender(){
        return gender;
    }
    void setGender (Gender newGender){
        if( gender != Gender::UNKNOWN_GENDER ){
            cout << "Gender is set and cannot be changed.\n";
            return;
        }
        checkGender(newGender);
        gender = newGender;
    }

    Breed getBreed(){
        return breed;
    }
    void setBreed (Breed newBreed){
        if( breed != UNKNOWN_BREED ){
            cout << "Breed is set and cannot be changed.\n";
            return;
        }
        checkBreed(newBreed);
        breed = newBreed;
    }

    bool getFixed(){
        return isCatFixed;
    }
    void fixCat(){
        isCatFixed = true;
    }

    Weight getWeight(){
        return weight;
    }
    void setWeight(Weight newWeight){
        checkWeight(newWeight);
        weight = newWeight;
    }


    // Constructors and Destructors
    Cat(); // Constructor with no Parameters
    Cat( const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight); // Constructor with fields for valid cat.
    ~Cat(); // Destructor


    // Methods
    void setZero(); // Initializes or Deletes Data
    bool print(); // Prints Cat
    bool validate(); // Checks if Cat is Valid
    static bool checkName(const char* newName ) ; // Checks Cat's Name
    static bool checkGender(const Gender newGender); // Checks Cat's Gender
    static bool checkBreed(const Breed newBreed); // Checks Cat's Breed
    static bool checkWeight(const Weight newWeight); // Checks Cat's Weight
};

// Linked List Implementation
extern Cat* catDatabaseHPointer;
extern bool validateDatabase();

extern const char* gender_str(const enum Gender gender);
extern const char* breed_str(const enum Breed breed);
extern const char* color_str(const enum Color colorData);

