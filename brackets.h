#ifndef BRACKETS_H
#define BRACKETS_H

#include <stddef.h>

typedef enum {
    SUCCESS = 0,
    ERROR_INVALID_INPUT = 1,
    ERROR_MEMORY = 2
} Result;

#define STACK_INIT_SIZE 10
#define NOT_BALANCED 0
#define BALANCED 1

typedef struct {
    char* data;
    size_t size;
    size_t capacity;
} CharStack;

Result stack_init(CharStack* s, size_t initial_capacity);
void stack_free(CharStack* s);
Result stack_push(CharStack* s, char el);
Result stack_pop(CharStack* s, char* res);
int stack_empty(const CharStack* s);

int check_balanced(const char* str);
const char* get_result_msg(int code);

#endif