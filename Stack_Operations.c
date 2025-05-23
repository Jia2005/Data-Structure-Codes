//Performing Stack Operations like Push, Pop, Peak, Display and Size
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max 10

int stack[Max], top = -1;

bool isFull() {
    if (top == Max - 1)
        return true;
    else
        return false;
}

bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}

void Push(int item) {
    if (isFull())
        printf("Stackoverflow");
    else {
        top++;
        stack[top] = item;
        printf("The element has been inserted \n");
    }
}

int Pop() {
    int temp;
    if (isEmpty())
        printf("Stack is Empty \n");
    else {
        temp = stack[top];
        top--;
        return temp;
    }
}

int Peek() {
    if (isEmpty())
        printf("No element present \n");
    else
        return stack[top];
}

void Display() {
    int i;
    if (isEmpty())
        printf("No element present in the stack \n");
    else
        printf("The stack is \n");
    
    for (i = top; i >= 0; i--) {
        printf("| %2d | \n", stack[i]);
    }
}

void Size() {
    printf("The size of the stack is %d \n", top + 1);
    printf("There are more %d spaces left \n", Max - top - 1);
}

void main() {
    int choice = 0, temp = 0, element;
    
    while (1) {
        printf("Enter ur choice from the following \n");
        printf("1-Push \n");
        printf("2-Pop \n");
        printf("3-Peek \n");
        printf("4-Display \n");
        printf("5-Size \n");
        printf("6-EXIT \n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to be added \n");
                scanf("%d", &element);
                Push(element);
                break;
            case 2:
                temp = Pop();
                printf("The element has been removed \n");
                break;
            case 3:
                printf("The top of the element is %d \n", Peek());
                break;
            case 4:
                Display();
                break;
            case 5:
                Size();
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
}
