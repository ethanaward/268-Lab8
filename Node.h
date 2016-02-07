/**
*	@file : Node.h
*	@author : Ethan Ward
*	@date : 2015.04.13
*	@brief: Creates Nodes, copies nodes, and has methods for getting and setting the values of nodes.
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

public:
/**
	*  @pre None
	*  @post Creates a new Node, with m_right set to nullptr and m_left set to nullptr
	*  @return None
	*/
	Node();
/**
	*  @pre None
	*  @post Creates a deep copy of the other node.
	*  @return None
	*/
	Node(const Node<T>& other);
/**
	*  @pre None
	*  @post None
	*  @return The value stored in the node
	*/
	T getValue();
/**
	*  @pre None
	*  @post None
	*  @return A pointer to the left subtree.
	*/
	Node<T>* getLeft();
/**
	*  @pre None
	*  @post None
	*  @return A pointer to the right subtree.
	*/
	Node<T>* getRight();
/**
	*  @pre None
	*  @post Sets the value of the node to the taken in value.
	*  @return None
	*/
	void setValue(T value);
/**
	*  @pre None
	*  @post Sets m_left to the taken in Node pointer.
	*  @return None
	*/
	void setLeft(Node<T>* left);
/**
	*  @pre None
	*  @post Sets m_left to the taken in Node pointer.
	*  @return None
	*/
	void setRight(Node<T>* right);
private:
	Node<T>* m_left;
	Node<T>* m_right;
	T m_value;
};

#include "Node.hpp"

#endif
