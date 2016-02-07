/**
*	@file : BinarySearchTree.hpp
*	@author : Ethan Ward
*	@date : 2015.04.13
*	@brief: Implements the methods described in BinarySearchTree.h
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {

	this->m_root = nullptr;

	if(other.m_root != nullptr) {
		this->m_root = new Node<T>(*(other.m_root));
	}

}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

	deleteTree(m_root);

}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone() {

	BSTI<T>* temp = new BinarySearchTree(*(this));
	return(temp);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
	if(m_root == nullptr) {
		return true;
	}
	
	else {
		return false;
	}
}

template <typename T>
bool BinarySearchTree<T>::add(T value) {

	if(isEmpty()) {
		Node<T>* temp = new Node<T>();
		temp->setValue(value);
		m_root = temp;
		return true;
	}

	else if(value < m_root->getValue()) {

		if(m_root->getLeft() == nullptr) {
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			m_root->setLeft(temp);
			return true;
		}	
		else {
			return( add(value, m_root->getLeft()) );
		}
	}

	else if(value > m_root->getValue()) {

		if(m_root->getRight() == nullptr) {
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			m_root->setRight(temp);
			return true;
		}	
		else {
			return( add(value, m_root->getRight()) );
		}
	}
	
	else {
		return false;
	}

}

template <typename T>
void BinarySearchTree<T>::printTree(Order order) const {

	if(this->isEmpty()) {
		std::cout << "Tree Empty";
	}

	else if(order == PRE_ORDER) {
		std::cout << m_root->getValue() << " ";
		printTree(m_root->getLeft(), order);
		printTree(m_root->getRight(), order);
	}

	else if(order == IN_ORDER) {
		printTree(m_root->getLeft(), order);
		std::cout << m_root->getValue() << " ";
		printTree(m_root->getRight(), order);
	}

	else if(order == POST_ORDER) {
		printTree(m_root->getLeft(), order);
		printTree(m_root->getRight(), order);
		std::cout << m_root->getValue() << " ";
	}
}

template <typename T>
void BinarySearchTree<T>::sortedPrint() const {

	Order order = IN_ORDER;
	printTree(order);

}

template <typename T>
T BinarySearchTree<T>::search(T value) const throw(ValueNotFoundException) {
	
	return( search(value, m_root));

}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree) {

	if(value < subtree->getValue()) {

		if(subtree->getLeft() == nullptr) {
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			subtree->setLeft(temp);
			return true;
		}	
		else {
			return( add(value, subtree->getLeft()) );
		}
	}

	else if(value > subtree->getValue()) {

		if(subtree->getRight() == nullptr) {
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			subtree->setRight(temp);
			return true;
		}	
		else {
			return( add(value, subtree->getRight()) );
		}
	}
	
	else {
		return false;
	}
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree) {

	if(subtree == nullptr) {
		return;
	}
	
	else {
		deleteTree(subtree->getLeft());
		deleteTree(subtree->getRight());
		delete subtree;
	}

}

template <typename T>
T BinarySearchTree<T>::search(T value, Node<T>* subtree) const throw(ValueNotFoundException) {

	if(subtree == nullptr) {
		throw ValueNotFoundException("The value is not in the tree");
	}

	if(value < subtree->getValue()) {
		return( search(value, subtree->getLeft()) );
	}

	else if(value > subtree->getValue()) {
		return( search(value,subtree->getRight()) );
	}

	else {
		return(value);
	}

}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const {
	
	if(subtree == nullptr) {
		return;
	}	

	else if(order == PRE_ORDER) {
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
	}

	else if(order == IN_ORDER) {
		printTree(subtree->getLeft(), order);
		std::cout << subtree->getValue() << " ";
		printTree(subtree->getRight(), order);
	}

	else if(order == POST_ORDER) {
		printTree(subtree->getLeft(), order);
		printTree(subtree->getRight(), order);
		std::cout << subtree->getValue() << " ";
	}
}

