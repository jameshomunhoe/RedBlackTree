#include <stdio.h>
#include "unity.h"
#include "Node.h"
#include "Rotations.h"
#include "InitNode.h"
#include "RedBlackTree.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node5, node10, node15, node20, node25, node30, node35, node40, node45;


void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node2, 2);
	resetNode(&node5, 5);
	resetNode(&node10, 10);
	resetNode(&node15, 15);
	resetNode(&node20, 20);
	resetNode(&node25, 25);
	resetNode(&node30, 30);
	resetNode(&node35, 35);
	resetNode(&node40, 40);
	resetNode(&node45, 45);
}
void tearDown(void){}


/**
*	 root				root
*	  |		del 10		 |
*	  v		 ---->		 v
*	 10(b)				 NULL
*/
void test_delRedBlackTree_delete_10_from_2_degree_tree(void){
	
	setNode(&node10, NULL, NULL, 'r');
	Node *root = &node10;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node10, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', retNode);
	
}

/**
*	 root				root
*	  |		del 15		 |
*	  v		 ---->		 v
*	 10(b)				 10(b)
*		\
*		15(r)
*/
void test_delRedBlackTree_delete_15_from_3_degree_tree(void){
	
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, NULL, &node15, 'b');
	Node *root = &node10;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_PTR(&node15, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
	
}

/**
*	 root				root
*	  |		del 5		 |
*	  v		 ---->		 v
*	 10(b)				 10(b)
*	/	\					\
*  5(r)	15(r)				15(r)
*/
void test_delRedBlackTree_delete_5_from_4_degree_tree(void){
	
	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	
}

/**
*	 root				root
*	  |		del 5		 |
*	  v		 ---->		 v
*	 10(b)				 10(b)
*	/	\					\
*  5(b)	15(b)				15(r)
*/
void test_delRedBlackTree_delete_5_from_4_degree_tree_with_black_child(void){
	
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	Node *root = &node10;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node5);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
	
}

/**
*	
*	 root				root
*	  |		del 1		 |
*	  v		 ---->		 v
*	 5(b)				 15(b)
*	/	\				/	\
* 1(b)	15(r)		  5(b)	20(b)
*		/	\			\
*	  10(b)	 20(b)		10(r)
*/
void test_delRedBlackTree_delete_1_from_6_degree_tree(void){
	
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, &node20, 'r');
	setNode(&node5, &node1, &node15, 'b');
	Node *root = &node5;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
	
}

/**
*	 root				root
*	  |		del 10		 |
*	  v		 ---->		 v
*	 5(b)				 5(b)
*	/	\				/	\
* 1(b)	15(r)		  1(b)	15(b)
*		/	\					\
*	  10(b)	 20(b)				 20(r)
*/
void test_delRedBlackTree_delete_10_from_5_degree_tree(void){
	
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, &node20, 'r');
	setNode(&node5, &node1, &node15, 'b');
	Node *root = &node5;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node10, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, &node20, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
	
}

/**
*	 root				root
*	  |		del 20		 |
*	  v		 ---->		 v
*	 5(b)				 5(b)
*	/	\				/	\
* 1(b)	15(r)		  1(b)	15(b)
*		/	\				/
*	  10(b)	 20(b)		10(r)
*/
void test_delRedBlackTree_delete_20_from_5_degree_tree(void){
	
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, &node20, 'r');
	setNode(&node5, &node1, &node15, 'b');
	Node *root = &node5;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node20);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node20, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	
}

/**
*	 	 root				root
*	  	 |		del 1		 |
*	  	 v		 ---->		 v
*	 	15(b)				 15(b)
*	   /	\			   /	  \
* 	5(r)	 25(r)		 5(b)	    25(r)
*	/ \	 	  /	  \			\	    /	\
* 1(b) 10(b) 20(b) 30(b)	10(r) 20(b)	 30(b)
*/
void test_delRedBlackTree_delete_1_from_8_degree_tree(void){
	
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');
	setNode(&node25, &node20, &node30, 'r');
	setNode(&node15, &node5, &node25, 'b');
	Node *root = &node15;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'r', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	
}

