#include "brackets.h"
#include <stdlib.h>
#include <string.h>

static Result stack_resize(CharStack* s, size_t new_capacity) {
    if (!s || new_capacity <= s->capacity) return ERROR_INVALID_INPUT;
    
    char* new_data = realloc(s->data, new_capacity);
    if (!new_data) return ERROR_MEMORY;
    
    s->data = new_data;
    s->capacity = new_capacity;
    return SUCCESS;
}

Result stack_init(CharStack* s, size_t initial_capacity) {
    if (!s || initial_capacity == 0) return ERROR_INVALID_INPUT;
    
    s->size = 0;
    s->capacity = initial_capacity;
    s->data = malloc(initial_capacity);
    
    return s->data ? SUCCESS : ERROR_MEMORY;
}

void stack_free(CharStack* s) {
    if (s) {
        free(s->data);
        s->data = NULL;
        s->capacity = s->size = 0;
    }
}

Result stack_push(CharStack* s, char el) {
    if (!s) return ERROR_INVALID_INPUT;
    
    if (s->size == s->capacity) {
        size_t new_cap = s->capacity ? s->capacity * 2 : STACK_INIT_SIZE;
        Result res = stack_resize(s, new_cap);
        if (res != SUCCESS) return res;
    }
    
    s->data[s->size++] = el;
    return SUCCESS;
}

Result stack_pop(CharStack* s, char* res) {
    if (!s || !res || s->size == 0) return ERROR_INVALID_INPUT;
    
    *res = s->data[--s->size];
    return SUCCESS;
}

int stack_empty(const CharStack* s) {
    return s ? s->size == 0 : 1;
}

static int is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int check_balanced(const char* str) {
    if (!str) return NOT_BALANCED;
    
    CharStack stack;
    if (stack_init(&stack, STACK_INIT_SIZE) != SUCCESS) 
        return NOT_BALANCED;
    
    int balanced = BALANCED;
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (strchr("([{<", c)) {
            if (stack_push(&stack, c) != SUCCESS) {
                balanced = NOT_BALANCED;
                break;
            }
        } 
        else if (strchr(")]}>", c)) {
            char top;
            if (stack_pop(&stack, &top) != SUCCESS || 
                !is_matching_pair(top, c)) {
                balanced = NOT_BALANCED;
                break;
            }
        }
    }
    
    if (balanced == BALANCED && !stack_empty(&stack)) 
        balanced = NOT_BALANCED;
    
    stack_free(&stack);
    return balanced;
}

const char* get_result_msg(int code) {
    return code == BALANCED ? "Balanced" : "Not balanced";
}