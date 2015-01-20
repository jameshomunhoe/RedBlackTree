#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "Rotations.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, 
     node2, 
     node3, 
     node4, 
     node5, 
     node6, 
     node7, 
     node8, 
     node9, 
     node10, 
     node11, 
     node12, 
     node13, 
     node14, 
     node15, 
     node16, 
     node17, 
     node18, 
     node19, 
     node20, 
     node21, 
     node22, 
     node23, 
     node24, 
     node25, 
     node26, 
     node27, 
     node28, 
     node29, 
     node30, 
     node31, 
     node32, 
     node33, 
     node34, 
     node35, 
     node36, 
     node37, 
     node38, 
     node39, 
     node40, 
     node41, 
     node42, 
     node43, 
     node44, 
     node45;

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node3, 3);
	resetNode(&node4, 4);
	resetNode(&node5, 5);
	resetNode(&node6, 6);
	resetNode(&node7, 7);
	resetNode(&node8, 8);
	resetNode(&node9, 9);
	resetNode(&node10, 10);
	resetNode(&node11, 11);
	resetNode(&node12, 12);
	resetNode(&node13, 13);
	resetNode(&node14, 14);
	resetNode(&node15, 15);
	resetNode(&node16, 16);
	resetNode(&node17, 17);
	resetNode(&node18, 18);
	resetNode(&node19, 19);
	resetNode(&node20, 20);
	resetNode(&node21, 21);
	resetNode(&node22, 22);
	resetNode(&node23, 23);
	resetNode(&node24, 24);
	resetNode(&node25, 25);
	resetNode(&node26, 26);
	resetNode(&node27, 27);
	resetNode(&node28, 28);
	resetNode(&node29, 29);
	resetNode(&node30, 30);
	resetNode(&node31, 31);
	resetNode(&node32, 32);
	resetNode(&node33, 33);
	resetNode(&node34, 34);
	resetNode(&node35, 35);
	resetNode(&node36, 36);
	resetNode(&node37, 37);
	resetNode(&node38, 38);
	resetNode(&node39, 39);
	resetNode(&node40, 40);
	resetNode(&node41, 41);
	resetNode(&node42, 42);
	resetNode(&node43, 43);
	resetNode(&node44, 44);
	resetNode(&node45, 45);
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
*	 root				    root
*	  |		 add 5		 |
*	  v		 ---->		 v
*	  10(b)				 10(b)
*						    /
*						  5(r)
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
*	 root				    root
*	  |		 add 10		 |
*	  v		 ---->		 v
*	  5(b)				 5(b)
*						      \
*							    10(r)
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
*	 root				    root
*	  |		 add 15		 |
*	  v		 ---->		 v		
*	  10(b)				10(b)
*	  /				 	    /	\
*	5(r)			  5(r)   15(r)
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
*	 root				    root
*	  |		 add 1		 |
*	  v		 ---->		 v		
*	  10(b)				  5(b)
*	  /				 	    /	\
*	5(r)			  1(r)   10(r)
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
*	 root				    root
*	  |		 add 5		 |
*	  v		 ---->		 v		
*	  10(b)				  5(b)
*	  /				 	    /	\
*	1(r)			  1(r)   10(r)
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
*	 root				    root
*	  |		 add 1		 |
*	  v		 ---->		 v		
*	  5(b)				5(b)
*	 	 \			 	  /	\
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
*	 root				    root
*	  |		 add 10		 |
*	  v		 ---->		 v		
*	  1(b)				5(b)
*	 	 \			 	  /	\
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
*	 root				    root
*	  |		 add 5		 |
*	  v		 ---->		 v		
*	  1(b)				5(b)
*	 	 \			 	   /	\
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

// 23th October

