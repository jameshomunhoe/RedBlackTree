#include "unity.h"
#include "CustomAssertion.h"


/**
*	Custom assertion of red-black tree
*/
void assertNode(Node *left, Node *right, char color, Node *actualNode, int lineNumber){
				//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^
				//			expected						actual
 					
	UNITY_TEST_ASSERT_EQUAL_INT8(color, actualNode->color, lineNumber, "Wrong color.");		
	UNITY_TEST_ASSERT_EQUAL_PTR(left, actualNode->left, lineNumber, "Wrong left node.");		
	UNITY_TEST_ASSERT_EQUAL_PTR(right, actualNode->right, lineNumber, "Wrong left node.");		
}