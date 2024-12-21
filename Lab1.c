#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int stack[MAX];
int top = -1;

void push(int);
void pop();
int isEmpty();
int isFull();
void display();

int main(){

    int choice,data;
    while(1){
        printf("press : 1 , to push element\n");
        printf("press : 2 , to pop element\n");
        printf("press : 3 ,  Display stack elements\n");
        printf("press : 4 , exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 

                printf("Enter value to push : " );
                scanf("%d",&data);
                push(data);
                break;
            case 2: 
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited \n");
                exit(1);
            default : 
                    printf("Invalid option or choice \n");
                    break;
        }

    }


    return 0 ;
}

void push(int data){
    if(isFull()) {
        printf("Stack overflow \n");
    }
    else{
        stack[++top] = data;
        printf("Element pushed to stack \n");
    }
}

void pop(){
    int temp ;
    if(isEmpty()){
         printf("Stack underflow \n");
    }
    else{
        temp = stack[top--];
        printf("Element Popped successfully \n");
    }

}

int isEmpty(){
     
    if(top == -1) return 1;
    else return 0;
}

int isFull(){
    
    if(top == MAX -1 ) return 1;
    else return 0;

}

void display(){
    if(isEmpty()){
         printf("Stack empty \n");
    } 
    else{
        printf("Stack elements : ");
        for (int i =top; i > -1; i--){
            printf("%d ",stack[i]);
        }
          printf("\n");
    }

}

/*
 Output

press : 1 , to push element        
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 1
Enter value to push : 2
Element pushed to stack 
press : 1 , to push element        
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 1
Enter value to push : 3
Element pushed to stack 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 3
Stack elements : 3 2 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 2
Element Popped successfully 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 3
Stack elements : 2 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 2
Element Popped successfully 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 3
Stack empty 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 2
Stack underflow 
press : 1 , to push element
press : 2 , to pop element
press : 3 ,  Display stack elements
press : 4 , exit
Enter your choice : 4
Exited 
*/