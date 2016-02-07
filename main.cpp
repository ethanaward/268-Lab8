/**
*	@file : main.cpp
*	@author : Ethan Ward
*	@date : 2015.04.13
*	@brief: Serves as a place to interact with the Binary Search Tree.
*/
#ifndef MAIN_CPP
#define MAIN_CPP

#include "Node.h"
#include "BinarySearchTree.h"
#include <ctime>
#include <random>

void printMenu() {
	std::cout << "\n\nInput a selection \n" <<
		"1) Add more values to original tree \n" <<
		"2) Copy the original tree \n" <<
		"3) Delete the original tree (one time only) \n" <<
		"4) Print original tree \n" <<
		"5) Print copy \n" <<
		"6) Search original tree \n" <<
		"7) Search copy \n" <<
		"8) Exit \n" <<
		"Your choice: ";

}

void randomBinaryTree(BSTI<int>* tree, int size) {

	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(-32000,32000);
	
	for(int i = 0; i < size; i++) {
		tree->add(distribution(generator));
	}

}

int main(int argc, char** argv) {

	BSTI<int>* tree = new BinarySearchTree<int>();
	BSTI<int>* treeCopy = nullptr;
	int choice = 0;
	int value = 0;
	bool treeExists = true;
	bool copyExists = false;	
	int printChoice = 0;
	

	std::cout << "Arg count: " << argc << "\n";
	std::cout << "Node count: " << argv[1] << "\n\n";

	if(argc > 1) {
		std::cout << "Filling original tree with " << argv[1] << " values.\n\n";
		randomBinaryTree(tree, atoi(argv[1]) );		
	}

	while(choice != 8) {
		printMenu();
		std::cin >> choice;
		std::cout << "You chose " << choice << "\n";

		if(choice == 1) {
			if(treeExists) {
				std::cout << "\nInput a value to add to the original: ";
				std::cin >> value;
				std::cout << "\nAdding " << value << " to the original tree.\n";
				tree->add(value);
			}

			else {
				std::cout << "\nCannot add values. Original does not exist.\n";
			}
		}

		else if(choice == 2) {
			if(treeExists) {
				if(copyExists) {
					delete treeCopy;
				}
				std::cout << "\nCopying the orignal tree.\n";
				treeCopy = tree->clone();
				copyExists = true;
			}
			
			else {
				std::cout << "\nCannot copy. Original does not exist.\n";
			}
		}
		
		else if(choice == 3) {
			if(treeExists) {
				std::cout << "\nOriginal Tree deleted\n";
				delete tree;
				treeExists = false;
			}
	
			else {
				std::cout << "\nCannot delete. Original does not exist.\n";
			}
		}

		else if(choice == 4) {
			if(treeExists) {
				std::cout << "\nPrint order options: \n 0 - pre-order \n 1 - in-order \n 2 - post-order \n Choice:";
				std::cin >> printChoice;
				std::cout << "\nYou chose: " <<  printChoice << "\n"; 
				
				if(printChoice == 0) {
					Order order = PRE_ORDER;
					tree->printTree(order);
				}
				
				else if(printChoice == 1) {
					Order order = IN_ORDER;
					tree->printTree(order);
				}

				else if(printChoice == 2) {
					Order order = POST_ORDER;
					tree->printTree(order);
				}				
			}
			
			else {
				std::cout << "\nCannot print. Original does not exist.\n";
			}
			
		}
		
		else if(choice == 5) {
			if(copyExists) {
				std::cout << "\nPrint order options: \n 0 - pre-order \n 1 - in-order \n 2 - post-order \n Choice:";
				std::cin >> printChoice;
				std::cout << "\nYou chose: " <<  printChoice << "\n"; 
				
				if(printChoice == 0) {
					Order order = PRE_ORDER;
					treeCopy->printTree(order);
				}
				
				else if(printChoice == 1) {
					Order order = IN_ORDER;
					treeCopy->printTree(order);
				}

				else if(printChoice == 2) {
					Order order = POST_ORDER;
					treeCopy->printTree(order);
				}				
			}
			
			else {
				std::cout << "\nCannot print. Copy does not exist.\n";
			}
		}

		else if(choice == 6) {
			if(treeExists) {
				std::cout << "\nWhat value do you want to search for? \n";
				std::cin >> value;
				std::cout << "\nSearching for " << value;
			
				try{
					std::cout << tree->search(value) << " is in the tree.\n";
				}
				catch(std::exception e) {
					std::cout << e.what();
				}
			}

			else {
				std::cout << "\nCannot search for value. Original does not exist.\n";
			}
		}

		else if(choice == 7) {
			if(copyExists) {
				std::cout << "\nWhat value do you want to search for? \n";
				std::cin >> value;
				std::cout << "\nSearching for " << value;
			
				try{
					std::cout << treeCopy->search(value) << " is in the tree.\n";
				}
				catch(std::exception e) {
					std::cout << e.what();
				}
			}

			else {
				std::cout << "\nCannot search for value. Copy does not exist.\n";
			}

		}

		else if(choice == 8) {
			std::cout << "\nExiting...\n";
		}


	}
	
	
		delete treeCopy;
	
	
	
		delete tree;
	

};
#endif
