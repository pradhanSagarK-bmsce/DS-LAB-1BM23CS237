#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void insert(int);
int delete();
void display();

int main() {

    int choice;
    printf("1 : insert \n");
    printf("2 : delete \n");
    printf("3 : display \n");
    printf("4 : exit \n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            }
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid element\n");
                break;
        }
    }
    return 0;
}

void insert(int value) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = value;
    } else {
        if (rear >= MAX - 1) {
            printf("Overflow\n");
            return;
        } else {
            rear++;
            queue[rear] = value;
        }
    }
}

int delete() {
    if (front == -1 && rear == -1) {
        printf("Empty, Underflow \n");
        return -1;
    } else {
        int deleted = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        printf("Deleted %d\n", deleted);
        return deleted;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Empty, Underflow \n");
        return;
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

/*
Output

1 : insert 
2 : delete    
3 : display   
4 : exit      
Enter choice: 2
Empty, Underflow 
Enter choice: 3  
Empty, Underflow 
Enter choice: 1
Enter value: 2
Enter choice: 1
Enter value: 3
Enter choice: 1
Enter value: 4
Enter choice: 1
Enter value: 5
Overflow
Enter choice: 3
2 3 4 
Enter choice: 2
Deleted 2
Enter choice: 2
Deleted 3
Enter choice: 2
Deleted 4
Enter choice: 2
Empty, Underflow 
Enter choice: 3
Empty, Underflow 
Enter choice: 4
Exiting...



*/