/**
	* Priority Queue Implementation using Linked List
	
	* Time Complexity Analysis
	* Enque Operation amortized time O(N)     
	* Deque Operation amortized time O(1)
	* Peek(Getting the Highest Priority Element) amortized time O(1)
	
*/

#include<stdio.h>
#include<stdlib.h>


/**
* Node -> Stores information of each element of Queue
* data -> stores element value
* priority -> stores element's priority
* next -> stores the next element
**/
typedef struct Node {
	
	int data;  // Stores Node value
	
	int priority;   // Higher Value indicates highest priority

	struct Node* next;  
	
} Node;


/**
* Creates a new Node
*/
Node* newNode(int d, int p){
	
	Node* temp = (Node*)malloc(sizeof(Node));
	
	temp->data = d;
	temp->priority = p;
	
	temp->next = NULL;
	
	
}

/**
* Peek -> returs the value at Head(Having highest Priority)
* Time Complexity: O(1)
*/
int peek( Node** head){
	
	return (*head)->data;
}


/**
* Deque(Pop) -> removes the element having highest priority from Queue
* Removes Head element
* Time Complexity: O(1)
*/
void pop( Node** head){
	
	Node* temp = *head; // storing the current head into temp
	
	(*head) = (*head)->next;  // storing the next node info to Head
	
	free(temp);  // free up Temp node
}


/**
* Push -> Insert a new node in the queue at a position according to its priority
* 
* Time Complexity: O(N)
*/
void push(Node** head, int d, int p){
	
	Node* start = (*head);   // stores head node info to start
	
	// Create a new node
	Node* temp = newNode(d, p);

	
	// If the Head Node as lower priority than NewNode
	if( (*head)->priority < p ){
	
		// Insert new node as Head
		temp->next = (*head);
		
		//Making new node as head
		(*head) = temp;
		
	}else{
	
		/**
		 * Travesing through list and Finding position to insert new Node
	 	 * If same priority Node is present then fisrt come first serve phenomena will be followed (i.e  start->next->priority >= p )
		*/
		while( start->next != NULL  && start->next->priority >= p ){
			
			// Store the Node after which new Node will be inserted		
			start = start->next;
			
		}
		
		/**
		 * Inserting a New Node
		 * A. Either at the End Of Queue
		 * B. or at the Required Position
		*/
		temp->next = start->next;
		start->next = temp;
		
		
	}
	
}


/**
 * Function to check wheather the node is empty or not
*/
int isEmpty( Node** head){
	
	return (*head) == NULL;
}


/**
 * Printing the Priority Queue
*/

int printQueue(Node* head){
	
	if( head == NULL ){
		printf("Queue is empty\n");
		exit(0);
	}
	
	while( head->next != NULL){
		
		printf("(%d,%d)-> ",head->data,head->priority );
		
		head = head->next;
	}
	
	printf("(%d,%d)\n",head->data,head->priority );
	
	
}



int main(){
	
	int choice, nodeData, nodePriority; //Stores no of element
	
	Node* priorityQueue = newNode(4,2);  // Initialzing Priority Queue with a Node(data->4, priority->2)
	
	printf("Priority Queue Implementation using Linked List\n");
	
	
	while(1){
	
	
		printf("\nEnter your choice\n");
		printf("1. Insert a new Node\n2. Delete a Node\n3. Peek the highest priority(Head) Node\n4. Print complete Priority Queue with Priority\n5. Exit\n");
		scanf("%d",&choice);
	
		
		
		switch(choice){
			
			case 1: printf("Insert a new Node in Queue\n");
					printf("Enter Node data: ");
					scanf("%d", &nodeData);
					printf("\nEnter Node priority: ");
					scanf("%d", &nodePriority);
					
					push(&priorityQueue, nodeData, nodePriority);
					break;
					
			case 2: printf("Deleting a Node(highest priority(head))\n");
					
					pop(&priorityQueue);
					break;
			
			case 3: printf("Highest Priority Node:  data:%d",peek(&priorityQueue));
					break;
					
			case 4: printf("The Priority Queue:\n");
					
					printQueue(priorityQueue);
					break;
					
			case 5: exit(0);
			
			default: break;
			
		}			

	
	
	}
		
}



