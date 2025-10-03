#include <stdio.h>
#include <string.h> 
#include <ctype.h>  

void custom_trim(const char *input_str, char *output_str) {
    int start = 0;
    int end = strlen(input_str) - 1;
    int i = 0;

    while (start < strlen(input_str) && isspace(input_str[start])) {
        start++;
    }

    while (end >= start && isspace(input_str[end])) {
        end--;
    }

    for (i = start; i <= end; i++) {
        output_str[i - start] = input_str[i];
    }

    output_str[i - start] = '\0';
}

int main() {
    char user_input[256]; 
    char trimmed_output[256]; 

    printf("Enter the string line:\n");

    fgets(user_input, sizeof(user_input), stdin);

    user_input[strcspn(user_input, "\n")] = 0;

    custom_trim(user_input, trimmed_output);

    printf("------------------------------------------\n");
    printf("Original string line: \"%s\"\n", user_input);
    printf("New string line: \"%s\"\n", trimmed_output);

    return 0;
}