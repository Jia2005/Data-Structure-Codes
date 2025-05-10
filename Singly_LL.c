//Singly Linked-List 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_cll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    
    printf("\nEnter –1 to end");
    printf("\nEnter the data : ");
    scanf("%d", &num);
    
    while(num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        
        if(start == NULL) {
            new_node->next = new_node;
            start = new_node;
        } else { 
            ptr = start;
            while(ptr->next != start) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *InsertAtBeginning(struct node *start, int value) {
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    
    if(start == NULL) {
        new_node->next = new_node;
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;
        
        new_node->next = start;
        ptr->next = new_node;
        start = new_node;
    }
    return start;
}

struct node *InsertAtEnd(struct node *start, int value) {
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    
    if(start == NULL) {
        new_node->next = new_node;
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;
        
        ptr->next = new_node;
        new_node->next = start;
    }
    return start;
}

struct node *InsertAfter(struct node *start, int value, int after_value) {
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    
    ptr = start;
    do {
        if(ptr->data == after_value) {
            new_node->next = ptr->next;
            ptr->next = new_node;
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    
    printf("\nValue %d not found in the list", after_value);
    free(new_node);
    return start;
}

struct node *InsertBefore(struct node *start, int value, int before_value) {
    struct node *new_node, *ptr, *preptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    
    if(start == NULL) {
        printf("\nList is empty");
        free(new_node);
        return start;
    }
    
    // If the first node contains the before_value
    if(start->data == before_value) {
        return InsertAtBeginning(start, value);
    }
    
    ptr = start;
    preptr = ptr;
    
    while(preptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
        if(ptr->data == before_value) {
            new_node->next = ptr;
            preptr->next = new_node;
            return start;
        }
    }
    
    printf("\nValue %d not found in the list", before_value);
    free(new_node);
    return start;
}

struct node *DelBeginning(struct node *start) {
    struct node *ptr;
    
    if(start == NULL) {
        printf("\nUnderflow");
        return NULL;
    }
    
    if(start->next == start) {
        free(start);
        return NULL;
    }
    
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
        
    ptr->next = start->next;
    ptr = start;
    start = start->next;
    free(ptr);
    
    return start;
}

struct node *DelEnd(struct node *start) {
    struct node *ptr, *preptr;
    
    if(start == NULL) {
        printf("\nUnderflow");
        return NULL;
    }
    
    if(start->next == start) {
        free(start);
        return NULL;
    }
    
    ptr = start;
    while(ptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = start;
    free(ptr);
    
    return start;
}

struct node *DelAfter(struct node *start, int value) {
    struct node *ptr, *temp;
    
    if(start == NULL) {
        printf("\nUnderflow");
        return NULL;
    }
    
    ptr = start;
    do {
        if(ptr->data == value) {
            temp = ptr->next;
            
            // If deleting the last node
            if(temp == start) {
                ptr->next = start->next;
                start = start->next;
            } else {
                ptr->next = temp->next;
            }
            
            free(temp);
            return start;
        }
        ptr = ptr->next;
    } while(ptr != start);
    
    printf("\nValue %d not found in the list", value);
    return start;
}

struct node *Traversal(struct node *start) {
    struct node *ptr;
    
    if(start == NULL) {
        printf("\nList is empty");
        return start;
    }
    
    printf("\nElements in the circular linked list: ");
    ptr = start;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);
    
    return start;
}

void printReverse(struct node *start, struct node *current) {
    if(current->next == start) {
        printf("%d ", current->data);
        return;
    }
    
    printReverse(start, current->next);
    printf("%d ", current->data);
}

struct node *Reverse(struct node *start) {
    struct node *prev, *current, *next, *last;
    
    if(start == NULL) {
        printf("\nList is empty");
        return NULL;
    }
    
    last = start;
    prev = start;
    current = start->next;
    start = start->next;
    
    while(start != last) {
        start = start->next;
        current->next = prev;
        prev = current;
        current = start;
    }
    
    current->next = prev;
    start = prev;
    
    return start;
}

int Size(struct node *start) {
    struct node *ptr;
    int count = 0;
    
    if(start == NULL)
        return 0;
    
    ptr = start;
    do {
        count++;
        ptr = ptr->next;
    } while(ptr != start);
    
    return count;
}

struct node *delete_list(struct node *start) {
    struct node *ptr, *temp;
    
    if(start == NULL) {
        printf("\nList is already empty");
        return NULL;
    }
    
    ptr = start;
    do {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    } while(ptr != start);
    
    return NULL;
}

int main() {
    int option, value, after_value, before_value, size;
    
    while(1) {
        printf("\n\n**MAIN MENU**");
        printf("\n1: Create a list");
        printf("\n2: Add a node at the beginning");
        printf("\n3: Add a node at the end");
        printf("\n4: Insert after a specific node");
        printf("\n5: Insert before a specific node");
        printf("\n6: Delete a node from the beginning");
        printf("\n7: Delete a node from the end");
        printf("\n8: Delete a node after a given node");
        printf("\n9: Forward Traversal");
        printf("\n10: Reverse Traversal");
        printf("\n11: Reversing the linked-list");
        printf("\n12: Size of the linked-list");
        printf("\n13: Delete the entire list");
        printf("\n14: EXIT");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                start = create_cll(start);
                printf("\nCircular linked-list is created");
                break;
                
            case 2:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &value);
                start = InsertAtBeginning(start, value);
                break;
                
            case 3:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &value);
                start = InsertAtEnd(start, value);
                break;
                
            case 4:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &value);
                printf("\nEnter the value after which the data has to be inserted: ");
                scanf("%d", &after_value);
                start = InsertAfter(start, value, after_value);
                break;
                
            case 5:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &value);
                printf("\nEnter the value before which the data has to be inserted: ");
                scanf("%d", &before_value);
                start = InsertBefore(start, value, before_value);
                break;
                
            case 6:
                start = DelBeginning(start);
                printf("\nNode deleted from the beginning");
                break;
                
            case 7:
                start = DelEnd(start);
                printf("\nNode deleted from the end");
                break;
                
            case 8:
                printf("\nEnter the value after which the node has to be deleted: ");
                scanf("%d", &value);
                start = DelAfter(start, value);
                break;
                
            case 9:
                start = Traversal(start);
                break;
                
            case 10:
                if(start != NULL) {
                    printf("\nElements in reverse order: ");
                    printReverse(start, start);
                } else {
                    printf("\nList is empty");
                }
                break;
                
            case 11:
                start = Reverse(start);
                printf("\nLinked list reversed");
                break;
                
            case 12:
                size = Size(start);
                printf("\nThe number of elements in the linked-list is %d", size);
                break;
                
            case 13:
                start = delete_list(start);
                printf("\nEntire list deleted");
                break;
                
            case 14:
                printf("\nExiting the program");
                exit(0);
                
            default:
                printf("\nIncorrect Choice. Please Try Again");
        }
    }
    
    return 0;
}
