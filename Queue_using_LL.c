//Queue Implementation using Linked-List
#include<stdio.h> 
#include<stdlib.h> 

struct node {
    int data; 
    struct node *next; 
}; 

struct node *front;
struct node *rear;

void insert();
void delete();
void display();

void main() {
    int choice; 
    while(1) {
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n"); 
        printf("\nEnter your choice \n"); 
        scanf("%d", &choice); 
        
        switch(choice) { 
            case 1: 
                insert(); 
                break; 
            case 2: 
                delete(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                exit(0); 
                break; 
            default: 
                printf("\nPlease enter a valid choice.\n"); 
        } 
    } 
} 

void insert() {
    struct node *ptr; 
    int item; 
    
    ptr = (struct node *) malloc(sizeof(struct node)); 
    if(ptr == NULL) { 
        printf("\nOverflow\n"); 
        return; 
    } else { 
        printf("\nEnter value\n"); 
        scanf("%d", &item); 
        ptr->data = item; 
        
        if(front == NULL) { 
            front = ptr; 
            rear = ptr; 
            front->next = NULL; 
            rear->next = NULL; 
        } else { 
            rear->next = ptr; 
            rear = ptr; 
            rear->next = NULL; 
        } 
    } 
} 

void delete() {
    struct node *ptr; 
    if(front == NULL) { 
        printf("\nUnderflow\n"); 
        return; 
    } else { 
        ptr = front; 
        front = front->next; 
        free(ptr); 
    } 
} 

void display() {
    struct node *ptr; 
    ptr = front; 
    
    if(front == NULL) { 
        printf("\nEmpty queue\n"); 
    } else { 
        printf("\nThe queue is\n"); 
        while(ptr != NULL) { 
            printf("%d\t", ptr->data); 
            ptr = ptr->next; 
        } 
    } 
}
