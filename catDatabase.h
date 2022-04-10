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
    // Getters
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