/**
*	 	 root						root
*	  	 |		del 10			 	 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 		/	  \
* 	5(r)	 25(r)		 		5(b)	   25(r)
*	/ \	 	  /	  \				/		    /	\
* 1(b) 10(b) 20(b) 30(b)  	1(r) 		20(b)	 30(b)
*/
void test_delRedBlackTree_delete_10_from_8_degree_tree(void){
	
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');
	setNode(&node25, &node20, &node30, 'r');
	setNode(&node15, &node5, &node25, 'b');
	Node *root = &node15;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node10, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'r', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	
}

/**
*	 	 root						root
*	  	 |		del 20			 	 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 		/	  \
* 	5(r)	 25(r)		 		5(r)	   25(b)
*	/ \	 	  /	  \				/	\	   		\
* 1(b) 10(b) 20(b) 30(b)  	1(b) 	10(b)		 30(r)
*/
void test_delRedBlackTree_delete_20_from_8_degree_tree(void){
	
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');
	setNode(&node25, &node20, &node30, 'r');
	setNode(&node15, &node5, &node25, 'b');
	Node *root = &node15;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node20);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node20, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, &node30, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);
	
}

/**
*	 	 root						root
*	  	 |		del 30			 	 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 		/	  \
* 	5(r)	 25(r)		 		5(r)	   25(b)
*	/ \	 	  /	  \				/	\	  	/
* 1(b) 10(b) 20(b) 30(b)  	1(b) 	10(b)  20(r)
*/
void test_delRedBlackTree_delete_30_from_8_degree_tree(void){
	
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');
	setNode(&node25, &node20, &node30, 'r');
	setNode(&node15, &node5, &node25, 'b');
	Node *root = &node15;
	Node *retNode;
	
	retNode = delRedBlackTree(&root, &node30);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node30, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);
	
}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(b)					 15(b)
*	   /	\					/	 \
* 	1(b)	 15(b)		 	5(b)	  20(b)
*		 	    \		
* 			  	20(r)  	
*/
void test_delRedBlackTree_case_1a_remove_1(void){

	setNode(&node20, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, &node20, 'b');
	setNode(&node5, &node1, &node15, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);

}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(b)					 10(b)
*	   /	\					/	 \
* 	1(b)	 15(b)		 	5(b)	  15(b)
*		 	 /		
* 			10(r)  	
*/
void test_delRedBlackTree_case_1b_remove_1(void){

	setNode(&node10, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);

}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(b)					 5(d)
*	   /	\						 \
* 	1(b)	 10(b)		 			  10(r)
*		 	 		
* 			  	
*/
void test_delRedBlackTree_case_2a_remove_1(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'd', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);

}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(r)					 5(b)
*	   /	\						 \
* 	1(b)	 10(b)		 			  10(r)
*		 	 		
* 			  	
*/
void test_delRedBlackTree_case_2b_remove_1(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);

}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(b)					 15(b)
*	   /	\					/	 \
* 	1(b)	 15(r)		 	5(b)	  20(b)
*		 	 /	 \				\
* 		 10(b)    20(b)			10(r)
*/
void test_delRedBlackTree_case_3a_remove_1(void){

	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, &node20, 'r');
	setNode(&node5, &node1, &node15, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node15, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);

}

/**
*	 	 root					root
*	  	 |		 del 1			  |
*	  	 v		 ---->			  v
*	 	5(b)					 20(b)
*	   /	\					/	 \
* 	1(b)	 20(r)		 	10(r)	  25(b)
*		 	 /	 \			/	\
* 		 10(b)    25(b)	   5(b)	15(b)
*			\
*			15(r)
*/
void test_delRedBlackTree_case_3b_remove_1(void){

	setNode(&node15, NULL, NULL, 'r');
	setNode(&node10, NULL, &node15, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node20, &node10, &node25, 'r');
	setNode(&node5, &node1, &node20, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node1);
	
	TEST_ASSERT_EQUAL_PTR(&node20, root);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);

}

