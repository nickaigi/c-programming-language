#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* nalloc(void);
void push(int, struct node**);
void pop(struct node**);
void peak(struct node*);
void stackprint(struct node**);

int main(){
    struct node* top = nalloc();
    int c;
    for(c = 0; c < 10; c++)
        push(c, &top);

    printf("Peak the top of the stack: ");
    peak(top);
    printf("Print the entire stack\n");
    stackprint(&top);
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
void peak(struct node* stack){
    if (stack != NULL){
        printf("top: %d\n", stack->data);
    } else
        printf("stack is empty\n");
}

struct node* nalloc(void){
    return (struct node *) malloc(sizeof(struct node));
}

/* stackprint: print entire content of stack 
 * has an error: there a zero at the bottom of the stack, where does that come
 * from??
 */
void stackprint(struct node** head){
    struct node* current = *head;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}
