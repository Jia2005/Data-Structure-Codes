//Linear Queue Implementation in C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max 10

int Q[Max], rear = -1, front = -1;

bool isEmpty() {
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

bool isFull() {
    if (rear == Max - 1)
        return true;
    else
        return false;
}

void Enqueue(int item) {
    if (isFull())
        printf("The queue is Full\n");
    else if (isEmpty())
        rear = front = 0;
    else
        rear = rear + 1;
    Q[rear] = item;
}

void Dequeue() {
    int temp;
    if (isEmpty())
        printf("Queue is Empty \n");
    else {
        temp = Q[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
        printf("The element deleted is %d \n", temp);
    }
}

void Display() {
    int i;
    if (isEmpty())
        printf("The queue is Empty \n");
    else {
        printf("The queue is \n");
        for (i = front; i <= rear; i++)
            printf("%d ", Q[i]);
    }
    printf("\n");
}

void Peek() {
    if (isEmpty())
        printf("The queue is Empty \n");
    else
        printf("The value of the foremost element is %d \n", Q[front]);
}

void main() {
    int n, item;
    while (1) {
        printf("Enter the operation you wanna perform on the queue \n");
        printf("1 for Insertion of an element \n");
        printf("2 for Deleting an element \n");
        printf("3 for Displaying the elements present in the queue \n");
        printf("4 for Displaying the foremost element in the queue \n");
        printf("5 to Exit \n");
        scanf("%d", &n);
        
        switch (n) {
            case 1:
                printf("Enter the element to be inserted \n");
                scanf("%d", &item);
                Enqueue(item);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                Peek();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Incorrect choice\n");
        }
    }
}
