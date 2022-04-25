///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <cassert>

#include "Cat.h"
#include "deleteCats.h"
#include "config.h"
using namespace std;

/*
bool deleteCat(Cat* deleteChosenCat){
    assert(deleteChosenCat != nullptr);
//    assert(validateDatabase());

    if(deleteChosenCat == catDatabaseHPointer){
        catDatabaseHPointer = catDatabaseHPointer->next;
        delete deleteChosenCat;
        CURRENT_CATS--;

        assert(validateDatabase());
        return true; // Successful Deletion
    }
    Cat* FindCat = catDatabaseHPointer;
    while(FindCat != nullptr){
        if(FindCat->next == deleteChosenCat){
            FindCat->next = deleteChosenCat->next;
            delete deleteChosenCat;
            CURRENT_CATS--;
            assert(validateDatabase());
        }
    }
    return true;
}
bool deleteAllCats(void){
    while(catDatabaseHPointer != nullptr){
        deleteCat(catDatabaseHPointer);
    }
    return true;
}
*/

