#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100

char stack[n];
char infix[n], postfix[n];
int top = -1;

void inToPost();
int precedence(char);
void push(char);
char pop();
int isEmpty();
int space(char);

void push(char c) {
    if (top == (n - 1)) {
        printf("The Stack is Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

int space(char c) {
    return (c == ' ' || c == '\t');
}

char pop() {
    if (top == -1) {
        printf("The Stack is Underflow\n");
        exit(0);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void inToPost() {
    int i, j = 0;
    char next;
    char symbol;
    
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        
        if (!space(symbol)) {
            switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while (!isEmpty() && (next = pop()) != '(') {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol; // Append operand directly
            }
        }
    }
    
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int precedence(char symbol) {
    switch (symbol) {
    case '^':
        return 3;
    case '*':
    case '%':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void display() {
    printf("The postfix is: %s\n", postfix);
}

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    inToPost();
    display();
    return 0;
}
