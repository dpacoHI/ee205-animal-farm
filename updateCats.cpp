///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "catDatabase.h"
#include "updateCats.h"
#include "config.h"

int updateCatName(NumCats index, char newName[]){
    // Check that index is not less than 0 or more than max number of cats
    if (index < 0 || index > MAX_CATS){
        fprintf( stderr, "%s: Bad Cat [%d]\n", PROGRAM_NAME, index);
        return 0;
    }
    // Check that newName is not blank
    if (strlen(newName) <= 0){
        fprintf( stderr, "%s: New cat name cannot be blank.\n", PROGRAM_NAME);
        return 0;
    }
    // Check that newName is not longer than max length
    if (strlen(newName) > MAX_NAME_LENGTH){
        fprintf( stderr, "%s: The new cat name is longer than %d.\n", PROGRAM_NAME, MAX_NAME_LENGTH);
        return 0;
    }
    // Check that newName is unique
    for (int i = 0; i < MAX_CATS; ++i){
        if (strcmp(newName, array_catData[i].nameData)==0){
            fprintf( stderr, "%s: There is already a %s in our database.\n", PROGRAM_NAME, newName);
            return 0;
        }
    }
    // If validations all pass, update cat name
    strncpy(array_catData[index].nameData, newName, MAX_NAME_LENGTH);
    return 1;
}

int fixCat(NumCats index){
    // Check that index is not less than 0 or greater than max number of cats
    if (index < 0 || index > MAX_CATS){
        fprintf( stderr, "%s: Bad cat [%d]\n", PROGRAM_NAME, index);
        return 0;
    }
    // Fix the cat
    array_catData[index].boolData = true;
    return 1;
}

int updateCatWeight(NumCats index, Weight newWeight){
    if (index < 0 || index > MAX_CATS){
        fprintf( stderr, "%s: Bad cat [%d]\n", PROGRAM_NAME, index);
        return 0;
    }
    if (newWeight < 0){
        fprintf( stderr, "%s: New weight must be greater than 0.\n", PROGRAM_NAME);
        return 0;
    }
    array_catData[index].weightData = newWeight;
    return 1;
}

int updateCatCollar1(NumCats index, Color newCollar1 ){
    array_catData[index].collar1 = newCollar1;
    return 1;
}

int updateCatCollar2(NumCats index, Color newCollar2 ){
    array_catData[index].collar2 = newCollar2;
    return 1;
}

int updateLicense( NumCats index, int newLicense ){
    array_catData[index].license = newLicense;
    return 1;
}

int updateCatName(const NumCats index, const char *newName) {
    return 0;
}

