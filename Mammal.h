///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Animal.h"
#include "Color.h"

using namespace std;

class Mammal : public Animal {
public:   // Constants
    static const std::string MAMMAL_NAME;

protected:  // Member Variables
    Color color = Color::UNKNOWN_COLOR;

public:
    // Constructors
    Mammal( const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};

    Mammal( const Color            newColor
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies)
            : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies )
            { setColor( newColor ); };

    // Getters & Setters
    Color getColor() const noexcept { return color; }
    void setColor( const Color newColor ) noexcept { color = newColor; }

    // Public Methods ////////////////////////////
    void dump() const noexcept override;
};