/**
*	 	 root					root
*	  	 |		 del 15			  |
*	  	 v		 ---->			  v
*	 	10(b)					 5(b)
*	   /	\					/	 \
* 	5(b)	 15(b)		 	1(b)	  10(b)
*	 /	 	    		
* 1(r)		  	 	
*/
void test_delRedBlackTree_case_1a_removeRight_15(void){

	setNode(&node1, NULL, NULL, 'r');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');

	Node *root = &node10;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node15, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);

}

/**
*	 	 root					root
*	  	 |		 del 15			  |
*	  	 v		 ---->			  v
*	 	10(b)					 5(b)
*	   /	\					/	 \
* 	1(b)	 15(b)		 	1(b)	  10(b)
*	 	\	 	    		
* 		5(r)		  	 	
*/
void test_delRedBlackTree_case_1b_removeRight_15(void){

	setNode(&node5, NULL, NULL, 'r');
	setNode(&node1, NULL, &node5, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node1, &node15, 'b');

	Node *root = &node10;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node15);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node15, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);

}

/**
*	 	 root					root
*	  	 |		 del 10			  |
*	  	 v		 ---->			  v
*	 	5(b)					 5(d)
*	   /	\					/
* 	1(b)	 10(b)		 	1(r)
*		 	 		
* 			  	
*/
void test_delRedBlackTree_case_2a_removeRight_10(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node10, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'd', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/**
*	 	 root					root
*	  	 |		 del 10			  |
*	  	 v		 ---->			  v
*	 	5(r)					 5(b)
*	   /	\					/
* 	1(b)	 10(b)		 	1(r)
*		 	 		
* 			  	
*/
void test_delRedBlackTree_case_2b_removeRight_10(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');

	Node *root = &node5;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node10);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node10, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);

}

/**
*	 	 	root					root
*	  	 	 |		 del 20			  |
*	  	 	 v		 ---->			  v
*	 		15(b)					 5(b)
*	   		/	\					/	 \
* 		5(r)	 20(b)		 	1(b)	  15(b)
*		/	\							  /
* 	1(b)    10(b)						10(r)
*/
void test_delRedBlackTree_case_3a_removeRight_20(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'r');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node15, &node5, &node20, 'b');

	Node *root = &node15;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node20);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node20, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(&node10, NULL, 'b', &node15);

}

/**
*	 	 	root					root
*	  	 	 |		 del 25			  |
*	  	 	 v		 ---->			  v
*	 		20(b)					 5(b)
*	   		/	\					/	 \
* 		5(r)	 25(b)		 	1(b)	  15(r)
*		/	\							  /		\
* 	1(b)    15(b)						10(b)	 20(b)	
*			/
*		 10(r)			
*/
void test_delRedBlackTree_case_3b_removeRight_25(void){

	setNode(&node10, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, NULL, 'b');
	setNode(&node5, &node1, &node15, 'r');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node5, &node25, 'b');

	Node *root = &node20;
	Node *retNode;

	retNode = _delRedBlackTree(&root, &node25);
	
	TEST_ASSERT_EQUAL_PTR(&node5, root);
	TEST_ASSERT_EQUAL_PTR(&node25, retNode);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', root);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'r', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);

}

/**
*	 	 	root					root
*	  	 	 |		 successor		  |
*	  	 	 v		 	5			  v
*	 		5(b)	 -------->		  -

*/
void test_removeNextLargerSuccessor_remove_5_and_do_nothing(void){

	setNode(&node5, NULL, NULL, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = removeNextLargerSuccessor(&root);
	TEST_ASSERT_EQUAL_PTR(NULL, root);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);

}

/**
*	 	 	root					root
*	  	 	 |		 successor		  |
*	  	 	 v		 	5			  v
*	 		5(b)	 -------->		 10(b)
*	   			\
*		       10(r)
*/
void test_removeNextLargerSuccessor_case_1(void){

	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, NULL, &node10, 'b');

	Node *root = &node5;
	Node *retNode;

	retNode = removeNextLargerSuccessor(&root);
	
	TEST_ASSERT_EQUAL_PTR(&node10, root);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);

}

