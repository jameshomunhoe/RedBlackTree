#include "unity.h"
#include "Rotations.h"
#include "Node.h"
#include "InitNode.h"

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



void changeRootByVal(Node *node, Node *newNode){
	node = newNode;
}

void changeRootByRef(Node **nodePtr, Node *newNode){
	*nodePtr = newNode;
}

void test_changeRootByValue(){
	Node *root;
	root = &node10;
	
	changeRootByVal(root,&node5);
	TEST_ASSERT_EQUAL_PTR(root,&node10);
	TEST_ASSERT_EQUAL(10,root->data);
}

void test_changeRootByRef(){
	Node *root;
	root = &node10;
	
	changeRootByRef(&root,&node5);
	TEST_ASSERT_EQUAL_PTR(&node5,root);
	TEST_ASSERT_EQUAL(5,root->data);

}	

/**
*		5				 10
*	   	 \ 		>>		/
*	  	  10		   5
*/
void test_leftRotate_should_rotate_2_node(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, &node10, 'b');
	
	Node *root = &node5;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/**
*	1				  5
*	 \				 /	\
*  	  5		>>		1	 10
*	   \
*		10
*
*/
void test_leftRotate_should_rotate_3_node(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, NULL, &node10, 'b');
	setNode(&node1, NULL, &node5, 'b');
	
	Node *root = &node1;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
 *    	     5					15
 *  	    /  \			   /   \
 * 		   1	15		>>	  5		20
 * 		       /  \			 / \	  \
 *		  	  10   20		1	10	  25
 *					 \
 *				 	  25
 *
 */
void test_leftRotate_should_rotate_6_node(void){
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node20, NULL, &node25, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node15, &node10, &node20, 'b');
	setNode(&node5, &node1, &node15, 'b');
	
	Node *root = &node5;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node15.right, &node20);	
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node15);
}

/**
*		10			5
*	   /  			 \
*	  5		>>		  10
*/
void test_rightRotate_should_rotate_2_node(void){
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	
	Node *root = &node10;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
*		10
*	   /  			5
*	  5		>>	   /  \	
*	 /			  1	  10
*	1
*/
void test_rightRotate_should_rotate_3_node(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	
	Node *root = &node10;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
 *         20                    10
 *        /  \                  /  \
 *      10    25			   5	20
 *     /  \           >>      /    /  \
 *    5    15				 1	  15   25
 *   /
 *  1 
 *
 */
void test_rightRotate_should_rotate_6_node(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node10, &node25, 'b');
	
	Node *root = &node20;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);	
	TEST_ASSERT_EQUAL_PTR(node20.left, &node15);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/**
*		10			10				5
*	   /  			/			   /  \
*	  1		>>	   5		>>	  1	   10
*	   \		  /
*		5		 1
*/
void test_leftRightRotate_should_rotate_3_node(void){
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node1, NULL, &node5, 'b');
	setNode(&node10, &node1, NULL, 'b');
	
	Node *root = &node10;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
*		15			 15				10
*	   /  			/			   /  \
*	  5		>>	   10		>>	  5	   15
*	 /  \		  /				 /
*	1	 10		 5				1
*				/
*			   1
*/
void test_leftRightRotate_should_rotate_4_node(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node15, &node5, NULL, 'b');
	
	Node *root = &node15;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/**
*		20			 		20						10
*	   /  \				   /  \					  /		\
*	  5		25		>>	  10   25		>>		 5		20
*	 /  \		  		 /	\					/	    / \
*	1	 10		 		5	 15				   1	  15	25
*		  \			   /
*		   15 	  	  1
*/
void test_leftRightRotate_should_rotate_6_node(void){
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, NULL, &node15, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, &node10, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node5, &node25, 'b');
	
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left, &node15);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

/**
*		20			 		20						15
*	   /  \				   /  \					  /		\
*	  5		25		>>	  15   25		>>		 5		20
*	 /  \		  		 /						/  \      \
*	1	 15		 		5	 				   1	10 	   25
*		 /			   /  \
*		10 		  	  1	   10
*/
void test_leftRightRotate_should_rotate_6_node_2nd_situation(void){
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node15, &node10, NULL, 'b');
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, &node15, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node5, &node25, 'b');
	
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node15.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node15);
}

/**
*		1				1					5
*	     \				 \				   /  \
*	  	  10		>>	  5			>>	  1    10
*	     /	  			   \
*		5			 		10
*/
void test_rightLeftRotate_should_rotate_3_node(void){
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	setNode(&node1, NULL, &node10, 'b');
	
	Node *root = &node1;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
*		1						1						5
*	     \ 						 \					   /  \
*	  	  10		>>			  5			>>		  1	   10
*	   	 /	\  					   \				 		\
*		5 	15	 					10						15
*									 \
*			   						  15
*/
void test_rightLeftRotate_should_rotate_4_node(void){
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, &node5, &node15, 'b');
	setNode(&node1, NULL, &node10, 'b');
	
	Node *root = &node1;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/**
*		5			 				5							15
*	   /  \						   /  \						   /   \
*	  1		20			>>		  1	   15			>>		  5	    20
*	       /  \  					  /  \					 / \	  \
*		 15	   25 					 10	  20				1	10		25
*		 / 			  						\
*		10  	  	  						 25
*/
void test_rightLeftRotate_should_rotate_6_node(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node10, NULL, NULL, 'b');
	setNode(&node15, &node10, NULL, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node15, &node25, 'b');
	setNode(&node5, &node1, &node20, 'b');
	
	Node *root = &node5;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, &node10);
	TEST_ASSERT_EQUAL_PTR(node10.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node15.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node20.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node15);
}

/**
*		5			 		5						10
*	   /  \				   /  \					  /		\
*	  1		20		>>	  1   10		>>		 5		20
*	   	   /  \  		 	 	\				/       /  \
*		  10	25	 			 20			   1       15   25
*		   \			   		/	\
*			15 		  	  	   15	25
*/
void test_rightLeftRotate_should_rotate_6_node_2nd_situation(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node15, NULL, NULL, 'b');
	setNode(&node10, NULL, &node15, 'b');
	setNode(&node25, NULL, NULL, 'b');
	setNode(&node20, &node10, &node25, 'b');
	setNode(&node5, &node1, &node20, 'b');
	
	Node *root = &node5;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left, &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left, &node5);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node20);
	TEST_ASSERT_EQUAL_PTR(node15.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left, &node15);
	TEST_ASSERT_EQUAL_PTR(node20.right, &node25);
	TEST_ASSERT_EQUAL_PTR(node25.left, NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right, NULL);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
}

