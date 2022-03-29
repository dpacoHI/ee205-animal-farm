///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

extern int updateCatName(const NumCats index, const char newName[]);

extern int fixCat(const NumCats index);

extern int updateCatWeight(const NumCats index, const Weight newWeight);

extern int updateCatCollar1(const NumCats index, Color newCollar1);

extern int updateCatCollar2(const NumCats index, Color newCollar2);

extern int updateLicense(const NumCats index, const int newLicense);

