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
#include <string.h>
#include <iostream>
#pragma once

using namespace std;

#define MAX_NAME_LENGTH 50
#define MAX_CATS 1024

// Declare Enums for Gender and Breed
enum Gender {UNKNOWN_GENDER, MALE, FEMALE};
enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};
enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};

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

extern struct catData
{
    char nameData[MAX_NAME_LENGTH];
    enum Gender genderData;
    enum Breed breedData;
    bool boolData;
    Weight weightData;
    enum Color collar1;
    enum Color collar2;
    unsigned long long license;
} array_catData[MAX_CATS];

// Implementation of Cat Class
class Cat{

protected:
    // Members
    char name[MAX_NAME_LENGTH];
    enum Gender gender;
    enum Breed  breed;
    bool        isCatFixed;
    Weight      weight;
    Cat*        next;
public:
    // Getters and Setters (with Validations)
    char* getName() {
        return name;
    }
    void setName (const char newName[]){
        if (newName == nullptr){ // Detects that name is not nullptr
            cout << "ERROR: Null Pointer Detected!\n";
            return;
        }
        if (strlen(newName) <= 0){ // Detects that name is not empty
            cout << "ERROR: Cats need a name.\n";
            return;
        }
        if (strlen(newName) > MAX_NAME_LENGTH){
            cout << "ERROR: Inputted name is too long\n";
            return;
        }
        strcpy(name, newName);
    }

    Gender getGender(){
        return gender;
    }
    void setGender (Gender newGender){
        if( gender != UNKNOWN_GENDER ){
            cout << "Gender is set and cannot be changed.\n";
            return;
        }
        if( newGender == UNKNOWN_GENDER ){
            cout << "ERROR: Gender must be known.\n";
            return;
        }
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
        if( newBreed == UNKNOWN_BREED){
            cout << "ERROR: Breed must be known.\n";
            return;
        }
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
        if(newWeight <= 0){
            cout << "ERROR: Cat's weight must be greater than 0.\n";
            return;
        }
        weight = newWeight;
    }


    // Constructors and Destructors
    Cat(); // Constructor with no Parameters
    Cat( const char* newName,
         const Gender newGender,
         const Breed newBreed,
         const Weight newWeight); // Constructor with fields for valid cat.
    ~Cat(); // Destructor

};
extern const char* gender_str(const enum Gender genderData);
extern const char* breed_str(const enum Breed breedData);
extern const char* color_str(const enum Color colorData);

