#include<stdio.h>
#include<stdlib.h>

void takeArrayInput(int* arr, unsigned int size) {
  unsigned int i;	
  for(i=0; i<size; i++) {
	scanf("%d", &arr[i]); 
  }
}

void printArray(int arr[], unsigned int size) {
  unsigned int i;	
  for(i=0; i<size; i++) {
	printf("%d ", arr[i]);
  }
}

int main() {
	
	unsigned int n;
	printf("Enter Size of Array\n");
	scanf("%d", &n);
	int arr[n];
	takeArrayInput(arr, n);
	printArray(arr, n);

	return 0;
	
}
