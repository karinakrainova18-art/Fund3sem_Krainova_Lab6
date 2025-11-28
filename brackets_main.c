#include "brackets.h"
#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter string to check brackets: ");
    char input[256];
    
    if (fgets(input, sizeof(input), stdin)) {
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') 
            input[len-1] = '\0';
            
        int result = check_balanced(input);
        printf("String: %s\nResult: %s\n", input, get_result_msg(result));
    } else {
        printf("Error reading input\n");
        return 1;
    }
    
    return 0;
}