/**
*		 root				    root
*		  |		 add 1		 |
*		  v		 ---->		 v		
*		 10(b)				  10(b)
*		 /	 \			 	  /	\
*	 5(r)	15(r)		 5(b)   15(b)
*	  					  /
*		 				  1(r)
*/
void test_addRedBlackTree_4_degree_add_1_to_tree_with_root_10(void){
	
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	setNode(&node1, NULL, NULL, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	
}

/**
*		_addRedBlackTree(does not change root color)
*
*		 root				    root
*		  |		 add 1		 |
*		  v		 ---->		 v		
*		 10(b)				  10(r)
*		 /	 \			 	  /	\
*	 5(r)	15(r)		 5(b)   15(b)
*	  					  /
*		 				  1(r)
*/
void test__addRedBlackTree_4_degree_add_1_to_tree_with_root_10(void){
	
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	setNode(&node1, NULL, NULL, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	
}

/**
*		 root			    	root
*		  |		 add 5		 |
*		  v		 ---->		 v		
*		 10(b)				  10(b)
*		 /	 \			 	  /	\
*	 1(r)	 15(r)  1(b)   15(b)
*	  	 				 	  \
*		 					    5(r)
*/
void test_addRedBlackTree_4_degree_add_5_to_tree_with_root_10(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node10, &node1, &node15, 'b');
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	
}

/**
*		_addRedBlackTree(does not change root color)
*
*		 root				    root
*		  |		 add 5		 |
*		  v		 ---->		 v		
*		 10(b)				  10(r)
*		 /	 \			 	  /	  \
*	 1(r)	 15(r)		 1(b)   15(b)
*	  	 				    	\
*		 					      5(r)
*/
void test__addRedBlackTree_4_degree_add_5_to_tree_with_root_10(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node10, &node1, &node15, 'b');
	Node *root = &node10;
	
	_addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	
}

/**
*		 root				    root
*		  |		 add 10		 |
*		  v		 ---->		 v		
*		 5(b)				    5(b)
*		 /	 \			 	  /	  \
*	 1(r)	 15(r)		 1(b)   15(b)
*	  	 				 		/
*		 					   10(r)
*/
void test_addRedBlackTree_4_degree_add_10_to_tree_with_root_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node10, NULL, NULL, 'b');
	Node *root = &node5;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node15);
	
}

/**
*		_addRedBlackTree(does not change root color)
*
*		 root				    root
*		  |		 add 10		 |
*		  v		 ---->		 v		
*		 5(b)				    5(b)
*		 /	 \			 	  /	  \
*	 1(r)	 15(r)		 1(b)   15(b)
*	  	 				 		/
*		 					   10(r)
*/
void test__addRedBlackTree_4_degree_add_10_to_tree_with_root_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node10, NULL, NULL, 'b');
	Node *root = &node5;
	
	_addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node15);
	
}

/**
*		 root				    root
*		  |		 add 15		 |
*		  v		 ---->		 v		
*		 5(b)				    5(b)
*		 /	 \			 	/   	\
*	 1(r)	 10(r)	1(b)   10(b)
*	  	 				 			      \
*		 					   		      15(r)
*/
void test_addRedBlackTree_4_degree_add_15_to_tree_with_root_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node15, NULL, NULL, 'b');
	Node *root = &node5;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	
}

/**
*		_addRedBlackTree(does not change root color)
*
*		 root				    root
*		  |		 add 15		 |
*		  v		 ---->		 v		
*		 5(b)				    5(b)
*		 /	 \			 	  /	    \
*	 1(r)	 10(r)		 1(b)   10(b)
*	  	 				 			        \
*		 					   		        15(r)
*/
void test__addRedBlackTree_4_degree_add_15_to_tree_with_root_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node15, NULL, NULL, 'b');
	Node *root = &node5;
	
	_addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'r', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	
}

/**
*			 root				    	root
*				|	  	add 5 		 |
*		 		v		  ----> 		 v		
*			  20(b)					  20(b)
*			 /	  \				    / 	\
*		 10(b)	 25(b)		10(r)	 25(b)
*		 /	 \			 		  /	   \
*	 1(r)	 15(r)		 	1(b)    15(b)
*	  	 				 		    \
*		 					   	    5(r)
*/
void test_addRedBlackTree_6_degree_add_5_to_tree_with_root_20(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node1, &node15, 'b');
	setNode(&node20, &node10, &node25, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	
	Node *root = &node20;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, root);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	
}

/**
*		_addRedBlackTree(does not change root color)
*
*			 root		    			root
*				|		  add 5 		 |
*		 		v		  ----> 		 v		
*			  20(b)					20(b)
*			 /	  \				   /	\
*		 10(b)	 25(b)	10(r)	 25(b)
*		 /	 \			 		/	\
*	 1(r)	 15(r)		1(b) 15(b)
*	  	 				 		  \
*		 					   	  5(r)
*/
void test__addRedBlackTree_6_degree_add_5_to_tree_with_root_20(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node1, &node15, 'b');
	setNode(&node20, &node10, &node25, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'r');
	
	Node *root = &node20;
	
	_addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, root);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node5, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	
}