/**
*	 	 	root					root
*	  	 	 |		 successor		  |
*	  	 	 v		 	1			  v
*	   		/		-------->		//	 
*		  1(b)   					 
*/
void test_removeNextLargerSuccessor_case_2(void){

	setNode(&node1, NULL, NULL, 'b');

	Node *retNode,*parentNode = &node1;

	retNode = removeNextLargerSuccessor(&parentNode);
	
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_NULL(parentNode);
	TEST_ASSERT_EQUAL(1, isDoubleBlack(parentNode, retNode));

}

/**
*	 	 	root					root
*	  	 	 |		 successor		  |
*	  	 	 v		 	1			  v
*	   		/		-------->		 /
*		  1(r)   					 
*/
void test_removeNextLargerSuccessor_case_3(void){

	setNode(&node1, NULL, NULL, 'r');

	Node *retNode,*parentNode = &node1;

	retNode = removeNextLargerSuccessor(&parentNode);
	
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_NULL(parentNode);
	TEST_ASSERT_EQUAL(1, isBlack(parentNode));

}

/**
*	 	 root						root
*	  	 |		successor 5			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 			  \
* 	5(r)	 25(r)		 			     25(r)
*/
void test_removeNextLargerSuccessor_given_5r_15b_25r_then_remove_5(){

	setNode(&node5, NULL, NULL, 'r');
	setNode(&node25, NULL, NULL, 'r');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = removeNextLargerSuccessor(&rootNode);
	
	TEST_ASSERT_EQUAL_PTR(&node15, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node25, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
	
}

/**
*	 	 root						root
*	  	 |		successor 1			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 		/	  \
* 	5(b)	 25(b)		 		5(b)	   25(b)
*	/	 	  /	  						  	/
* 1(r) 		 20(r)   		 		 	20(r) 
*/
void test_removeNextLargerSuccessor_given_1r_5b_15b_20r_25b_then_remove_1(){
	setNode(&node1, NULL, NULL, 'r');
	setNode(&node20, NULL, NULL, 'r');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node25, &node20, NULL, 'b');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = removeNextLargerSuccessor(&rootNode);
	
	TEST_ASSERT_EQUAL_PTR(&node15, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, NULL, 'b', &node25);

}

/**
*	 	 root						root
*	  	 |		successor 1			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(d)
*	   /	\			  	 		/	  \
* 	5(b)	 25(b)		 		5(b)	   25(r)
*	/ \	 	  /	  \					\	  	/	\
* 1(b) 10(b) 20(b) 30(b)  		 	10(r) 20(b)  30(b)  
*/
void test_removeNextLargerSuccessor_given_1b_5b_10b_15b_20b_25b_30b_then_remove_1(){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node25, &node20, &node30, 'b');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = removeNextLargerSuccessor(&rootNode);
	
	TEST_ASSERT_EQUAL_PTR(&node15, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'd', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'r', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);

}

