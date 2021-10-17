#include<iostream>
#include<fstream>
#include "Tree.h"
using namespace std;

/////////////////////////////////////
// PRIVATE METHODS
/////////////////////////////////////

// Will read data into tree
// Data read will be from c:\temp\input.txt
void Tree::readData()
{
	// Opens file
	ifstream file("c:\\temp\\input.txt");
	int input;
	file >> input;
	// Loops through file, putting numbers into tree
	while (input != -1)
	{
		add(input);
		file >> input;
	}
	// Closes file
	file.close();
}

// Recursively prints tree using pre-order traversal
void Tree::printNLR(Node* root)
{
	// Node first
	cout << root->data << " ";
	// Goes left second
	if (root->left != nullptr)
	{
		printNLR(root->left);
	}
	// Goes right third
	if (root->right != nullptr)
	{
		printNLR(root->right);
	}
}

// Recursively prints tree using in-order traversal
void Tree::printLNR(Node* root)
{
	// Goes left first
	if (root->left != nullptr)
	{
		printLNR(root->left);
	}
	// Node second
	cout << root->data << " ";
	// Goes right third
	if (root->right != nullptr)
	{
		printLNR(root->right);
	}
}

// Recursively prints tree using post-order traversal
void Tree::printLRN(Node* root)
{
	// Goes left first
	if (root->left != nullptr)
	{
		printLRN(root->left);
	}
	// Goes right second
	if (root->right != nullptr)
	{
		printLRN(root->right);
	}
	// Node third
	cout << root->data << " ";
}





/////////////////////////////////////
// PUBLIC METHODS
/////////////////////////////////////

// Constructor
// Reads data to start
Tree::Tree()
{
	root = nullptr;
	readData();
}

// Adds a node to the tree
void Tree::add(int data)
{
	// Creates the new node that will be
	// added to the tree.
	Node* temp = new Node(data);

	// If there is no root, it will set that
	if (root == nullptr)
	{
		root = temp;
	}
	// Runs if there is already a root
	else
	{
		// Creates a node that will be used to tell
		// where we currently are in the tree.
		Node* current = root;

		// Will loop and try to find correct position for new node
		while (true)
		{
			// Runs if the new node is less than the current one
			if (data < current->data)
			{
				// If the left node is empty, it will set it and end the function
				if (current->left == nullptr)
				{
					current->left = temp;
					break;
				}
				// Otherwise, it will move the node, and continue the loop
				current = current->left;
			}
			
			// Runs if the new node is greater than the current one
			else if (data >= current->data)
			{
				// If the right node is empty, it will set it and end the function
				if (current->right == nullptr)
				{
					current->right = temp;
					break;
				}
				// Otherwise, it will move the node, and continue the loop
				current = current->right;
			}
		}
	}
}

// Deletes a node from the tree
// I think I've found the algorithm
//----------------------------------
// If the NTD (Node-to-delete) has no children:
//		Delete it
// If the NTD has one child:
//		Replace it with it's child
// If the NTD has two children:
//		Replace it with the largest node from the left subtree
void Tree::del(int data)
{
	Node* current = root;
	while (true)
	{
		// If the data is less than the current nodes data
		if (data < current->data)
		{
			// If the data matches the current data,
			// we've found the right node, and must delete it.
			if (data == current->left->data)
			{

			}
			// Runs if there are still children nodes to go to,
			// and the correct node hasn't been found yet.
			else if (current->left != nullptr)
			{
				current = current->left;
			}
			// If this isn't the right node, and there is nowhere
			// left to go, we break the loop and the function will end.
			// This means no matching node was found and nothing was deleted.
			else
			{
				break;
			}
		}
		// If the data is more than, or equal to, the current nodes data
		else if (data >= current->data)
		{
			// If the data matches the current data,
			// we've found the right node, and must delete it.
			if (data == current->right->data)
			{

			}
			// Runs if there are still children nodes to go to,
			// and the correct node hasn't been found yet.
			else if (current->right == nullptr)
			{
				current = current->right;
			}
			// If this isn't the right node, and there is nowhere
			// left to go, we break the loop and the function will end.
			// This means no matching node was found and nothing was deleted.
			else
			{
				break;
			}
		}
	}
}

// Calls recursive method to print using pre-order traversal
void Tree::printNLR()
{
	cout << "NLR: ";
	printNLR(root);
	cout << endl;
}

// Calls recursive method to print using in-order traversal
void Tree::printLNR()
{
	cout << "LNR: ";
	printLNR(root);
	cout << endl;
}

// Calls recursive method to print using post-order traversal
void Tree::printLRN()
{
	cout << "LRN: ";
	printLRN(root);
	cout << endl;
}

void Tree::displayTree()
{
	printNLR();
	printLNR();
	printLRN();
}
