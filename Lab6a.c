#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
void create_ll();
struct node *display(struct node*);
struct node *sort(struct node*);
struct node *concat(struct node*, struct node*);
struct node *reverse(struct node*);

int main() {
    int choice;
    printf("\n1: Create LL\n2: Display\n3: Sort\n4: Concat\n5: Reverse\n6: Exit\n");
    int flag = 1;
    while (flag) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_ll();  // Create both lists
                break;
            case 2: {
                int c;
                printf("Enter list 1 or 2: ");
                scanf("%d", &c);
                if (c == 1) {
                    head1 = display(head1); 
                } else if (c == 2) {
                    head2 = display(head2); 
                } else {
                    printf("Invalid list choice.\n");
                }
                break;
            }
            case 3: {
                int c;
                printf("Enter list 1 or 2: ");
                scanf("%d", &c);
                if (c == 1) {
                    head1 = sort(head1); 
                } else if (c == 2) {
                    head2 = sort(head2); 
                } else {
                    printf("Invalid list choice.\n");
                }
                break;
            }
            case 4: head1 = concat(head1, head2); break;
            case 5: head1 = reverse(head1); break;
            case 6: flag = 0; break;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void create_ll() {
    struct node *new_node, *ptr;
    int num;

    printf("Enter elements for list 1 (enter -1 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (head1 == NULL) {
            head1 = new_node;
        } else {
            ptr = head1;
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = new_node;
        }
    }

    printf("Enter elements for list 2 (enter -1 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (head2 == NULL) {
            head2 = new_node;
        } else {
            ptr = head2;
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = new_node;
        }
    }
}

struct node *display(struct node *head) {
    struct node *ptr = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    printf("List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}

struct node *sort(struct node *head) {
    struct node *ptr, *cptr;
    int temp;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        for (cptr = ptr->next; cptr != NULL; cptr = cptr->next) {
            if (ptr->data > cptr->data) {
                temp = ptr->data;
                ptr->data = cptr->data;
                cptr->data = temp;
            }
        }
    }
    return head;
}

struct node *concat(struct node *head1, struct node *head2) {
    struct node *ptr = head1;
    if (head1 == NULL) return head2;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = head2;
    return head1;
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/*
OUTPUT : 

1: Create LL
2: Display
3: Sort
4: Concat
5: Reverse
6: Exit

Enter your choice: 1
Enter elements for list 1 (enter -1 to stop): 1 4 3 5 -1
Enter elements for list 2 (enter -1 to stop): 6 2 7 -1

Enter your choice: 2
Enter list 1 or 2: 1
List: 1 4 3 5 

Enter your choice: 2
Enter list 1 or 2: 2
List: 6 2 7 

Enter your choice: 3
Enter list 1 or 2: 1

Enter your choice: 2
Enter list 1 or 2: 1
List: 1 3 4 5 

Enter your choice: 3
Enter list 1 or 2: 2

Enter your choice: 2
Enter list 1 or 2: 2
List: 2 6 7 

Enter your choice: 4

Enter your choice: 2
Enter list 1 or 2: 1
List: 1 3 4 5 2 6 7 

Enter your choice: 5

Enter your choice: 2
Enter list 1 or 2: 1
List: 7 6 2 5 4 3 1  

Enter your choice: 6

*/