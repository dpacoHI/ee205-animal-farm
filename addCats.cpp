///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "addCats.h"
#include "catDatabase.h"
#include "config.h"

const int addCat(const char *name, const enum gender gender, const enum breed breed, const bool isFixed, const Weight weight,const enum Color collar1_color, const enum Color collar2_color, const unsigned long long int license){

    // Check if database is full
    if (CURRENT_CATS > MAX_CATS){
        fprintf( stderr, "%s: %d is more than the maximum of %d cats.\n", PROGRAM_NAME, CURRENT_CATS, MAX_CATS);
        return 0;
    }

    // Check if cat name is blank
    if (strlen(name) <= 0 ){
        fprintf( stderr, "%s: Give the cat a name... not a blank.\n", PROGRAM_NAME);
        return 0;
    }

    // Check if cat name is longer than 30 characters
    if (strlen(name) > MAX_NAME_LENGTH){
        fprintf( stderr, "%s: The cat's name length of %ld is longer than %d.\n", PROGRAM_NAME, strlen(name), MAX_NAME_LENGTH);
        return 0;
    }

    // Check if cat name is unique throughout all of database
    for (int i = 0; i <= MAX_CATS; ++i){
        if (name == array_catData[i].nameData){
            fprintf( stderr, "%s: There already is a %s in our database.\n", PROGRAM_NAME, name);
            return 0;
        }
    }

    // Check if cat weight is greater than 0
    if (weight <= 0){
        fprintf( stderr, "%s: The cat must weigh greater than 0.\n", PROGRAM_NAME);
        return 0;
    }

    // If validations all pass, send data into database arrays and add a number of cats.
    // CURRENT_CATS++;
    // strncpy(nameData[CURRENT_CATS], name, MAX_NAME_LENGTH);
    // genderData[CURRENT_CATS]= gender;
    // breedData[CURRENT_CATS]= breed;
    // boolData[CURRENT_CATS]= isFixed;
    // weightData[CURRENT_CATS]= weight;

    // If validations all pass, send data into structure and add a number of cats.
    strncpy(array_catData[CURRENT_CATS].nameData, name, MAX_NAME_LENGTH);
    array_catData[CURRENT_CATS].genderData = gender;
    array_catData[CURRENT_CATS].breedData = breed;
    array_catData[CURRENT_CATS].boolData = isFixed;
    array_catData[CURRENT_CATS].weightData = weight;
    array_catData[CURRENT_CATS].collar1 = collar1_color;
    array_catData[CURRENT_CATS].collar2 = collar2_color;
    array_catData[CURRENT_CATS].license = license;
    CURRENT_CATS++;
    return 1;

}

