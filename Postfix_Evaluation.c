#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 20

typedef struct stack {
    char a[N];
    int top;
} stack;

void push(stack *s, int x) {
    s->top++;
    s->a[s->top] = x;
}

int pop(stack *s) {
    int x;
    x = s->a[s->top];
    s->top--;
    return x;
}

int evaluate(char exp[]) {
    int i = 0, j, op1, op2, res;
    stack s;
    s.top = -1;
    
    printf("Token \t Stack \n");
    
    while(exp[i] != '\0') {
        if(isalnum(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            op1 = pop(&s);
            op2 = pop(&s);
            
            if(exp[i] == '+')
                res = op2 + op1;
            else if(exp[i] == '*')
                res = op2 * op1;
            else if(exp[i] == '/')
                res = op2 / op1;
            else if(exp[i] == '-')
                res = op2 - op1;
            else
                res = op2 % op1;
                
            push(&s, res);
        }
        
        j = s.top;
        printf("%c \t \t ", exp[i]);
        
        while(j >= 0) {
            printf("%d ", s.a[j]);
            j--;
        }
        
        printf("\n");
        i++;
    }
    
    return pop(&s);
}

void main() {
    int res;
    char exp[20];
    
    printf("Enter the postfix expression:\n");
    scanf("%s", exp);
    
    res = evaluate(exp);
    printf("The result of the postfix expression is %d", res);
}
