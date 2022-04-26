///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "config.h"
#include "Animal.h"

using namespace std;
const string Animal::KINGDOM_NAME = "Animalia";

Animal::Animal(const Weight::t_weight newMaxWeight, const std::string &newClassification,
               const std::string &newSpecies) {
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {
    setGender(newGender);
    weight.setWeight(newWeight);
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

void Animal::setGender(const Gender newGender) {
    if(gender != Gender::UNKNOWN_GENDER){
        throw logic_error("Error: Gender is set");
    }
    gender = newGender;
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    weight.setWeight(newWeight);
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if(checkClassification.empty()) {
        cout << "Error: Classification must be specified" << endl;
        return false;
    }
    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if(checkSpecies.empty()){
        return false;
    }
    return true;
}

void Animal::dump() const noexcept {
    Node::dump();
    FORMAT_LINE_FOR_DUMP("Animal", "this")              << this << endl;
    FORMAT_LINE_FOR_DUMP("Animal", "kingdom")           << getKingdom() << endl;
    FORMAT_LINE_FOR_DUMP("Animal", "classification")    << getClassification() << endl;
    FORMAT_LINE_FOR_DUMP("Animal", "species")           << getSpecies() << endl;
    FORMAT_LINE_FOR_DUMP("Animal", "gender")            << getGender() << endl;
    FORMAT_LINE_FOR_DUMP("Animal", "weight")            << getWeight() << endl;
}

bool Animal::validate() const noexcept {
    if(!Node::validate()){
        return false;
    }
    if(KINGDOM_NAME.compare("Animal")){
        return false;
    }
    if(!validateClassification(getClassification())){
        return false;
    }
    if(!validateSpecies(getSpecies())){
        return false;
    }
    if(!weight.isWeightValid(getWeight())){
        return false;
    }
    return true;
}

