#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define max 10

char stack[max];
int top = -1;

void push(char ch) {
    if (isfull()) {
        printf("The stack is full\n");
    } else {
        stack[++top] = ch;
    }
}

bool isfull() {
    if (top >= max) {
        return true;
    } else {
        return false;
    }
}

bool isempty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int convertInfixtoPostfix(char *expr) {
    int i, j;
    char pexpr[max];
    
    printf("Prefix Expression \n%s \n", expr);
    printf("token \t stack \t Postfix Expression\n");
    
    for (i = 0, j = -1; expr[i]; ++i) {
        if (isalnum(expr[i])) {
            pexpr[++j] = expr[i];
        } else if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (expr[i] == ')') {
                while (!isempty() && peek() != '(') {
                    pexpr[++j] = pop();
                }
                pop();
            }
            if (expr[i] == '}') {
                while (!isempty() && peek() != '{') {
                    pexpr[++j] = pop();
                }
                pop();
            }
            if (expr[i] == ']') {
                while (!isempty() && peek() != '[') {
                    pexpr[++j] = pop();
                }
                pop();
            }
        } else {
            while (!isempty() && precedence(expr[i]) <= precedence(peek())) {
                pexpr[++j] = pop();
            }
            push(expr[i]);
        }
        printf("%c \t %s \t %s\n", expr[i], stack, pexpr);
    }
    
    while (!isempty()) {
        pexpr[++j] = pop();
    }
    
    pexpr[++j] = '\0';  // Add null terminator
    printf("Postfix Expression\n%s\n", pexpr);
    
    return 0;
}

int main() {
    char expr[max];
    
    printf("\nEnter infix expression:\n");
    scanf("%s", expr);
    
    convertInfixtoPostfix(expr);
    
    return 0;
}
