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

#include "catDatabase.h"
#include "config.h"

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


