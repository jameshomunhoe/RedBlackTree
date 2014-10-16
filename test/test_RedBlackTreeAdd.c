#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "Rotations.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
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
	
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}

/**
*	 root				root
*	  |		 add 10		 |
*	  v		 ---->		 v
*	  5(b)				 5(b)
*						   \
*							10(r)
*
*/
void test_addRedBlackTree_add_10_to_tree_with_root_5(void){
	
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	Node *root = &node5;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				root
*	  |		 add 15		 |
*	  v		 ---->		 v		
*	  10(b)				10(b)
*	  /				 	/	\
*	5(r)			 5(r)   15(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_15_to_tree_with_root_10(void){
	
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}

/**
*	 root				root
*	  |		 add 1		 |
*	  v		 ---->		 v		
*	  10(b)				5(b)
*	  /				 	/	\
*	5(r)			 1(r)   10(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_1_to_tree_with_root_10(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				root
*	  |		 add 5		 |
*	  v		 ---->		 v		
*	  10(b)				5(b)
*	  /				 	/	\
*	1(r)			 1(r)   10(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_5_to_tree_with_root_10(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node10, &node1, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				root
*	  |		 add 1		 |
*	  v		 ---->		 v		
*	  5(b)				5(b)
*	 	 \			 	/	\
*		10(r)		 1(r)   10(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_1_to_tree_with_root_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, NULL, &node10, 'b');
	Node *root = &node5;
	
	addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				root
*	  |		 add 10		 |
*	  v		 ---->		 v		
*	  1(b)				5(b)
*	 	 \			 	/	\
*		5(r)		 1(r)   10(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_10_to_tree_with_root_1(void){
	
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node1, NULL, &node5, 'b');
	setNode(&node10, NULL, NULL, 'b');
	Node *root = &node1;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				root
*	  |		 add 10		 |
*	  v		 ---->		 v		
*	  1(b)				5(b)
*	 	 \			 	/	\
*		10(r)		 1(r)   10(r)
*					
*				 
*/
void test_addRedBlackTree_3_degree_add_5_to_tree_with_root_1(void){
	
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node1, NULL, &node10, 'b');
	setNode(&node10, NULL, NULL, 'r');
	Node *root = &node1;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 root				
*	  |		 add 10	
*	  v		 ---->		error
*	  10(b)			
*					
*					
*
*/
void test_addRedBlackTree_throw_exception_with_same_value_input(void){
	
	setNode(&node10, NULL, NULL, 'b');
	// setNode(&node10, NULL, NULL, 'r');
	Node *root = &node10;
	
	int e;
	// addRedBlackTree(&root, &node10);
	
	Try
		addRedBlackTree(&root, &node10);
	Catch(e)
		TEST_ASSERT_EQUAL(ERROR_EQUIVALENT_NODE,e);
	
}