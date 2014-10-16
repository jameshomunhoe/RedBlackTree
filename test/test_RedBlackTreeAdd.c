#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertion.h"
#include "CException.h"

Node node1, node5, node10, node15, node20, node25;


void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node10, 10);
	resetNode(&node15, 15);
	resetNode(&node20, 20);
	resetNode(&node25, 25);
}
void tearDown(void){}


/**
*	 root				root
*	  |		add 10		 |
*	  v		 ---->		 v
*	 NULL				 10
*/
void test_addRedBlackTree_add_10_to_empty_tree(void){
	
	setNode(&node10, NULL, NULL, 'r');
	Node *root = NULL;
	
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	
}

/**
*	 root				root
*	  |		 add 5		 |
*	  v		 ---->		 v
*	  10(b)				 10(b)
*						 /
*						5(r)
*
*/
void test_addRedBlackTree_add_5_to_tree_with_root_10(void){
	
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	Node *root = &node10;
	
	// addRedBlackTree(&root, &node5);
	
	// TEST_ASSERT_EQUAL_PTR(&node10, root);
	// TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
	// TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}
