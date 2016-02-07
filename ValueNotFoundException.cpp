/**
*	@file : ValueNotFoundException.cpp
*	@author : Ethan Ward
*	@date : 2015.04.10
*	@brief: Implements the functionality of ValueNotFoundException.h.
*/
#include "ValueNotFoundException.h"

ValueNotFoundException::ValueNotFoundException(const char* message):std::runtime_error(message) {

}
