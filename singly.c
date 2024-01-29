#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 newNode->next = head;
 return newNode;
 }
struct Node* deleteNode(struct Node* head, int key) {
 struct Node* current = head;
 struct Node* prev = NULL;
 if (current != NULL && current->data == key) {
 head = current->next;
 free(current);
 return head;
 }
 while (current != NULL && current->data != key) {
 prev = current;
 current = current->next;
 }
 if (current == NULL) {
 printf("Key not found in the list\n");
 return head;
 }
 prev->next = current->next;
 free(current);
 return head;
}
void traverse(struct Node* head) {
 struct Node* current = head;
 printf("Linked List: ");
 while (current != NULL) {
 printf("%d -> ", current->data);
 current = current->next;
 }
 printf("NULL\n");
}
int main() {
 struct Node* head = NULL;
 int choice, data, key;
 do {
 printf("\nSingly Linked List Operations Menu:\n");
 printf("1. Create a linked list\n");
 printf("2. Insert at the beginning\n");
 printf("3. Delete a node\n");
 printf("4. Traverse the list\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data to create a node: ");
 scanf("%d", &data);
 head = createNode(data);
 break;
 case 2:
 printf("Enter data to insert at the beginning: ");
 scanf("%d", &data);
 head = insertAtBeginning(head, data);
 break;
 case 3:
 printf("Enter the value to delete: ");
 scanf("%d", &key);
 head = deleteNode(head, key);
 break;
 case 4:
 traverse(head);
 break;
 case 5:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice! Please enter a valid option.\n");
 }
 } while (choice != 5);
 return 0;
}
