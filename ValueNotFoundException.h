/**
*	@file : ValueNotFoundException.h
*	@author : Ethan Ward
*	@date : 2015.04.10
*	@brief: Inherits from std::runtime_error to create a new type of exception that passes in a message to the std::runtime_error constructor.
*/
#ifndef VALUENOTFOUNDEXCEPTION_H
#define VALUENOTFOUNDEXCEPTION_H

#include <stdexcept>

class ValueNotFoundException: public std::runtime_error{

public:
/**
	*  @pre None
	*  @post Creates a ValueNotFoundException, and passes the message taken in to the std::runtime_error constructor
	*  @return None
	*/
	ValueNotFoundException(const char* message);
};

#endif
