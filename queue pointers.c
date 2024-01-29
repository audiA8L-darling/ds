#include <stdio.h>
#include <stdlib.h>
struct QueueNode {
 int data;
 struct QueueNode* next;
};
struct Queue {
 struct QueueNode* front;
 struct QueueNode* rear;
};
void initialize(struct Queue* queue) {
 queue->front = queue->rear = NULL;
}
int isEmpty(struct Queue* queue) {
 return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int value) {
 struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct 
QueueNode));
 if (newNode == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 newNode->data = value;
 newNode->next = NULL;
 if (isEmpty(queue)) {
 queue->front = queue->rear = newNode;
 } else {
 queue->rear->next = newNode;
 queue->rear = newNode;
 }
 printf("Enqueued %d into the queue\n", value);
}
int dequeue(struct Queue* queue) {
 if (isEmpty(queue)) {
 printf("Queue is empty. Cannot dequeue.\n");
 return -1;
 }
 struct QueueNode* temp = queue->front;
 int dequeued = temp->data;
 queue->front = temp->next;
 free(temp);
 if (queue->front == NULL) {
 queue->rear = NULL;
 }
 printf("Dequeued %d from the queue\n", dequeued);
 return dequeued;
 }
void display(struct Queue* queue) {
 if (isEmpty(queue)) {
 printf("Queue is empty.\n");
 } else {
 printf("Queue contents: ");
 struct QueueNode* current = queue->front;
 while (current != NULL) {
 printf("%d, ", current->data);
 current = current->next;
 }
 printf("\n");
 }
}
int main() {
 struct Queue queue;
 initialize(&queue);
 int choice, value;
 do {
 printf("\nQueue Operations Menu:\n");
 printf("1. Enqueue\n");
 printf("2. Dequeue\n");
 printf("3. Display\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter a value to enqueue: ");
 scanf("%d", &value);
 enqueue(&queue, value);
 break;
 case 2:
 dequeue(&queue);
 break;
 case 3:
 display(&queue);
 break;
 case 4:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice! Please enter a valid option.\n");
 }
 } while (choice != 4);
 while (!isEmpty(&queue)) {
 dequeue(&queue);
 }
 return 0;
}
