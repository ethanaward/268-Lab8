/**
*	@file : BinarySearchTree.h
*	@author : Ethan Ward
*	@date : 2015.04.13
*	@brief: Creates Binary Search Trees, clones them, adds values to them, searches for values, deletes them, and searches for values in a specific order.
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTI.h"
#include "ValueNotFoundException.h"
#include "Node.h"
#include <iostream>

template <typename T>
class BinarySearchTree:public BSTI<T> {

public:
/**
	*  @pre None
	*  @post A Binary Search Tree is created, with m_root set to nullptr.
	*  @return None
	*/
	BinarySearchTree();
/**
	*  @pre None
	*  @post A deep copy of the other BST is created.
	*  @return None
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);
/**
	*  @pre None
	*  @post Deletes the entire tree by calling deleteTree().
	*  @return None
	*/
	~BinarySearchTree();
/**
	*  @pre None
	*  @post Creates a deep copy of this.
	*  @return The deep copy of this.
	*/
	BSTI<T>* clone();
/**
	*  @pre None
	*  @post None
	*  @return True if the tree has no nodes, false otherwise.
	*/
	bool isEmpty() const;
/**
	*  @pre None
	*  @post Adds the value to the tree.
	*  @return True if the operation was successful, false otherwise.
	*/
	bool add(T value);
/**
	*  @pre None
	*  @post If the tree is empty, displays "Tree is empty". Otherwise, prints the tree in the given order.
	*  @return None
	*/
	void printTree(Order order) const;
/**
	*  @pre None
	*  @post The contents of the tree are printed to the console in order.
	*  @return None
	*/
	void sortedPrint() const;
/**
	*  @pre None
	*  @post If the value is not in the tree, throws an exception.
	*  @return The value from the private search method.
	*/
	T search(T value) const throw(ValueNotFoundException);
private:
	Node<T>* m_root;
/**
	*  @pre None
	*  @post The value is added to the correct branch of the subtree.
	*  @return True if successful, false if not.
	*/
	bool add(T value, Node<T>* subtree);
/**
	*  @pre None
	*  @post Deletes the root node, left node, and right node of the subtree passed in.
	*  @return None
	*/
	void deleteTree(Node<T>* subtree);
/**
	*  @pre None
	*  @post If the value is not in the tree, throws an exception.
	*  @return The value from the search.
	*/
	T search(T value, Node<T>* subtree) const throw(ValueNotFoundException);
/**
	*  @pre None
	*  @post Prints out the values of the tree in the given order.
	*  @return None
	*/
	void printTree(Node<T>* subtree, Order order) const;
};

#include "BinarySearchTree.hpp"

#endif