/**
*		  root		  			  	      root
*				|		  add 15 		 	       |
*		 		v		  ----> 		   	      v		
*			  30(b)		  			  	    30(b)
*			 /	   \			  	        /	  \
*		  5(r)    40(r)			      5(b)	   40(b)
*		 /	\		    /	\ 		      /	\		     / 	 \
*	 1(b) 20(b) 35(b) 45(b)	  1(b)	20(r)  35(b)  45(b)
*	  	   /  \		 				          /  \
*		10(r) 25(r)			   		      10(b)  25(b)
*									                \
*									                15(r)
*/
void test_addRedBlackTree_10_degree_add_15_to_tree_with_root_30(void){
	
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node25, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node20, &node10, &node25, 'b');
	setNode(&node35, NULL, NULL, 'b');
	setNode(&node45, NULL, NULL, 'b');
	setNode(&node5, &node1, &node20, 'r');
	setNode(&node40, &node35, &node45, 'r');
	setNode(&node30, &node5, &node40, 'b');
	setNode(&node15, NULL, NULL, 'b');
	
	Node *root = &node30;
	
	addRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node30, root);
	TEST_ASSERT_EQUAL_NODE(&node5, &node40, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node20, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'r', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node35);
	TEST_ASSERT_EQUAL_NODE(&node35, &node45, 'b', &node40);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node45);
	
}

//Additional test to pass add functions
/**
*     root     add 13     root
*       |     ------->      |
*       v                   v
*     NULL                  13(b)
*/
void test_addRedBlackTree_additional_add_13(void){
	
	setNode(&node13, NULL, NULL, 'r');
	
	Node *root = NULL;
	
	addRedBlackTree(&root, &node13);
	
	TEST_ASSERT_EQUAL_PTR(&node13, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
	
}

/**
*     root     add 10     root
*       |     ------->      |
*       v                   v
*       13(b)               13(b)
*                            /
*                         10(r)
*/
void test_addRedBlackTree_additional_add_10(void){
	
	setNode(&node13, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	
	Node *root = &node13;
	
	addRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node13, root);
  TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*     root     add 2     root             root
*       |     ------->      |               |
*       v                   v               v
*       13(b)               13(b)   --->    10(b)
*       /                     /             /  \
*     10(r)               10(r)           2(r)  13(r)
*                         /   
*                       2(r)
*/
void test_addRedBlackTree_additional_add_2(void){
	
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node13, &node10, NULL, 'b');
	setNode(&node2, NULL, NULL, 'b');
	
	Node *root = &node13;
	
	addRedBlackTree(&root, &node2);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
	
}

/**
*     root     add 1     root                 root
*       |     ------->      |                  |
*       v                   v                  v
*       10(b)               10(b)   --->      10(b)
*       /  \               /     \            /  \
*     2(r)  13(r)       2(r)      13(r)     2(b)  13(b)
*                       /                   /   
*                    1(r)                 1(r)
*/
void test_addRedBlackTree_additional_add_1(void){
	
	setNode(&node2, NULL, NULL, 'r');
	setNode(&node13, NULL, NULL, 'r');
	setNode(&node10, &node2, &node13, 'b');
	setNode(&node1, NULL, NULL, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	
}

/**
*     root     add 5     root
*       |     ------->      |
*       v                   v
*       10(b)               10(b)
*       /  \               /     \
*     2(b)  13(b)       2(b)      13(b)
*     /                /   \
*   1(r)             1(r)   5(r)
*/
void test_addRedBlackTree_additional_add_5(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node2, &node1, NULL, 'b');
	setNode(&node13, NULL, NULL, 'b');
	setNode(&node10, &node2, &node13, 'b');
	setNode(&node5, NULL, NULL, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	
}

/**
*     root     add 31     root
*       |     ------->      |
*       v                   v
*       10(b)               10(b)
*       /  \               /     \
*     2(b)  13(b)       2(b)      13(b)
*     /  \             /   \          \
*   1(r)  5(r)       1(r)   5(r)       31(r)
*/
void test_addRedBlackTree_additional_add_31(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node2, &node1, &node5, 'b');
	setNode(&node13, NULL, NULL, 'b');
	setNode(&node10, &node2, &node13, 'b');
	setNode(&node31, NULL, NULL, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node31);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node31, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
	
}

/**
*     root     add 7        root
*       |     ------->        |
*       v                    v
*       10(b)                10(b)
*       /  \                /     \
*     2(b)  13(b)         2(r)      13(b)
*     /  \       \        /   \          \
*   1(r)  5(r)   31(r)  1(b)  5(b)        31(r)
*                                 \
*                                 7(r)
*/
void test_addRedBlackTree_additional_add_7(void){
	
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node2, &node1, &node5, 'b');
	setNode(&node31, NULL, NULL, 'r');
	setNode(&node13, NULL, &node31, 'b');
	setNode(&node10, &node2, &node13, 'b');
	setNode(&node7, NULL, NULL, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node7);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, &node31, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
	
}

