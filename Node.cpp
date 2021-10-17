#include "Node.h"
#include<windows.h>

// Default constructor
Node::Node()
{
	data = NULL;
	left = right = nullptr;
}

// Constructors. Initializes data.
Node::Node(int data)
{
	this->data = data;
	left = right = nullptr;
}