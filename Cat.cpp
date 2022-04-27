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
#include <iomanip>
#include <cassert>
#include "Cat.h"
#include "config.h"
using namespace std;

const string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

string Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const string &newName) {
    if(validateName(newName)){
        throw invalid_argument("ERROR: Invalid Name");
    }
    name = newName;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    Cat::isCatFixed = true;
}

string Cat::speak() const noexcept {
    return "Meow";
}

void Cat::dump() const noexcept {
    Mammal::dump();
    FORMAT_LINE_FOR_DUMP("Cat", "name") << getName() << endl;
    FORMAT_LINE_FOR_DUMP("Cat", "isFixed") << isFixed() << endl;
}

bool Cat::validateName(const string &newName) {
    if(newName.empty()){
        throw invalid_argument("ERROR: newName cannot be empty");
    }
    return true;
}

bool Cat::validate() const noexcept {
    Mammal::validate();
    assert(validateName(getName()));
    return true;
}