/**
*     root     add 19        root                      root
*       |     ------->        |     ----->               |
*       v                     v                          v
*       10(b)                10(b)                      10(b)
*       /  \                /      \                   /     \
*     2(r)  13(b)         2(r)      13(b)            2(r)     19(b)
*     /  \       \        /   \         \           /   \     /     \
*   1(b)  5(b)   31(r)  1(b)  5(b)      31(r)    1(b)   5(b) 13(r)    31(r)
*             \                   \      /                \
*              7(r)                7(r) 19(r)             7(r)
*/
void test_addRedBlackTree_additional_add_19(void){
	
	setNode(&node7, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, NULL, &node7, 'b');
	setNode(&node31, NULL, NULL, 'r');
	setNode(&node2, &node1, &node5, 'r');
	setNode(&node13, NULL, &node31, 'b');
	setNode(&node10, &node2, &node13, 'b');
	setNode(&node19, NULL, NULL, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node19);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node19, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(&node13, &node31, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, &node7, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node7);
	
}

/**
*     root     add 19           root
*       |     ------->           |
*       v                        v
*       10(b)                   10(b)
*       /    \                /      \ 
*    2(r)     19(b)         2(r)      19(b)
*    /  \      /  \        /   \      /   \
*  1(b) 5(b) 13(r) 31(r)  1(b)  7(b) 13(r)  31(r) 
*          \                    /  \
*           7(r)             5(r)   8(r)
*/
void test_addRedBlackTree_additional_add_8(void){
	
	setNode(&node7, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, NULL, &node7, 'b');
	setNode(&node13, NULL, NULL, 'r');
	setNode(&node31, NULL, NULL, 'r');
	setNode(&node2, &node1, &node5, 'r');
	setNode(&node19, &node13, &node31, 'b');
	setNode(&node10, &node2, &node19, 'b');
	
	Node *root = &node10;
	
	addRedBlackTree(&root, &node8);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
  TEST_ASSERT_EQUAL_NODE(&node2, &node19, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node1, &node7, 'r', &node2);
  TEST_ASSERT_EQUAL_NODE(&node13, &node31, 'b', &node19);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(&node5, &node8, 'b', &node7);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node13);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node31);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node8);
  
  //to compare height
  int leftHeight;
  int rightHeight;
  int doubleBlack;
  
  leftHeight = checkLeftHeight(&root);
  rightHeight = checkRightHeight(&root);
  doubleBlack = findDoubleBlackNode(&root);
  
  TEST_ASSERT_EQUAL(2, leftHeight);
  TEST_ASSERT_EQUAL(2, rightHeight);
  TEST_ASSERT_EQUAL(0, doubleBlack);
	
}

