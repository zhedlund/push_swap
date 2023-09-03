
// TEST PROGRAMS DOUBLY LINKED LIST

/*
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_stack {
    int data;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;




void print_list(t_stack *stack)
{
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// creates a doubly linked list node by node

int main() {
    t_stack *node1 = (t_stack *)malloc(sizeof(t_stack));
    node1->data = 10;
    node1->prev = NULL;
    node1->next = NULL;

    t_stack *node2 = (t_stack *)malloc(sizeof(t_stack));
    node2->data = 20;
    node2->prev = node1;
    node2->next = NULL;
    node1->next = node2;

    t_stack *node3 = (t_stack *)malloc(sizeof(t_stack));
    node3->data = 30;
    node3->prev = node2;
    node3->next = NULL;
    node2->next = node3;

    t_stack *node4 = (t_stack *)malloc(sizeof(t_stack));
    node4->data = 40;
    node4->prev = node3;
    node4->next = NULL;
    node3->next = node4;

    t_stack *head = node1;  // Head points to the first node


printf("Original stack: ");
    print_list(head);

    swap(&head);

    printf("Stack after swapping first two nodes: ");
    print_list(head);
    
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

*/




// creates a doubly linked list using loop

/*
int main()
{
    t_stack *stack1 = NULL;
    t_stack *stack2 = NULL;

    for (int i = 15; i >= 10; i--) {
        t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = stack1;
        if (stack1)
            stack1->prev = newNode;
        stack1 = newNode;
    }

    for (int i = 15; i >= 10; i--) 
    {
        t_stack *newnode2 = (t_stack *)malloc(sizeof(t_stack));
        newnode2->data = i;
        newnode2->prev = NULL;
        newnode2->next = stack2;
        if (stack2)
            stack2->prev = newnode2;
        stack2 = newnode2;
    }
    print_list(stack1);
    print_list(stack2);
    //pa(&stack1, &stack2);
    pb(&stack2, &stack1);
    pb(&stack2, &stack1);
    print_list(stack1);
    print_list(stack2);

    return (0);
}

*/