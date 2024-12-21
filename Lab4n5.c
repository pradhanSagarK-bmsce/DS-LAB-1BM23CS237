#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_atPos(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_atPos(struct node*);

int main() {
    int choice;
    printf("\n1: Create LL\n2: Display\n3: Insert at Beginning\n4: Insert at End\n5: Insert at Position\n6: Delete from Beginning\n7: Delete from End\n8: Delete from Position\n9: Exit\n");
    int flag = 1;
    while (flag) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: start = create_ll(start); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_atPos(start); break;
            case 6: start = delete_beg(start); break;
            case 7: start = delete_end(start); break;
            case 8: start = delete_atPos(start); break;
            case 9: flag = 0; break;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    while(num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL) {
            new_node->next = NULL;
            start = new_node;
        } else {
            ptr = start;
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("Enter num: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    while (ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    if(start == NULL) {
        start = new_node;
    } else {
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

struct node *insert_atPos(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, indx = 0, pos;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 0) {
        printf("Invalid position.\n");
        return start;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;

    if(pos == 0) {
        new_node->next = start;
        start = new_node;
        return start;
    }

    while(ptr != NULL && indx < pos) {
        preptr = ptr;
        ptr = ptr->next;
        indx++;
    }

    if(ptr == NULL && indx < pos) {
        printf("Position is greater than the length of the list.\n");
        free(new_node);
        return start;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_atPos(struct node *start) {
    struct node *ptr, *preptr;
    int indx = 0, pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 0 || start == NULL) {
        printf("Invalid position or empty list.\n");
        return start;
    }

    ptr = start;
    preptr = NULL;

    if(pos == 0) {
        start = start->next;
        free(ptr);
        return start;
    }

    while(ptr != NULL && indx < pos) {
        preptr = ptr;
        ptr = ptr->next;
        indx++;
    }

    if(ptr == NULL) {
        printf("Position is greater than the length of the list.\n");
        return start;
    }

    preptr->next = ptr->next;
    free(ptr);

    return start;
}


/*
OUTPUT :


1: Create LL
2: Display
3: Insert at Beginning
4: Insert at End
5: Insert at Position
6: Delete from Beginning
7: Delete from End
8: Delete from Position
9: Exit

Enter your choice: 1
Enter num: 2
Enter num: 3
Enter num: 4
Enter num: 5
Enter num: 6
Enter num: -1

Enter your choice: 2
         2       3       4       5       6
Enter your choice: 7

Enter your choice: 2
         2       3       4       5
Enter your choice: 6

Enter your choice: 2
         3       4       5
Enter your choice: 3      
Enter num: 2

Enter your choice: 2
         2       3       4       5
Enter your choice: 4
Enter num: 6

Enter your choice: 2
         2       3       4       5       6
Enter your choice: 5
Enter num: 0
Enter position: 2

Enter your choice: 2
         2       3       0       4       5       6
Enter your choice: 8
Enter position: 2

Enter your choice: 2
         2       3       4       5       6
Enter your choice: 9

*/