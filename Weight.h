///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <ostream>

class Weight {
public:
    // Enumerations & Type Definitions
    enum UnitOfWeight { POUND, KILO, SLUG };
    typedef float t_weight;
    void setMaxWeight( t_weight newMaxWeight );

    // Constants
    static const t_weight UNKNOWN_WEIGHT;    // When a weight is not known, return this.
    static const t_weight KILOS_IN_A_POUND;  // The number of kilos in a pound
    static const t_weight SLUGS_IN_A_POUND;  // The number of slugs in a pound

    static const std::string POUND_LABEL;       // Unit of measure for the pound
    static const std::string KILO_LABEL;        // Unit of measure for the kilogram
    static const std::string SLUG_LABEL;        // Unit of measure for the slug

private:
    // Member Variables
    bool bIsKnown = false;  // `true` if Weight is known.  Defaults to `false`.
    bool bHasMax = false;   // `true` if Weight has a maximum weight defined.  Defaults to `false`.
    enum UnitOfWeight unitOfWeight = POUND;  // How the Weight is held and displayed.  Defaults to POUND.

    t_weight weight{};      // The weight.  It must always be > 0.  If `maxWeight` is set then it must also be <= `maxWeight`.
    t_weight maxWeight{};   // The maximum weight.  The maximum weight can only be set when the Weight is constructed.

public:
    // Constructors
    explicit Weight() noexcept;
    explicit Weight( t_weight newWeight );
    explicit Weight( UnitOfWeight newUnitOfWeight ) noexcept;  // A weight with a UnitOfWeight
    explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );  // A weight with a value and UnitOfWeight
    explicit Weight( t_weight newWeight, t_weight newMaxWeight );  // A weight with a value and a maximum weight
    explicit Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  // A weight with a UnitOfWeight and a maximum weight
    explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  // A weight with a value, UnitOfWeight and a maximum weight

    // Getters
    bool  isWeightKnown() const noexcept;  ///< `true` if the weight is known
    bool  hasMaxWeight() const noexcept;   ///< `true` if the maximum weight is set
    t_weight getWeight() const noexcept;      ///< Get the weight in the Weight's units
    t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;  ///< Get the weight in a specified unit
    t_weight getMaxWeight() const noexcept;   ///< Get the maximum weight
    UnitOfWeight getWeightUnit() const noexcept;  ///< Get the UnitOfWeight for this Weight

    // Setters
    void setWeight( t_weight newWeight );  // Set the weight
    void setWeight( t_weight newWeight, UnitOfWeight weightUnits );  // Set the weight as a specified unit

    // Static Methods
    static float fromKilogramToPound( t_weight kilogram ) noexcept;  // Converts kilo to pound
    static float fromPoundToKilogram( t_weight pound ) noexcept;     // Converts pound to kilo
    static float fromSlugToPound( t_weight slug ) noexcept;          // Converts slug to pound
    static float fromPoundToSlug( t_weight pound ) noexcept;         // Converts pound to slug
    static float convertWeight( t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

    // Public Methods
    bool isWeightValid( t_weight checkWeight ) const noexcept;  // Check the weight
    bool validate() const noexcept;   // Check Weight if valid
    void dump() const noexcept;       // Print the Weight class

    // Public Overrides
    bool operator==( const Weight& rhs_Weight ) const;  ///< Weights are equal when their `weight`s are equal
    bool operator<( const Weight& rhs_Weight ) const;   ///< Compare two Weights
    Weight& operator+=( t_weight rhs_addToWeight );     ///< Add to an existing weight
};


/// Output Weight as a formatted string
///
/// @param lhs_stream     The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Weight The Weight to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown Pounds` or `3.14 out of 20 Kilos`
std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;


/// Output the UnitOfMeasure as a formatted string
///
/// @param lhs_stream     The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_UnitOfWeight The weight-unit to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return Pound`, `Kilo` or `Slug` as defined by LABEL_POUND, LABEL_KILO or LABEL_SLUG
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );