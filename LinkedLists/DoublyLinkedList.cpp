#include<iostream>
#include<stdlib.h>
using namespace std;

/**
 * Purpose: Define the Node structute of Doubly Linked List
 * Parameter: Head pointer
 * @returns: new Head pointer
 * Complexity: O(1)
 */
typedef struct Node{
    int info;
    struct Node *next, *prev;
}Node;


/**
 * Purpose: Forward traversal in the doubly linked list
 * Parameter: Head pointer
 * @returns: void
 * Complexity: O(N)
 */
void forwardTraversal(struct Node *head){
    cout<<"\nForward traversal in Doubly List: \n";
    while(head->next!=NULL){
        cout<<head->info<<" -> ";
        head=head->next;
   		// cout<<"\nEnd..!\n";
    }
    cout<<head->info<<endl;//for last node of list
}

/**
 * Purpose: Reverse traversal in doubly linked list
 * Parameter: Tail pointer
 * @returns: void
 * Complexity: O(N)
 */
void backwardTraversal(struct Node *tail){
    cout<<"\nBackward traversal in Doubly list:\n";
    while(tail->prev!=NULL){//Loop continues until it reaches to start node
        cout<<tail->info<<" -> ";
        tail = tail->prev;
    }
    cout<<tail->info<<endl;//for printing start node
}


/**
 * Purpose: Insert a new Node at the begining
 * Parameter: Head pointer
 * @returns: new Head pointer
 * Complexity: O(1)
 */
struct Node* insertBegin(struct Node *head){

    cout<<"\nEnter the Node which you want Insert at Front of DLL\n";
    int val; cin>>val;

    struct Node  *newN=NULL;
    newN = (struct Node*)malloc(sizeof(struct Node));//dynamic mem allocated
    newN->info= val;

    newN->prev = NULL; //its new Head so null
    newN->next = head; //points to second node which is head now;
    head->prev = newN; //head prev points to newN and becomes second node

    return newN;//returns the new Head Node


}


/**
 * Purpose: Insert a new Node at the end using Head pointer(if tail pointer is not there)
 * Parameter: Head pointer
 * @returns: new Tail pointer
 * Complexity: O(N)
 */
struct Node* insertEndHead(struct Node*head){


    while(head->next != NULL){//loops run it reaches the Tail Node
        head=head->next;//
    }

    struct Node* newTail=NULL;
    newTail = (struct Node*)malloc(sizeof(struct Node));


    head->next= newTail;
    newTail->prev = head;
    newTail->next = NULL;

    cout<<"\nEnter the node which will be inserted at End:\n";
    cin>>newTail->info;
    return newTail;

}


/**
 * Purpose: Insert a new Node at the end using Tail Pointer
 * Parameter: Head pointer
 * @returns: new Tail pointer
 * Complexity: O(1)
 */
struct Node* insertEndTail(struct Node *tail){
    struct Node* newTail=NULL;
    newTail = (struct Node*)malloc(sizeof(struct Node));

    cout<<"Enter the New Node inserted at End\n";
    cin>>newTail->info;

    newTail->next=NULL;
    tail->next = newTail;
    newTail->prev= tail;

    return newTail;

}

/**
 * Purpose: Insert a new Node after a specific Node
 * Parameter: Head pointer
 * @returns: void(since there must be node after which new node will be inserted, it never be the first node)
 * Complexity: O(N)
 */
void insertAfter(struct Node *head){
    int node_at,val;
    cout<<"Enter the Node after which you want to insert\n";
    cin>>node_at;
    cout<<"Enter the Node need to be Inserted.!\n";
    cin>>val;
    while(head->info != node_at){
        head= head->next;
    }

    struct Node *newNode=NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info=val;

    newNode->next = head->next;
    (head->next)->prev = newNode;  //next node prev is linked to newNode
    head->next=newNode;

    newNode->prev = head;

}



/**
 * Purpose: Deletes front node
 * Parameter: Head pointer
 * @returns: new Head pointer
 * Complexity: O(1)
 */
struct Node* deleteFront(struct Node* head){
    struct Node *newHead= NULL;

    newHead = head->next;
    newHead->prev = NULL;
    (head->next) = NULL;  //head becomes null reference
    free(head);
    return newHead;
}


/**
 * Purpose: Deletes end node using Tail pointer
 * Parameter: Tail pointer
 * @returns: new Tail pointer
 * Complexity: O(1)
 */
struct Node* deleteEnd(struct Node *tail){

    struct Node *newTail = NULL;
   // newTail = (struct Node*)malloc(sizeof(struct Node));

    newTail = tail->prev;
    newTail->next = NULL;
    tail->prev = NULL;
    free(tail);
    return newTail;
}

/**
 * Purpose: Deletes node after a specific node
 * Parameter: Head pointer
 * @returns: new Head pointer
 * Complexity: O(1)
 */
struct Node* deleteAfter(struct Node *head){
    int val;
    cout<<"Enter the node which you want to delete\n";
    cin>>val;

    while(head->info != val){
        head= head->next;
    }
    struct Node *newHead= NULL;
    newHead = head->prev;
    newHead->next = head->next;
   (head->next)->prev = newHead;

    //making null reference
    head->next = NULL; head->prev= NULL;
    free(head);
    return newHead;

    /*(head->prev)->next = head->next;
    (head->next)->prev = head->prev;
    head->next = NULL; head->prev=NULL;
    free(head);
    */

}


int main(){
    struct Node *head=NULL;// 1st node of DLL
    struct Node *tail=NULL;// last node of DLL

    //dynamic mem allocation
    head =(struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));
    
    int firstNode,secondNode;
    cout<<"Enter 1st Node of DLL"<<endl;
    cin>>firstNode;
	
	cout<<"Enter 2nd Node of DLL"<<endl;
	cin>>secondNode;

    head->info = firstNode;
    head->prev = NULL; //start node prev is NULL
    head->next = tail;


    tail->info= secondNode;
    tail->prev = head;
    tail->next = NULL;

    forwardTraversal(head);
    backwardTraversal(tail);


    int choice;
    while(choice!=8){
        cout<<"\nEnter your choice:\n1: Insert Front\n2: Insert at End using Head O(N)\n3: Insert at End using Tail O(1)\n4: Insert After Node:\n5: Delete Front Node using Head O(1)\n6: Delete End Node using Tail O(1)\n7: Delete Particular Node\n8: Exit..!!!\n9: Reverse Traversal:\n";
        cin>>choice;
        switch(choice){
            case 1: head=insertBegin(head);
                    break;
            case 2: tail=insertEndHead(head);
                    break;
            case 3: tail=insertEndTail(tail);
                    break;
            case 4: insertAfter(head);
                    break;
            case 5: head=deleteFront(head);
                    break;
            case 6: tail =deleteEnd(tail);
                    break;
            case 7: head=deleteAfter(head);
                    break;
            case 8: break;
            case 9: backwardTraversal(tail);

        }

        forwardTraversal(head);

    }//end of while

}
