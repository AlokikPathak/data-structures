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


int main(){

	struct node *root = NULL;
	
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
		
	return 0;
	
}