/**
* To check the height should balance for both sides after adding
* No doubleBlack Node should exist
* Removing smaller Node should able to remove all
*/
void test_addRedBlackTree_and_remove_all_with_30_nodes(){

  Node *node[30];
  Node *root = NULL;
  
  //Add 20 nodes in random sequece
  //Value of nodes are 1-30
  
  addRedBlackTree(&root, &node10);
  addRedBlackTree(&root, &node5);
  addRedBlackTree(&root, &node23);
  addRedBlackTree(&root, &node2);
  addRedBlackTree(&root, &node30);
  addRedBlackTree(&root, &node15);
  addRedBlackTree(&root, &node3);
  addRedBlackTree(&root, &node12);
  addRedBlackTree(&root, &node29);
  addRedBlackTree(&root, &node25);
  addRedBlackTree(&root, &node8);
  addRedBlackTree(&root, &node11);
  addRedBlackTree(&root, &node28);
  addRedBlackTree(&root, &node17);
  addRedBlackTree(&root, &node1);
  addRedBlackTree(&root, &node19);
  addRedBlackTree(&root, &node27);
  addRedBlackTree(&root, &node13);
  addRedBlackTree(&root, &node9);
  addRedBlackTree(&root, &node14);
  addRedBlackTree(&root, &node6);
  addRedBlackTree(&root, &node26);
  addRedBlackTree(&root, &node24);
  addRedBlackTree(&root, &node20);
  addRedBlackTree(&root, &node4);
  addRedBlackTree(&root, &node18);
  addRedBlackTree(&root, &node7);
  addRedBlackTree(&root, &node22);
  addRedBlackTree(&root, &node16);
  addRedBlackTree(&root, &node21);

  //Check and compare the height, left and right should same
  //Check if there is blackNode
  int leftHeight = checkLeftHeight(&root);
  int rightHeight = checkRightHeight(&root);
  int doubleBlack = findDoubleBlackNode(&root);
  int i;
  
  TEST_ASSERT_EQUAL(leftHeight, rightHeight);
  TEST_ASSERT_EQUAL(0, doubleBlack);

  //Remove smallest value 1 by 1
  //Expect the result sort in ascending order in node[]
  for( i = 0 ; i < 30 ; i++){
    node[i] = removeNextLargerSuccessor(&root);
    // printf("Node %d value: %d\n", i, node[i]->data);
    TEST_ASSERT_EQUAL( i+1, node[i]->data);
  }
  
}

void test_addRedBlackTree_dr_poh_test(){

  Node *node[26];
  Node *root = NULL;
  
  addRedBlackTree(&root, &node13);
  addRedBlackTree(&root, &node10);
  addRedBlackTree(&root, &node2);
  addRedBlackTree(&root, &node1);
  addRedBlackTree(&root, &node5);
  addRedBlackTree(&root, &node31);
  addRedBlackTree(&root, &node7);
  addRedBlackTree(&root, &node19);
  addRedBlackTree(&root, &node8);
  addRedBlackTree(&root, &node24);
  addRedBlackTree(&root, &node12);
  addRedBlackTree(&root, &node26);
  addRedBlackTree(&root, &node15);
  addRedBlackTree(&root, &node21);
  addRedBlackTree(&root, &node30);
  addRedBlackTree(&root, &node20);
  addRedBlackTree(&root, &node22);
  addRedBlackTree(&root, &node32);
  addRedBlackTree(&root, &node23);
  addRedBlackTree(&root, &node29);
  addRedBlackTree(&root, &node18);
  addRedBlackTree(&root, &node25);
  addRedBlackTree(&root, &node11);
  addRedBlackTree(&root, &node28);
  addRedBlackTree(&root, &node27);
  addRedBlackTree(&root, &node3);

  //Check and compare the height, left and right should same
  //Check if there is blackNode
  int leftHeight = checkLeftHeight(&root);
  int rightHeight = checkRightHeight(&root);
  int doubleBlack = findDoubleBlackNode(&root);
  int i;
  
  TEST_ASSERT_EQUAL(leftHeight, rightHeight);
  TEST_ASSERT_EQUAL(0, doubleBlack);

  //Remove smallest value 1 by 1
  //Expect the result sort in ascending order in node[]
  for( i = 0 ; i < 26 ; i++){
    node[i] = removeNextLargerSuccessor(&root);
    // printf("Node %d value: %d\n", i, node[i]->data);
  }
    TEST_ASSERT_EQUAL( 1, node[0]->data);
    TEST_ASSERT_EQUAL( 2, node[1]->data);
    TEST_ASSERT_EQUAL( 3, node[2]->data);
    TEST_ASSERT_EQUAL( 5, node[3]->data);
    TEST_ASSERT_EQUAL( 7, node[4]->data);
    TEST_ASSERT_EQUAL( 8, node[5]->data);
    TEST_ASSERT_EQUAL( 10, node[6]->data);
    TEST_ASSERT_EQUAL( 11, node[7]->data);
    TEST_ASSERT_EQUAL( 12, node[8]->data);
    TEST_ASSERT_EQUAL( 13, node[9]->data);
    TEST_ASSERT_EQUAL( 15, node[10]->data);
    TEST_ASSERT_EQUAL( 18, node[11]->data);
    TEST_ASSERT_EQUAL( 19, node[12]->data);
    TEST_ASSERT_EQUAL( 20, node[13]->data);
    TEST_ASSERT_EQUAL( 21, node[14]->data);
    TEST_ASSERT_EQUAL( 22, node[15]->data);
    TEST_ASSERT_EQUAL( 23, node[16]->data);
    TEST_ASSERT_EQUAL( 24, node[17]->data);
    TEST_ASSERT_EQUAL( 25, node[18]->data);
    TEST_ASSERT_EQUAL( 26, node[19]->data);
    TEST_ASSERT_EQUAL( 27, node[20]->data);
    TEST_ASSERT_EQUAL( 28, node[21]->data);
    TEST_ASSERT_EQUAL( 29, node[22]->data);
    TEST_ASSERT_EQUAL( 30, node[23]->data);
    TEST_ASSERT_EQUAL( 31, node[24]->data);
    TEST_ASSERT_EQUAL( 32, node[25]->data);
  
}



