//Hash Table Implementation with Linear Probing
#include <stdio.h>
#include <stdlib.h>

#define max 10

int h[max] = {0};  // Initialize all elements to 0 instead of NULL

void insert() {
    int key, index, i, hkey;
    
    printf("\nEnter a value to insert into hash table\n");
    scanf("%d", &key);
    
    hkey = key % max;
    
    for(i = 0; i < max; i++) {
        index = (hkey + i) % max;
        if(h[index] == 0) {
            h[index] = key;
            break;
        }
    }
    
    if(i == max)
        printf("\nElement cannot be inserted\n");
}

void search() {
    int key, index, i, hkey;
    
    printf("\nEnter the element to be searched\n");
    scanf("%d", &key);
    
    hkey = key % max;
    
    for(i = 0; i < max; i++) {
        index = (hkey + i) % max;
        if(h[index] == key) {
            printf("Value is found at index %d", index);
            break;
        }
    }
    
    if(i == max)
        printf("\nValue is not found\n");
}

void display() {
    int i;
    
    printf("\nElements in the hash table are \n");
    for(i = 0; i < max; i++)
        printf("\nAt index %d \t value = %d", i, h[i]);
}

int main() {
    int opt;
    
    while(1) {
        printf("\nPress \n1. Insert\n2. Display \n3. Search \n4. Exit \n");
        scanf("%d", &opt);
        
        switch(opt) {
            case 1:
                insert();
                break;
                
            case 2:
                display();
                break;
                
            case 3:
                search();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Wrong choice. Please try again. \n");
        }
    }
    
    return 0;
}
