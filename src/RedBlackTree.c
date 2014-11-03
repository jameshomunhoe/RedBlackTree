#include <stdio.h>
#include "RedBlackTree.h"
#include "Rotations.h"
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
	
	
	if(*rootPtr != NULL && (*rootPtr)->left != NULL && (*rootPtr)->right != NULL &&
		(*rootPtr)->left->color == 'r' && (*rootPtr)->right->color == 'r'){
		
		(*rootPtr)->color = 'r';
		(*rootPtr)->left->color = 'b';
		(*rootPtr)->right->color = 'b';
	}
	
	if(*rootPtr == NULL){
		*rootPtr = newNode;
		(*rootPtr)->color = 'r';
		return;
	}
		
	else if(newNode->data < (*rootPtr)->data)
		_addRedBlackTree(&((*rootPtr)->left), newNode);
	
	else if(newNode->data > (*rootPtr)->data)
		_addRedBlackTree(&((*rootPtr)->right), newNode);
	
	else
		Throw(ERROR_EQUIVALENT_NODE);
		
	checkViolationAndRotate(rootPtr);
}

void checkViolationAndRotate(Node **rootPtr){

	if((*rootPtr)->left != NULL && (*rootPtr)->left->color == 'r'){
		if((*rootPtr)->left->left != NULL || (*rootPtr)->left->right != NULL){
			if((*rootPtr)->left->left != NULL &&(*rootPtr)->left->left->color == 'r')
				rightRotate(rootPtr);
		
			else if((*rootPtr)->left->right != NULL && (*rootPtr)->left->right->color == 'r')
				leftRightRotate(rootPtr);
				
			else 
				return;
				
			(*rootPtr)->right->color = 'r';
			(*rootPtr)->color = 'b';
		}
	}
	
	else if((*rootPtr)->right != NULL && (*rootPtr)->right->color == 'r'){
		if((*rootPtr)->right->right != NULL || (*rootPtr)->right->left != NULL){
			if((*rootPtr)->right->right != NULL &&(*rootPtr)->right->right->color == 'r')
				leftRotate(rootPtr);
				
			else if((*rootPtr)->right->left != NULL &&(*rootPtr)->right->left->color == 'r')
				rightLeftRotate(rootPtr);
			
			else 
				return;
				
			(*rootPtr)->left->color = 'r';
			(*rootPtr)->color = 'b';
		}
	}
}