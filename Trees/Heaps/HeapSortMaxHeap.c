#include <stdio.h>

/**
 * Name: swapTwoNum()
 * Purpose: Swaps two numbers
 * @param: int* a
 * @param: int* b
 * @return: void
 * @complexity: O(1) i.e constant time
*/
void swapTwoNum(int *a, int *b)
{
	*a = (*a + *b) - (*b = *a);
}

/**
 * Name: takeArrayInput()
 * Purpose: takes input of given array
 * @param: int* arr, pointer to array
 * @param: unsigned int size, size of array
 * @return: void
 * @complexity: O(N) i.e. linear
*/
void takeArrayInput(int *arr, int size)
{
	unsigned int i;
	printf("Enter %d elements of array\n", size);
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
}

/**
 * Name: takeArrayInput()
 * Purpose: takes input of given array
 * @param: int* arr, pointer to array
 * @param: unsigned int size, size of array
 * @return: void
 * @complexity: O(N) i.e. linear
*/
void printArray(int arr[],  int size)
{
	unsigned int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

/**
 * Name: maxHeapify()
 * Purpose: Max-heapify the given root of sub-tree as array 
 * @param: int* arr, pointer to heap array
 * @param: unsigned int size, stores size of heap array
 * @param: unsigned int nodeIndex, contains index of root node of sub-tree needed to be max-heap
 * @return: void
 * @complexity: O(logN) i.e. logrithimic time
*/
void maxHeapify(int *arr, int size, int nodeIndex)
{

	int left = (2 * nodeIndex) + 1;  // left child Node index( since array is from 0 so +1)
	int right = (2 * nodeIndex) + 2; // right child Node index
	int largest = nodeIndex;		 // initialize as root node

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	// largest in not root Node index(i.e. modified)
	if (largest != nodeIndex)
	{
		// swapping Root Node with child having largest value & build Max Heap Sub-tree
		swapTwoNum(&arr[nodeIndex], &arr[largest]);
		// recursively MaxHeapify the new subtree formed after swap
		maxHeapify(arr, size, largest);
	}
}

/**
 * Name: buildMaxHeap()
 * Purpose: Build Max heap out of an array visualized as Heap
 * @param: int arr[]
 * @param: int n, size of array
 * @return: void
 * @complexity : O(N) (max_heapify complexity: O(logN) and total n/2 steps so O(N) is linear time)
 * If array is visualized as nearly Complete Binary Tree, all the elements after n/2 to n are leaves
 * In heaps, the leaves are automatically a Max Heap, since they don't have child
 * 
*/
void buildMaxHeap(int *arr, int n)
{
	int i;
	for (i = (n / 2) - 1; i >= 0; i--)
		maxHeapify(arr, n, i);
}

/**
 * Name: heapSortMaxHeap()
 * Purpose: Build Max Heap out of given array visualized as heap, and then sorting the Max Heap
 * @param: int* arr, pointer to array
 * @param: int n, size of array
 * @return: void
 * @complexity: O(NlogN), since BuilMaxHeap() takes O(N) and traversing through Binary Tree takes logarithimic time
*/
void heapSortMaxHeap(int *arr, int n)
{
	int i;
	// Making Max Heap using the heap
	buildMaxHeap(arr, n);
	printf("\nMax Heap: ");
	printArray(arr, n);

	// Performing Heap Sort on Max heap
	// heap sort using man-heap
	// exchange last node with root, man-heapify the changed heap
	// doing this for all nodes from last to first( sorting using bottom-to-top(leaves to root) way in heap)
	for (i = n - 1; i >= 0; i--)
	{
		// Move current root to end(i.e i, everytime getting reduced by 1)
		swapTwoNum(&arr[0], &arr[i]);
		// Remove the last node, and call Max Heapify on reduced heap of size "i"
		maxHeapify(arr, i, 0);
	}
}

/**
 * Name: main()
 * Pupose: Starts execution of program
 * @return: int
 * ex. n = 10, arr[n]= {14, 16, 10, 9, 7, 8, 3, 2, 4, 1}
 * Max_Heap: {16, 14, 10, 9, 7, 8, 3, 2, 4, 1}
 * Sorted: {1, 2, 3, 4, 7, 8, 9, 10, 14, 16 }
*/
int main()
{
	unsigned int n;
	printf("Enter Size of Array\n");
	scanf("%d", &n);
	int arr[n];
	takeArrayInput(arr, n);
	heapSortMaxHeap(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);

	return 0;
}
