//Stack Implementation using Linked-List
#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int val;
    struct node *next;
};

struct node *head;

void main() {
    int choice = 0;
    
    while(1) {
        printf("\n\nChose one from the below options\n");
        printf("\n1.Enter an element\n2.Delete an element\n3.Display\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                push();
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Please Enter valid choice");
            }
        }
    }
}

void push() {
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    
    if(ptr == NULL) {
        printf("Not able to push the element");
    }
    else {
        printf("Enter the value \n");
        scanf("%d", &val);
        
        if(head == NULL) {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        }
        else {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        printf("Item inserted");
    }
}

void pop() {
    int item;
    struct node *ptr;
    
    if(head == NULL) {
        printf("Underflow");
    }
    else {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item deleted");
    }
}

void display() {
    int i;
    struct node *ptr;
    ptr = head;
    
    if(ptr == NULL) {
        printf("Stack is empty\n");
    }
    else {
        printf("The stack elements are\n");
        while(ptr != NULL) {
            printf("|%2d|\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