/**
*  This will fail code, build test by adding this
*
*  addRedBlackTree(&root, &node1);
*  addRedBlackTree(&root, &node30);
*  addRedBlackTree(&root, &node2);
*  addRedBlackTree(&root, &node29);
*  addRedBlackTree(&root, &node3);
*  addRedBlackTree(&root, &node28);
*  addRedBlackTree(&root, &node4);
*  addRedBlackTree(&root, &node27);
*  addRedBlackTree(&root, &node5);
*  addRedBlackTree(&root, &node26);
*  addRedBlackTree(&root, &node6);
*  addRedBlackTree(&root, &node25);
*  addRedBlackTree(&root, &node7);
*  addRedBlackTree(&root, &node24);
**/

/**
*   root              root
*     v     ----->      v
*   NULL                1(b)
**/
void test_addRedBlackTree_node_1(){
  
  Node *root = NULL;
  
  addRedBlackTree(&root, &node1);
  
 TEST_ASSERT_EQUAL_PTR(&node1, root);
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
}

/**
*   root              root
*     v     ----->      v
*   1(b)                1(b)
*                         \
*                          30(r)
**/
void test_addRedBlackTree_node_30(){
  
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1;
  
  addRedBlackTree(&root, &node30);
  
 TEST_ASSERT_EQUAL_PTR(&node1, root);
 TEST_ASSERT_EQUAL_NODE(NULL, &node30, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(NULL, &node30, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);  
}

/**
*   root              root
*     v     ----->      v
*   1(b)                2(b)
*       \               /  \
*        30(r)        1(r)  30(r)
**/
void test_addRedBlackTree_node_2(){
  
  setNode(&node30, NULL, NULL, 'r');
  setNode(&node1, NULL, &node30, 'b');
  Node *root = &node1;
  
  addRedBlackTree(&root, &node2);
  
 TEST_ASSERT_EQUAL_PTR(&node2, root);
 TEST_ASSERT_EQUAL_NODE(&node1, &node30, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node30, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);  
}

/**
*   root              root
*     v     ----->      v
*   2(b)                2(b)
*   /    \               /  \
*  1(r)   30(r)        1(b)  30(b)
*                            /
*                          29(r)
**/
void test_addRedBlackTree_node_29(){
  
  setNode(&node30, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node2, &node1, &node30, 'b');
  Node *root = &node2;
  
  addRedBlackTree(&root, &node29);
  
 TEST_ASSERT_EQUAL_PTR(&node2, root);
 TEST_ASSERT_EQUAL_NODE(&node1, &node30, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node30, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(&node29, NULL, 'b', &node30);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node29);  
}

/**
*   root              root
*     v     ----->      v
*   2(b)                2(b)
*   /    \               /  \
*  1(b)   30(b)        1(b)  29(b)
*         /                   /   \
*      29(r)                 3(r)  30(r)
**/
void test_addRedBlackTree_node_3(){
  
  setNode(&node29, NULL, NULL, 'r');
  setNode(&node30, &node29, NULL, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node30, 'b');
  Node *root = &node2;
  
  addRedBlackTree(&root, &node3);
  
 TEST_ASSERT_EQUAL_PTR(&node2, root);
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'b', &node29);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);  
}

/**
*   root              root
*     v     ----->      v
*   2(b)                2(b)
*   /    \               /  \
*  1(b)   29(b)        1(b)  29(r)
*         /  \                 /   \
*      3(r)   30(r)           3(b)  30(b)
*                                \  
*                                28(r)
**/
void test_addRedBlackTree_node_28(){
  
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node30, NULL, NULL, 'r');
  setNode(&node29, &node3, &node30, 'b');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node29, 'b');
  Node *root = &node2;
  
  addRedBlackTree(&root, &node28);
  
 TEST_ASSERT_EQUAL_PTR(&node2, root);
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(&node3, &node30, 'r', &node29);  
 TEST_ASSERT_EQUAL_NODE(NULL, &node28, 'b', &node3);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node28);  
}

