//Binary Search Tree traversal using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

int smallest(struct node *root) {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int largest(struct node *root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

struct node *insert(struct node *root, int val) {
    struct node *newnode, *t1, *t2;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(root == NULL)
        root = newnode;
    else {
        t2 = NULL;
        t1 = root;
        while(t1 != NULL) {
            t2 = t1;
            if(val <= t1->data)
                t1 = t1->left;
            else
                t1 = t1->right;
        }
        if(val <= t2->data)
            t2->left = newnode;
        else
            t2->right = newnode;
    }
    return root;
}

struct node *delete(struct node *root, int key) {
    struct node *temp;
    if(root == NULL)
        return root;
        
    if(key > root->data)
        root->right = delete(root->right, key);
    else if(key < root->data)
        root->left = delete(root->left, key);
    else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            int t1 = smallest(root->right);
            root->data = t1;
            root->right = delete(root->right, t1);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if(root == NULL)
        return;
    printf("%d \t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d \t", root->data);
}

int search(struct node* temp, int key) {
    if(temp == NULL)
        return 0;
    else if(key == temp->data)
        return temp->data;
    else if(key < temp->data)
        return search(temp->left, key);
    else
        return search(temp->right, key);
}

int total_nodes(struct node *temp) {
    if(temp != NULL)
        return (total_nodes(temp->left) + total_nodes(temp->right) + 1);
    else
        return 0;
}

int internal_nodes(struct node *temp) {
    if(temp == NULL || (temp->left == NULL) && (temp->right == NULL))
        return 0;
    else
        return (internal_nodes(temp->left) + internal_nodes(temp->right) + 1);
}

int leaf_nodes(struct node *temp) {
    if(temp == NULL)
        return 0;
    else if((temp->left == NULL) && (temp->right == NULL))
        return 1;
    else
        return (leaf_nodes(temp->left) + leaf_nodes(temp->right));
}

int height(struct node *temp) {
    if(temp == NULL)
        return -1;
    else {
        int leftht = height(temp->left);
        int rightht = height(temp->right);
        if(leftht > rightht)
            return (leftht + 1);
        else
            return (rightht + 1);
    }
}

void mirror(struct node* root) {
    if (root == NULL)
        return;
    else {
        struct node* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void main() {
    struct node *root = NULL;
    int choice, a, b, c, p, s, t, u, h, f, g;
    
    while(1) {
        printf("\nOption :- "
               "\n1.Insert an element "
               "\n2.Delete an element "
               "\n3.Inorder Traversal "
               "\n4.Preorder Traversal "
               "\n5.Postorder Traversal "
               "\n6.Search an element "
               "\n7.Number of elements in the tree "
               "\n8.Number of leafs nodes in the tree "
               "\n9.Number of internal nodes in the tree "
               "\n10.Height of the tree "
               "\n11.Largest and Smallest Element "
               "\n12.Mirror "
               "\n13.Exit "
               "\nEnter your choice :- \n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Enter the value to be inserted \n");
                scanf("%d", &a);
                root = insert(root, a);
                printf("The element has been inserted \n");
                break;
                
            case 2: 
                printf("Enter the value to be deleted \n");
                scanf("%d", &b);
                root = delete(root, b);
                printf("The element has been deleted \n");
                break;
                
            case 3: 
                inorder(root);
                break;
                
            case 4: 
                preorder(root);
                break;
                
            case 5: 
                postorder(root);
                break;
                
            case 6: 
                printf("Enter the element to be searched \n");
                scanf("%d", &c);
                p = search(root, c);
                if (p == 0)
                    printf("Element is not present in the tree \n");
                else
                    printf("Element found in the tree \n");
                break;
                
            case 7: 
                s = total_nodes(root);
                printf("The total number of nodes are %d", s);
                break;
                
            case 8: 
                t = leaf_nodes(root);
                printf("The total number of leaf nodes are %d", t);
                break;
                
            case 9: 
                u = internal_nodes(root);
                printf("The total number of internal nodes are %d", u);
                break;
                
            case 10: 
                h = height(root);
                printf("The height of the tree is %d", h);
                break;
                
            case 11: 
                f = smallest(root);
                g = largest(root);
                printf("The smallest element of the tree is %d \nThe largest element of the tree is %d", f, g);
                break;
                
            case 12: 
                mirror(root);
                printf("The tree has been mirrored \n");
                break;
                
            case 13: 
                exit(0);
                
            default: 
                printf("Incorrect choice. Please try again \n");
        }
    }
}
