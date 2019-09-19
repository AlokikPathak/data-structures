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
 * Name: minHeapify()
 * Purpose: Min-heapify the given root of sub-tree as array 
 * @param: int* arr, pointer to heap array
 * @param: unsigned int size, stores size of heap array
 * @param: unsigned int nodeIndex, contains index of root node of sub-tree needed to be mix-heap
 * @return: void
 * @complexity: O(logN) i.e. logrithimic time
*/
void minHeapify(int *arr, int size, int nodeIndex)
{

	int left = (2 * nodeIndex) + 1;  // left child Node index( since array is from 0 so +1)
	int right = (2 * nodeIndex) + 2; // right child Node index
	int smallest = nodeIndex;		 // initialize as root node

	if (left < size && arr[left] < arr[smallest])
		smallest = left;
	if (right < size && arr[right] < arr[smallest])
		smallest = right;

	// largest in not root Node index(i.e. modified)
	if (smallest != nodeIndex)
	{
		// swapping Root Node with child having smallest(min) value & build Min Heap Sub-tree
		swapTwoNum(&arr[nodeIndex], &arr[smallest]);
		// recursively MinHeapify the new subtree formed after swap
		minHeapify(arr, size, smallest);
	}
}

/**
 * Name: buildMinHeap()
 * Purpose: Build Min heap out of an array visualized as Heap
 * @param: int arr[]
 * @param: int n, size of array
 * @return: void
 * @complexity : O(N) (min_heapify complexity: O(logN) and total n/2 steps so N constant)
 * If array is visualized as nearly Complete Binary Tree, all the elements after n/2 to n are leaves
 * In heaps, the leaves are automatically a Min Heap, since they don't have child
 * 
*/
void buildMinHeap(int *arr, int n)
{
	int i;
	for (i = (n / 2) - 1; i >= 0; i--)
		minHeapify(arr, n, i);
}

/**
 * Name: main()
 * Pupose: Starts execution of program
 * @return: int
 * ex. n = 6, arr[n]= {18, 17, 9, 2, 6, -10}
 * Min_Heap: {18, 17, 9, 2, 6, -10}
*/
int main()
{
	unsigned int n;
	printf("Enter Size of Array\n");
	scanf("%d", &n);
	int arr[n];
	takeArrayInput(arr, n);
	buildMinHeap(arr, n);
	printf("Min Heap: \n");
	printArray(arr, n);

	return 0;
}