/**
*   root              root
*     v     ----->      v
*    2(b)                2(b)
*   /    \               /  \
*  1(b)   29(r)        1(b)  29(r)
*         /  \                 /   \
*      3(b)   30(b)          4(b)   30(b)
*         \                   /   \  
*          28(r)           3(r)    28(r)
**/
void test_addRedBlackTree_node_4(){
  
  setNode(&node28, NULL, NULL, 'r');
  setNode(&node3, NULL, &node28, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node29, &node3, &node30, 'r');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node29, 'b');
  Node *root = &node2;
  
  addRedBlackTree(&root, &node4);
  
 TEST_ASSERT_EQUAL_PTR(&node2, root);
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node29, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(&node4, &node30, 'r', &node29);  
 TEST_ASSERT_EQUAL_NODE(&node3, &node28, 'b', &node4);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node28);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);  
}

/**
*   root                root
*     v     ----->        v
*    2(b)                4(b)
*   /    \               /    \
*  1(b)   29(r)        2(r)     29(r)
*         /  \         /  \     /   \
*      4(b)   30(b)  1(b) 3(b) 28(b)  30(b)   
*      /   \                    /
*    3(r)   28(r)             27(r)
**/
void test_addRedBlackTree_node_27(){
  
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node28, NULL, NULL, 'r');
  setNode(&node4, &node3, &node28, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node29, &node4, &node30, 'r');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node2, &node1, &node29, 'b');
  Node *root = &node2;
  
  addRedBlackTree(&root, &node27);
  
 TEST_ASSERT_EQUAL_PTR(&node4, root);
 TEST_ASSERT_EQUAL_NODE(&node2, &node29, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node2, &node29, 'b', &node4);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'r', &node2);  
 TEST_ASSERT_EQUAL_NODE(&node28, &node30, 'r', &node29);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);  
 TEST_ASSERT_EQUAL_NODE(&node27, NULL, 'b', &node28);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node27);  
}


//Dr poh, if possible help me check this test, the result should be first, or second?
/**                         
*                           This is answer when i do
*                           on a paper
*     root                      root                        root (this is my program answer)
*       v     ----->              v                           v
*      4(b)                     4(b)                         4(b)
*      /    \                  /     \                      /     \
*    2(r)   29(r)            2(r)     29(r)         or    2(b)      29(b)
*   /  \      /  \          /   \     /   \               /   \     /   \
*1(b) 3(b) 28(b) 30(b)   1(b)  3(b) 27(b)   30(b)       1(b)  3(b) 27(b)  30(b)
*         /                         /   \                         /   \
*      27(r)                       5(r)  28(r)                   5(r) 28(r)
**/
void test_addRedBlackTree_node_5(){
  
  setNode(&node27, NULL, NULL, 'r');
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node28, &node27, NULL, 'b');
  setNode(&node30, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node29, &node28, &node30, 'r');
  setNode(&node4, &node2, &node29, 'b');
  Node *root = &node4;
  
  addRedBlackTree(&root, &node5);
  
 TEST_ASSERT_EQUAL_PTR(&node4, root);
 TEST_ASSERT_EQUAL_NODE(&node2, &node29, 'b', root);  
 TEST_ASSERT_EQUAL_NODE(&node2, &node29, 'b', &node4);  
 TEST_ASSERT_EQUAL_NODE(&node1, &node3, 'b', &node2);  
 TEST_ASSERT_EQUAL_NODE(&node27, &node30, 'b', &node29);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);  
 TEST_ASSERT_EQUAL_NODE(&node5, &node28, 'b', &node27);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);  
 TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node28);  
}





























