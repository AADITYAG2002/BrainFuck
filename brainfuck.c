#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define STACK_SIZE 5
#define BUFFER_SIZE 1024
#define MEMORY_SIZE 10

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

void  interpreter(char *program){
    int inst_ptr = 0;
    int mem_ptr = 0;
    int memory[MEMORY_SIZE] = {0};
    struct STACK *stackptr, stack;
    stackptr = &stack;
    stackptr->top = -1;
    
    for(;program[inst_ptr] != '\0';++inst_ptr){
        switch ((int)program[inst_ptr]){
            case 62: // > increment mem ptr
                mem_ptr++;
                break;
            case 60: // < decrement mem ptr
                mem_ptr--;
                break;
            case 43: // + increment mem block
                memory[mem_ptr]++;
                break;
            case 45: // - decrement mem block
                memory[mem_ptr]--;
                break;
            case 46: // . output curr mem to stdio
                printf("%i",  memory[mem_ptr]);
                fflush(stdout);
                break;
            case 44: // , input to curr mem from stdio
                char temp;
                scanf("%c", &temp);
                memory[mem_ptr] = (int)temp;
                fflush(stdin);
                break;
            case 91: // [ loop begin
                // if (memory[mem_ptr]){
                    
                // }
                push(stackptr, inst_ptr);
                break;
            case 93: // ] loop end
                if (memory[mem_ptr]){
                    inst_ptr = stackptr->stack_arr[stackptr->top]-1;
                    break;
                }
                (void)pop(stackptr);
                break;         
            default:
                break;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Incorrect arguents given \n");
        printf("Usage: ./brainfuck [program file]\n");
        return EXIT_FAILURE;
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("file not found \n");
        printf("Usage: ./brainfuck [program file]\n");
        return EXIT_FAILURE;
    }
    if(fgetc(fp) == EOF){
        printf("File Empty \n");
        return EXIT_FAILURE;
    }
    else{
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, fp);
        interpreter(buffer);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}