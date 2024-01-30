#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct STACK {
    int stack_arr[STACK_SIZE];
    int top;
};
void push(struct STACK *stack, int val){
    stack->stack_arr[++stack->top] = val;
}

int pop(struct STACK *stack){
    return stack->stack_arr[stack->top--];
}

int main(int argc, char *argv[]) {
    struct STACK *stackptr, stack;
    stackptr = &stack;
    stackptr->top = -1;

    push(stackptr, 5);
    push(stackptr,6);
    pop(stackptr);

    return EXIT_SUCCESS;
}