/*
//fails when add until 24 and delete first 7 nodes or add until 11 and removeNexLargerSuccessor 7 times
void xtest_addRedBlackTree_add_inner_left_test(){

  Node *node[30];
  Node *root = NULL;
  
  addRedBlackTree(&root, &node1);
  addRedBlackTree(&root, &node30);
  addRedBlackTree(&root, &node2);
  addRedBlackTree(&root, &node29);
  addRedBlackTree(&root, &node3);
  addRedBlackTree(&root, &node28);
  addRedBlackTree(&root, &node4);
  addRedBlackTree(&root, &node27);
  addRedBlackTree(&root, &node5);
  addRedBlackTree(&root, &node26);
  addRedBlackTree(&root, &node6);
  addRedBlackTree(&root, &node25);
  addRedBlackTree(&root, &node7);
  addRedBlackTree(&root, &node24);
  // addRedBlackTree(&root, &node8);
  // addRedBlackTree(&root, &node23);
  // addRedBlackTree(&root, &node9);
  // addRedBlackTree(&root, &node22);
  // addRedBlackTree(&root, &node10);
  // addRedBlackTree(&root, &node21);
  // addRedBlackTree(&root, &node11);
  // addRedBlackTree(&root, &node20);
  // addRedBlackTree(&root, &node12);
  // addRedBlackTree(&root, &node19);
  // addRedBlackTree(&root, &node13);
  // addRedBlackTree(&root, &node18);
  // addRedBlackTree(&root, &node14);
  // addRedBlackTree(&root, &node17);
  // addRedBlackTree(&root, &node15);
  // addRedBlackTree(&root, &node16);

  // Check and compare the height, left and right should same
  // Check if there is blackNode
  int leftHeight = checkLeftHeight(&root);
  int rightHeight = checkRightHeight(&root);
  int doubleBlack = findDoubleBlackNode(&root);
  int i;
  
  TEST_ASSERT_EQUAL(leftHeight, rightHeight);
  TEST_ASSERT_EQUAL(0, doubleBlack);

  delRedBlackTree(&root,&node1);
  delRedBlackTree(&root,&node2);
  delRedBlackTree(&root,&node3);
  delRedBlackTree(&root,&node4);
  delRedBlackTree(&root,&node5);
  delRedBlackTree(&root,&node6);
  delRedBlackTree(&root,&node7);
  
  
  
  
  // Remove smallest value 1 by 1
  // Expect the result sort in ascending order in node[]
  // for( i = 0 ; i < 7 ; i++){
    // node[i] = removeNextLargerSuccessor(&root);
    // printf("Node %d value: %d\n", i, node[i]->data);
  // }
    // TEST_ASSERT_EQUAL( 1, node[0]->data);
    // TEST_ASSERT_EQUAL( 2, node[1]->data);
    // TEST_ASSERT_EQUAL( 3, node[2]->data);
    // TEST_ASSERT_EQUAL( 4, node[3]->data);
    // TEST_ASSERT_EQUAL( 5, node[4]->data);
    // TEST_ASSERT_EQUAL( 6, node[5]->data);
    // TEST_ASSERT_EQUAL( 7, node[6]->data);
    // TEST_ASSERT_EQUAL( 8, node[7]->data);
    // TEST_ASSERT_EQUAL( 9, node[8]->data);
    // TEST_ASSERT_EQUAL( 10, node[9]->data);
    // TEST_ASSERT_EQUAL( 11, node[10]->data);
    // TEST_ASSERT_EQUAL( 12, node[11]->data);
    // TEST_ASSERT_EQUAL( 13, node[12]->data);
    // TEST_ASSERT_EQUAL( 14, node[13]->data);
    // TEST_ASSERT_EQUAL( 15, node[14]->data);
    // TEST_ASSERT_EQUAL( 16, node[15]->data);
    // TEST_ASSERT_EQUAL( 17, node[16]->data);
    // TEST_ASSERT_EQUAL( 18, node[17]->data);
    // TEST_ASSERT_EQUAL( 19, node[18]->data);
    // TEST_ASSERT_EQUAL( 20, node[19]->data);
    // TEST_ASSERT_EQUAL( 21, node[20]->data);
    // TEST_ASSERT_EQUAL( 22, node[21]->data);
    // TEST_ASSERT_EQUAL( 23, node[22]->data);
    // TEST_ASSERT_EQUAL( 24, node[23]->data);
    // TEST_ASSERT_EQUAL( 25, node[24]->data);
    // TEST_ASSERT_EQUAL( 26, node[25]->data);
    // TEST_ASSERT_EQUAL( 27, node[26]->data);
    // TEST_ASSERT_EQUAL( 28, node[27]->data);
    // TEST_ASSERT_EQUAL( 29, node[28]->data);
    // TEST_ASSERT_EQUAL( 30, node[29]->data);
  
}
*/