/**
*	 	 root						root
*	  	 |		successor 1			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b)
*	   /	\			  	 		/	  \
* 	5(b)	 25(b)		 		5(b)	   25(b)
*	/ \	 	  /	  \				/	\	  	/	\
* 1(b) 10(b) 20(b) 30(b)  	2(b) 	10(b) 20(b)  30(b)  
*	\
*	2(r)
*/
void test_removeNextLargerSuccessor_given_1b_2r_5b_10b_15b_20b_25b_30b_then_remove_1(){
	setNode(&node2, NULL, NULL, 'r');
	setNode(&node1, NULL, &node2, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node20, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node25, &node20, &node30, 'b');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = removeNextLargerSuccessor(&rootNode);
	
	TEST_ASSERT_EQUAL_PTR(&node15, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node1, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
	TEST_ASSERT_EQUAL_NODE(&node2, &node10, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, &node25, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(&node20, &node30, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);

}

/**
*	 	 root						root
*	  	 |		remove 15			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	25(b) 
*	   /	\			  	 		/
*	  5(r)	25(r)				 5(r)
*/
void test_delRedBlackTree_given_5r_15b_25r_then_remove_15(){

	setNode(&node5, NULL, NULL, 'r');
	setNode(&node25, NULL, NULL, 'r');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = _delRedBlackTree(&rootNode,&node15);
	
	TEST_ASSERT_EQUAL_PTR(&node25, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node15, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node25);
	
}

/**
*	 	 root						root
*	  	 |		remove 15			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	5(b) 
*	   /				  	 		
*	  5(r)					
*/
void test_delRedBlackTree_given_5r_15b_then_remove_15(){

	setNode(&node5, NULL, NULL, 'r');
	setNode(&node15, &node5, NULL, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = _delRedBlackTree(&rootNode,&node15);
	
	TEST_ASSERT_EQUAL_PTR(&node5, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node15, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
	
}

/**
*	 	root						root
*	  	 |		remove 5			 |
*	  	 v		 ---->			 	 v
*	 	15(b)					 	15(b) 
*	   /	\			  	 		/	\
*	  5(b)	25(b)				 10(b)	25(b)
*	  /  \						 /
*	1(r)  10(r)				  1(r)
*/
void test_delRedBlackTree_given_1r_5b_15r_20b_25b_then_remove_5(){

	setNode(&node1, NULL, NULL, 'r');
	setNode(&node10, NULL, NULL, 'r');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node15, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node15;
	retNode = _delRedBlackTree(&rootNode,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node15, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	
}

/**
*	Testing : remove left parent without case involved
*
*	 	root						root
*	  	 |		remove 5			 |
*	  	 v		 ---->			 	 v
*	 	 20(b)					 	15(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   25(b)			10(b)	25(b)
*	/  \			\			 /
*1(b)  15(b)		30(b)		  1(r)
*		/
*	   10(r)
*/
void test_delRedBlackTree_remove_5b_left_parent_without_case_involved(){

	setNode(&node10, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, &node10, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node25, NULL, &node30, 'b');
	setNode(&node20, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, &node30, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	
}
/**
*	Testing : remove left parent with case 1a
*
*	 		root						root
*	  	 	|		remove 5			 |
*	  	 	v		 ---->			 	 v
*	 	 	20(b)					 	20(b) 
*	   		/	  \			  	 		/	\
*	 	5(b)	   35(b)			2(b)	  35(b)
*		/  \		/	\			/ \		  /	 \
*	2(b)  15(b)  30(b)	40(b)	1(b)  15(b)	30(b) 40(b) 
*	/		  
* 1(r)		
*/
void test_delRedBlackTree_remove_5b_left_parent_with_case_1a(){

	setNode(&node1, NULL, NULL, 'r');
	setNode(&node2, &node1, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node40, NULL, NULL, 'b');
	setNode(&node5, &node2, &node15, 'b');
	setNode(&node35, &node30, &node40, 'b');
	setNode(&node20, &node5, &node35, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node2);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node2, &node35, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(&node30, &node40, 'b', &node35);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
	
}

/**
*	Testing : remove left parent with case 1b
*
*	 		root						root
*	  	 	|		remove 5			 |
*	  	 	v		 ---->			 	 v
*	 	 	20(b)					 	20(b) 
*	   		/	  \			  	 		/	\
*	 	5(b)	   35(b)			2(b)	  35(b)
*		/  \		/	\			/ \		  /	 \
*	1(b)  15(b)  30(b)	40(b)	1(b)  15(b)	30(b) 40(b) 
*		\	  
* 		2(r)		
*/
void test_delRedBlackTree_remove_5b_left_parent_with_case_1b(){

	setNode(&node2, NULL, NULL, 'r');
	setNode(&node1, NULL, &node2, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node40, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node35, &node30, &node40, 'b');
	setNode(&node20, &node5, &node35, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node2);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node2, &node35, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(&node30, &node40, 'b', &node35);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
	
}

/**
*	Testing : remove left parent with case 2a and 2b
*
*	 	root						root
*	  	 |		remove 5			 |
*	  	 v		 ---->			 	 v
*	 	 20(r)					 	20(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   30(b)			15(b)	  30(r)
*	/  \		/	\			/ 		  /	 	\
*1(b)  15(b)  25(b)	35(b)	1(r)  		25(b)  35(b)
*/
void test_delRedBlackTree_remove_5b_left_parent_with_case_2a_and_2b(){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node35, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node30, &node25, &node35, 'b');
	setNode(&node20, &node5, &node30, 'r');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node5, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node15, &node30, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(&node25, &node35, 'r', &node30);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node35);
	
}

/**
*	Testing : remove right parent without case involve
*
*	 	root						root
*	  	 |		remove 25			 |
*	  	 v		 ---->			 	 v
*	 	 20(b)					 	20(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   25(b)			5(b)	  35(b)
*	/  \		/	\			/ \		  /	 \
*1(b)  15(b)  30(b)	35(b)	1(b)  15(b)	30(b) 40(b) 
*						\
*	  	`				40(r)
*/
void test_delRedBlackTree_remove_25b_right_parent_without_case_involved(){

	setNode(&node40, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node30, NULL, NULL, 'b');
	setNode(&node35, NULL, &node40, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node25, &node30, &node35, 'b');
	setNode(&node20, &node5, &node25, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node25);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node25, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node35, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(&node30, &node40, 'b', &node35);
	
}

/**
*	Testing : remove right parent with case 1a
*
*	 	root						root
*	  	 |		remove 35			 |
*	  	 v		 ---->			 	 v
*	 	 20(b)					 	20(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   35(b)			5(b)	  30(b)
*	/  \		/	\			/ \		  /	 \
*1(b)  15(b)  30(b)	40(b)	1(b)  15(b)	25(b) 40(b) 
*			  /
*			25(r)
*/
void test_delRedBlackTree_remove_35b_right_parent_with_case_1a(){

	setNode(&node25, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node30, &node25, NULL, 'b');
	setNode(&node40, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node35, &node30, &node40, 'b');
	setNode(&node20, &node5, &node35, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node35);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node35, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node30, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(&node25, &node40, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
	
}

/**
*	Testing : remove right parent with case 1b
*
*	 	root						root
*	  	 |		remove 35			 |
*	  	 v		 ---->			 	 v
*	 	 20(b)					 	20(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   35(b)			5(b)	  30(b)
*	/  \		/	\			/ \		  /	 \
*1(b)  15(b)  25(b)	40(b)	1(b)  15(b)	25(b) 40(b) 
*				\
*				30(r)
*/
void test_delRedBlackTree_remove_35b_right_parent_with_case_1b(){

	setNode(&node30, NULL, NULL, 'r');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node25, NULL, &node30, 'b');
	setNode(&node40, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node35, &node25, &node40, 'b');
	setNode(&node20, &node5, &node35, 'b');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node35);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node35, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node30, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
	TEST_ASSERT_EQUAL_NODE(&node25, &node40, 'b', &node30);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node40);
	
}

/**
*	Testing : remove right parent with case 2a and 2b
*
*	 	root						root
*	  	 |		remove 30			 |
*	  	 v		 ---->			 	 v
*	 	 20(r)					 	20(b) 
*	   /	  \			  	 		/	\
*	 5(b)	   30(b)			5(r)	  35(b)
*	/  \		/	\			/ \		  /	 
*1(b)  15(b)  25(b)	35(b)	1(b)  15(b)	25(r)  
*/
void test_delRedBlackTree_remove_30b_right_parent_with_case_2a_and_2b(){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node35, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node30, &node25, &node35, 'b');
	setNode(&node20, &node5, &node30, 'r');
	
	Node *retNode,*rootNode = &node20;
	retNode = _delRedBlackTree(&rootNode,&node30);
	
	TEST_ASSERT_EQUAL_PTR(&node20, rootNode);
	TEST_ASSERT_EQUAL_PTR(&node30, retNode);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
	TEST_ASSERT_EQUAL_NODE(&node1, &node15, 'r', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
	TEST_ASSERT_EQUAL_NODE(&node5, &node35, 'b', &node20);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
	TEST_ASSERT_EQUAL_NODE(&node25, NULL, 'b', &node35);
	
}
