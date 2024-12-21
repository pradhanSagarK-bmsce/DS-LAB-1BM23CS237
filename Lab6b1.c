#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node* push(struct node*, int);
struct node* delete(struct node*);
void display(struct node*);

int main() {
    int choice;
    printf("\n1: Insert\n2: Delete\n3: Display\n4: Exit\n");
    int flag = 1;
    while (flag) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            }
            case 2: 
                top = delete(top);
                break;
            case 3: 
                display(top);
                break;
            case 4: 
                flag = 0;
                break;
            default: 
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

struct node* push(struct node* top, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return top;
    }
    new_node->data = data;
    new_node->next = top;
    top = new_node;
    return top;
}

struct node* delete(struct node* top) {
    if (top == NULL) {
        printf("Underflow: The stack is empty.\n");
        return top;
    }
    struct node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(struct node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    struct node* ptr = top;
    printf("Stack elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*
OUTPUT : 

1: Insert
2: Delete
3: Display
4: Exit

Enter your choice: 3
The stack is empty.

Enter your choice: 2
Underflow: The stack is empty.

Enter your choice: 1
Enter data: 2

Enter your choice: 1
Enter data: 3

Enter your choice: 1
Enter data: 4

Enter your choice: 3
Stack elements: 4 3 2 

Enter your choice: 2

Enter your choice: 2

Enter your choice: 2

Enter your choice: 2
Underflow: The stack is empty.

Enter your choice: 3
The stack is empty.

Enter your choice: 4

*/