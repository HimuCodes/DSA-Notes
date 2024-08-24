#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_balanced_parentheses(const char *expression) {
    char stack[100];
    int top = -1;
    char opening[] = "({[";
    char closing[] = ")}]";
    
    for (int i = 0; i < strlen(expression); i++) {
        char char_current = expression[i];
        
        // If the character is an opening parenthesis, push it onto the stack
        if (strchr(opening, char_current)) {
            stack[++top] = char_current;
        } 
        // If the character is a closing parenthesis, check for matching
        else if (strchr(closing, char_current)) {
            if (top == -1) {
                return false;  // Unmatched closing parenthesis
            }
            
            char top_char = stack[top--];
            
            // Check if the top of the stack matches the corresponding opening parenthesis
            if ((char_current == ')' && top_char != '(') ||
                (char_current == '}' && top_char != '{') ||
                (char_current == ']' && top_char != '[')) {
                return false;
            }
        }
    }
    
    // If the stack is empty, all parentheses were matched
    return top == -1;
}

int main() {
    const char *test_expressions[] = {
        "((()))",
        "({[]})",
        "(()",
        "({[}])",
        "",
        "((()())())",
        "())(",
    };

    int num_tests = sizeof(test_expressions) / sizeof(test_expressions[0]);

    for (int i = 0; i < num_tests; i++) {
        bool result = is_balanced_parentheses(test_expressions[i]);
        printf("'%s' is %s\n", test_expressions[i], result ? "balanced" : "not balanced");
    }

    return 0;
}
