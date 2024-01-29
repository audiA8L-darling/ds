#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100// Define a structure for the stack
struct Stack {
 int items[MAX_SIZE];
 int top;
};
void initialize(struct Stack* stack) {
 stack->top = -1;
}
int isEmpty(struct Stack* stack) {
 return stack->top == -1;
}
int isFull(struct Stack* stack) {
 return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int value) {
 if (isFull(stack)) {
 printf("Stack is full. Cannot push %d\n", value);
 } else {
 stack->items[++stack->top] = value;
 printf("Pushed %d onto the stack\n", value);
 }
}
int pop(struct Stack* stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty. Cannot pop.\n");
 return -1;
 } else {
 int popped = stack->items[stack->top--];
 printf("Popped %d from the stack\n", popped);
 return popped;
 }
}
void display(struct Stack* stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty.\n");
 } else {
 printf("Stack contents: ");
 for (int i = 0; i <= stack->top; i++) {
 printf("%d ", stack->items[i]);
 }
 printf("\n");
 }
}
int main() {
 struct Stack stack;
 initialize(&stack);
 int choice, value;
 do {
 printf("\nStack Operations Menu:\n");
 printf("1. Push\n");
 printf("2. Pop\n");
 printf("3. Display\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter a value to push: ");
 scanf("%d", &value);
 push(&stack, value);
 break;
 case 2:
 pop(&stack);
 break;
 case 3:
 display(&stack);
 break;
 case 4:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice! Please enter a valid option.\n");
 }
 } while (choice != 4);
 return 0;
}
