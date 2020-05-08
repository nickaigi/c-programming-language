#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* nalloc(void);
void push(int, struct node**);
void pop(struct node**);
void top(struct node*);

int main(){
    struct node* root = nalloc();
    push(1, &root);
    top(root);
    push(2, &root);
    top(root);
    pop(&root);
    top(root);

    return 0;
}

void push(int data, struct node** stack){
    struct node* new_node = nalloc();

    new_node->data = data;
    new_node->next = *stack;
    (*stack) = new_node;
}

void pop(struct node** stack){
    if (*stack != NULL){
        printf("poped: %d\n", (*stack)->data);
        struct node* tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    } else
        printf("The Stack is empty");
}

/* top: display element at the top of the stack */
void top(struct node* stack){
    if (stack != NULL){
        printf("top: %d\n", stack->data);
    } else
        printf("stack is empty\n");
}

struct node* nalloc(void){
    return (struct node *) malloc(sizeof(struct node));
}

void stackprint(struct node *head){
    struct node* current = head;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}
