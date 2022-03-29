///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "catDatabase.h"
#include "reportCats.h"
#include "config.h"

int printCat(NumCats index){
    // Check if index is less than 0 or more than number of cats in database
    if (index > MAX_CATS || index < 0){
        fprintf( stderr, "%s: Bad cat [%d]\n", PROGRAM_NAME, index);
        return 0;
    }
    else {
        printf("cat index = [%u] | name = [%s] | gender = [%s] | breed = [%s] | isFixed = [%d] | weight = [%f] | color1 = [%s] | color2 = [%s] | license = [%llu]\n", index, array_catData[index].nameData, gender_str(array_catData[index].genderData), breed_str(array_catData[index].breedData), array_catData[index].boolData, array_catData[index].weightData, color_str(array_catData[index].collar1), color_str(array_catData[index].collar2), array_catData[index].license);
    }
    return 1;
}

int printAllCats(void){
    // Print all cats by stepping up from i
    for (int i = 0; i < CURRENT_CATS; ++i){
        printf("cat index = [%u] | name = [%s] | gender = [%s] | breed = [%s] | isFixed = [%d] | weight = [%f] | color1 = [%s] | color2 = [%s] | license = [%llu]\n", i, array_catData[i].nameData, gender_str(array_catData[i].genderData), breed_str(array_catData[i].breedData), array_catData[i].boolData, array_catData[i].weightData, color_str(array_catData[i].collar1), color_str(array_catData[i].collar2), array_catData[i].license);
    }
    return 1;
}


int findCat(const char *name){
    // Scan for name in database
    for (int i = 0; i < MAX_CATS; ++i){
        if (strcmp(name, array_catData[i].nameData) == 0){
            printf("Cat %s is in index %u\n", array_catData[i].nameData, i);
            return i;
        }
        // Returns index number if found
    }
    return 0; // Returns error if not found
}
