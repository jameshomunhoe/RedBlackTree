#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode);
void _addRedBlackTree(Node **rootPtr, Node *newNode);
Node *delRedBlackTree(Node **rootPtr, Node *newNode);
Node *_delRedBlackTree(Node **rootPtr, Node *newNode);

//To check violation and rotate if needed
void checkViolationAndRotate(Node **rootPtr);


#endif // RedBlackTree_H
