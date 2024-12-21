#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int data);
void dequeue();
void display();

int main() {
    int choice, data, flag = 1;

    printf("\nQueue Operations using Singly Linked List");
    printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");

    while (flag) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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

void enqueue(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow: The queue is empty.\n");
        return;
    }
    struct node *temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    struct node *ptr = front;
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*
OUTPUT : 


Queue Operations using Singly Linked List
1: Enqueue
2: Dequeue
3: Display
4: Exit

Enter your choice: 3
The queue is empty.

Enter your choice: 2
Underflow: The queue is empty.

Enter your choice: 1
Enter data: 1
Enqueued: 1

Enter your choice: 1
Enter data: 2
Enqueued: 2

Enter your choice: 1
Enter data: 3
Enqueued: 3

Enter your choice: 1
Enter data: 4
Enqueued: 4

Enter your choice: 3
Queue elements: 1 2 3 4 

Enter your choice: 2
Dequeued: 1

Enter your choice: 2
Dequeued: 2

Enter your choice: 2
Dequeued: 3

Enter your choice: 2
Dequeued: 4

Enter your choice: 2
Underflow: The queue is empty.

Enter your choice: 3
The queue is empty.

Enter your choice: 2
Underflow: The queue is empty.

Enter your choice: 4


*/