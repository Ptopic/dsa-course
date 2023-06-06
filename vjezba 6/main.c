#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {

	void* pointer;
	int priority;

} Element;

typedef struct {

	Element* elements;
	int numberOfElements;

} PriorityQueue;


void swapElements(PriorityQueue* priorityQueue, int index1, int index2) {
	Element temp = priorityQueue->elements[index1];
	priorityQueue->elements[index1] = priorityQueue->elements[index2];
	priorityQueue->elements[index2] = temp;
}

void swapElementsPointers(Element* first, Element* second) {
	Element temp = *first;
	*first = *second;
	*second = temp;
}

int getIndexOfLastElement(PriorityQueue* priorityQueue) {
	return priorityQueue->numberOfElements - 1;
}

PriorityQueue* createPriorityQueue() {
	PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	queue->elements = (Element*)malloc(sizeof(Element) * 10000);
	queue->numberOfElements = 0;
	return queue;
}


void addElement(PriorityQueue* priorityQueue, int priority) {
	int index = priorityQueue->numberOfElements++;
	priorityQueue->elements[index].priority = priority;

	fixHeapToTop(priorityQueue, index);
}

int fixHeapToTop(PriorityQueue* priorityQueue, int childIndex) {

	int parentIndex = (childIndex - 1) / 2;

	Element childElement = priorityQueue->elements[childIndex];
	Element parentElement = priorityQueue->elements[parentIndex];

	if (childElement.priority <= parentElement.priority)
		return;

	swapElements(priorityQueue, childIndex, parentIndex);
	fixHeapToTop(priorityQueue, parentIndex);
}

int fixHeapToTopIterative(PriorityQueue* priorityQueue, int childIndex) {

	int parentIndex = (childIndex - 1) / 2;

	Element childElement = priorityQueue->elements[childIndex];
	Element parentElement = priorityQueue->elements[parentIndex];

	while (childElement.priority > parentElement.priority) {

		swapElements(priorityQueue, childIndex, parentIndex);

		childIndex = parentIndex;
		parentIndex = (childIndex - 1) / 2;

		childElement = priorityQueue->elements[childIndex];
		parentElement = priorityQueue->elements[parentIndex];
	}
}


Element removeMaxElement(PriorityQueue* priorityQueue) {
	if (priorityQueue->numberOfElements <= 0)
		return;

	Element topElement = priorityQueue->elements[0];
	Element lastElement = priorityQueue->elements[getIndexOfLastElement(priorityQueue)];

	priorityQueue->elements[0] = lastElement;
	priorityQueue->elements[getIndexOfLastElement(priorityQueue)].priority = -842150451;
	priorityQueue->numberOfElements--;

	fixHeapToTop(priorityQueue, 0);

	return topElement;

}

void printPriorityQueueRow(PriorityQueue* priorityQueue) {

	for (int i = 0; i < priorityQueue->numberOfElements; ++i)
		printf("%d ", priorityQueue->elements[i].priority);

	printf("\n");
}


void main() {

	PriorityQueue* queue = createPriorityQueue();

	printf("Num of elements : %d \n", queue->numberOfElements);

	int arr[] = { 3 , 5 , 8 };
	int arr2[] = { 3 , 3 , 3 , 3 };
	int arr3[] = { 9 , 2 , 5 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		addElement(queue, arr[i]);

	printf("Num of elements : %d \n", queue->numberOfElements);

	printPriorityQueueRow(queue);

	removeMaxElement(queue);

	printPriorityQueueRow(queue);

	removeMaxElement(queue);

	printPriorityQueueRow(queue);

	removeMaxElement(queue);

	printPriorityQueueRow(queue);


	free(queue);
}