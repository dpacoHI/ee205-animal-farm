///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "catDatabase.h"

#pragma once

extern const int addCat(const char name[], const enum gender gender, const enum breed breed, const bool isFixed, const float weight, const enum Color collar1_color, const enum Color collar2_color, const unsigned long long license );

// extern int addCat( name[], gender, breed, isFixed, weight);

