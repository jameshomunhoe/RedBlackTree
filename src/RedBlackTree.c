#include <stdio.h>
#include "RedBlackTree.h"
#include "Node.h"
#include "ErrorCode.h"
#include "CException.h"

/**
*	Important notes / information
*
*	exampleFunction(Node **nodePtr)
*	(**nodePtr).data //This is same
*	(*nodePtr)->data //with this
*
*	change root method
*	*nodePtr=&node5;
*/


void addRedBlackTree(Node **rootPtr, Node *newNode){
	
	_addRedBlackTree(rootPtr, newNode);
	(*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode){
	
	if(*rootPtr == NULL)
		*rootPtr = newNode;
		
	else if(newNode->data < (*rootPtr)->data)
		// _addRedBlackTree(&((*nodePtr)->right)

	(*rootPtr)->color = 'b';
}