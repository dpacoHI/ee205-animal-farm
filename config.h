///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <string>
#include <ostream>


#define PROGRAM_NAME "animalfarm3"
#define DEBUG // For Debugging
#define MAX_NAME1 "12981249281491059875210915290852109518"
#define MAX_NAME2 "DIFFERENT 98123409125701248u01293812490815290"
#define ILLEGAL_NAME "1209812410325671356987153987159812571285701257251"

#define PRINT_HEADING_FOR_DUMP std::cout << std::setw(80) << std::setfill('=') << "" << std::endl

#define FORMAT_LINE_FOR_DUMP( className, member ) std::cout << std::setfill( ' ' ) << std::left << std::boolalpha << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)