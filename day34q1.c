#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    
    return val;
}

int main() {
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            int b = pop();
            int a = pop();
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}