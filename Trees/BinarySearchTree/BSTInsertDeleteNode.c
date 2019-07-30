#include<stdio.h>
#include<stdlib.h>

// BST node structure
struct node{
	int key;
	struct node *left, *right;
};

// Create a new Node in BST
struct node* newNode( int item) {

	struct node *temp = (struct node*) malloc( sizeof(struct node) );
	
	temp->key = item;

	temp->left = temp->right = NULL;
	
	return temp;
}


// Utility function to insert new node in given BST with given key value
struct node* insert( struct node* node, int key) {
	
	/* If tree empty, create and returns root node*/
	if( node == NULL){
		
		return newNode(key);
		
	} 
	/* if new key is smaller than root node key */
	else if( key < node->key){
		node->left = insert( node->left, key );
	} 
	/* if new key is greater that root node key */
	else if( key > node->key ) {	
		node->right = insert( node->right, key );
	}
	
	/* returns (unchanged) node pointer(root node)*/
	return node;  
}


/*
	* Depth First Search: In-order Traversal (left->root->right)
*/
void inorderTraverse( struct node *root) {
	
	if( root != NULL ) {
		
		inorderTraverse( root->left );
		printf("%d\n", root->key );
		inorderTraverse( root->right );
		
	} 
}

void preorderTraverse( struct node *root) {
	
	if( root != NULL) {
		
		printf( "%d\n", root->key);
		preorderTraverse( root->left );
		preorderTraverse( root->right );
	}
}

void postorderTraverse( struct node *root ) {
	
	if( root != NULL) {
		
		postorderTraverse( root->left );
		postorderTraverse( root->right );
		printf("%d\n", root->key);
	}
}

/**
 * "In-order successor" needed for deletion of Node if it has both children
 * Left-most leaf node of Right-subtreee of the Node to be deleted is In-order successor
 * minValueNode finds the In-order successor of that node
 * @return struct Node* i.e in-order successor 
*/
struct node* minValueNode( struct node* root) {
		
	// Base Case: If the node doesn't have left-child i.e. the node is In-order successor( or minValueNode of the tree)
	if ( root->left == NULL) {	
		return root;
		
	}else {
		// always traversing through left child
		return minValueNode( root->left );
	} 	
	
}

/**
 * Deletes the Node with specific Key value
 * 3 Cases are there
 * 1. If the delete Node has only Left Child
 * 2. If the delete Node has only Right Child
 * 3. If the Delete Node has both Children
 * @return struct Node* new root of BST
*/
struct node* deleteNodeBST( struct node* root, int key ) {
	
	
	// Traversing and finding the Node need to be deleted
	
	// Base case
	if(root == NULL) {
		return root;
	}
	
	/**
	 * If Key is less than the Root's key then the Node needed to be deleted
	 * lies in the left sub-tree
	*/
	if( key < root->key ) {
		root->left = deleteNodeBST( root->left, key);
	}
	
	/**
	 * If Key is greater than the Root's key then the Node needed to be deleted
	 * lies in the right sub-tree
	*/
	else if( key > root->key ) {
		root->right = deleteNodeBST( root->right, key );
	} 
	/**
	 * If Key is equal to the Node needed to be deleted key
	 * We've the reached to Node in BST which needed to be deleted 
	*/
	else {
		
		
		/**
		 * 3 Cases are there
 			* 1. If the delete Node has only Left Child
 			* 2. If the delete Node has only Right Child
 			* 3. If the Delete Node has both Children
		 */ 
		
		
		// Case 1: If the Delete Node has only Left child or no child
		if( root->right == NULL ) {
			
			// assign the root->left to new temp node
			struct node *temp = root->left;
			// clear old root node
			free( root );
			
			// returning the new root node
			return temp;  
		}
		// Case 2: if Delete Node has only right child or no child
		else if( root->left == NULL  ) {
			
			// assign the root->right to new temp node
			struct node *temp = root->right;
			// clear old root node
			free( root );
			
			// returning the new root node
			return temp;
		}
		// Case 3: if Delete Node has both child
		// So Delete Node is replaced by its in-order successor 
		// in-order successor is left-most node(smallest) in right-subtree of Delete Node
		else {
			
			// Passing the root node of the Right sub-tree of Delete Node to get in-order successor
			struct node *temp = minValueNode( root->right );
			
			// Copy the content of in-order successor to Delete Node
			root->key = temp->key;
			
			// Delete the in-order successor
			// Further Optimise by Tracking the Parent of Successor
			root->right = deleteNodeBST( root->right, temp->key);
	
		}	
	}
	return root;	
}//end of function


int main(){

	struct node *root = NULL;
	
	/**
						50
					  /    \
	                30       70
	              /   \     /  \
	            20    40   60   80
	*/
	
	//1st Node
	root = insert(root, 50);
	
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	
	// Print DFS: inorder traverse
	printf("In-order(sorted) Traversal:\n");
	inorderTraverse( root );
	
	printf("Pre-order traversal:\n");
	preorderTraverse( root );

	printf("Post-order traversal:\n");
	postorderTraverse( root );
	
	root = deleteNodeBST(root, 50);
	printf("In-order(sorted) Traversal after delete node '50':\n");
	inorderTraverse( root );
	/** 
		After Deleting Root Node "50"
						60
					  /    \
	                30      70
	              /   \       \
	            20    40       80
	*/
	
	root = deleteNodeBST(root, 80);
	printf("In-order(sorted) Traversal after delete node '80':\n");
	inorderTraverse( root );
	/** 
		After Deleting Root Node "80"
						60
					  /    \
	                30      70
	              /   \     
	            20    40       
	*/
	
	root = insert(root, 98);
	printf("In-order(sorted) Traversal after inserting node '98':\n");
	inorderTraverse( root );
	/** 
		After Inserting Root Node "98"
						60
					  /    \
	                30      70
	              /   \       \
	            20    40       98
	*/
	
	root = insert(root, 35);
	printf("In-order(sorted) Traversal after inserting node '35':\n");
	inorderTraverse( root );
	/** 
		After Inserting Root Node "98"
						60
					  /    \
	                30      70
	              /   \       \
	            20    40       98
	                  /
	                35
	*/
	
	root = deleteNodeBST(root, 40);
	printf("In-order(sorted) Traversal after delete node '40':\n");
	inorderTraverse( root );
	/** 
		After Deleting Root Node "40"
						60
					  /    \
	                30      70
	              /   \       \
	            20    35       98
					  
	*/
	
	root = deleteNodeBST(root, 70);
	printf("In-order(sorted) Traversal after delete node '70':\n");
	inorderTraverse( root );
	/** 
		After Deleting Root Node "70"
						60
					  /    \
	                30      98
	              /   \      
	            20    35       
					  
	*/
	
	return 0;
	
}

