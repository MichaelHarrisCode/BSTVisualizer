#include "Node.h"
#pragma once

class Tree
{
private:
	// Attributes
	Node* root;

	// Methods
	void readData();
	Node* add(Node* root, int data);
	void printNLR(Node* root);
public:
	Tree();
	void add(int data);
	void printNLR();
};