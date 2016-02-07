/**
*	@file : BSTI.h
*	@author : Ethan Ward
*	@date : 2015.04.13
*	@brief: Is an interface for Binary Search Trees.
*/
#ifndef BSTI_H
#define BSTI_H

#include "ValueNotFoundException.h"

enum Order { PRE_ORDER, IN_ORDER, POST_ORDER };

template <typename T>
class BSTI {

public:
/**
	*  @pre A BSTI exists
	*  @post Deletes the whole tree.
	*  @return None
	*/
	virtual ~BSTI(){};
/**
	*  @pre this is in a valid state.
	*  @post Creates a deep copy of this
	*  @return A pointer to a deep copy of this.
	*/
	virtual BSTI<T>* clone() = 0;
/**
	*  @pre None
	*  @post None
	*  @return True if there are no nodes in the tree, false if else.
	*/
	virtual bool isEmpty() const = 0;
/**
	*  @pre Value is a valid T
	*  @post A new Node<T> is created and inserted into the tree
	*  @return False if the value cannot be added
	*/
	virtual bool add(T value) = 0;
/**
	*  @pre T is comparable using ==
	*  @post None
	*  @return The value of the tree if found, throws an exception otherwise.
	*/
	virtual T search (T value) const throw(ValueNotFoundException) = 0;
/**
	*  @pre None
	*  @post The values in the tree are printed in the specified order.
	*  @return None
	*/
	virtual void printTree(Order order) const = 0;
/**
	*  @pre None
	*  @post The values in the tree are printed in order.
	*  @return None
	*/
	virtual void sortedPrint() const = 0;
};

#endif
