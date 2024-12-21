#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_before(struct node *);
struct node *delete_node(struct node *);

int main()
{
    int choice, flag = 1;
    printf("1.Create DLL \n2.Insert before \n3. Delete Node\n4. Display\n5.Exit\n");

    while (flag)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_ll(start);
            break;
        case 2:
            start = insert_before(start);
            break;
        case 3:
        start=delete_node(start);
        break;
        case 4:
            start = display(start);
            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int number;
    printf("enter -1 to end \n");
    printf("enter the data:");
    scanf("%d", &number);
    while (number != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = number;
        if (start == NULL)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("enter the data:");
        scanf("%d", &number);
    }
    return start;
}


struct node* insert_before(struct node *start) {
    int num, value;
    printf("Enter Number to insert Before\n");
    scanf("%d", &num);
    printf("Enter value to insert\n");
    scanf("%d", &value);

    struct node *ptr = start;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    if (start == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    }

    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with value %d not found in the list.\n", num);
        free(new_node);
        return start;
    }

    if (ptr == start) {
        new_node->next = start;
        new_node->prev = NULL;
        start->prev = new_node;
        return new_node;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return start;
}



struct node *delete_node(struct node *start) {
    struct node *ptr, *temp;
    int val;
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the data to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value not found in the list.\n");
        return start;
    }
    if (ptr == start) {
        start = start->next;
        if (start != NULL) start->prev = NULL;
        free(ptr);
    } else {
        ptr->prev->next = ptr->next;
        if (ptr->next != NULL) ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

/*

OUTPUT : 

1.Create DLL 
2.Insert before
3. Delete Node
4. Display
5.Exit
Enter choice: 1
enter -1 to end 
enter the data:1
enter the data:2
enter the data:3
enter the data:4
enter the data:-1
Enter choice: 4
 1 2 3 4
Enter choice: 3
Enter the data to be deleted: 2
Enter choice: 4
 1 3 4
Enter choice: 3
Enter the data to be deleted: 4
Enter choice: 4
 1 3
Enter choice: 3
Enter the data to be deleted: 1
Enter choice: 4
 3
Enter choice: 2
Enter Number to insert Before
1
Enter value to insert
2
Node with value 1 not found in the list.
Enter choice: 2
Enter Number to insert Before
3
Enter value to insert
1
Enter choice: 4
 1 3
Enter choice: 5



*/