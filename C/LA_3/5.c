/*
    Write a program for the evaluation of a Postfix expression.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *addChar(char *str, char ch)
{
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
    return str;
}

int applyOp(char op, int b, int a)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int evaluatePostfix(char *str)
{
    int i = 0, val;
    int numStack[100];
    int top = -1;

    while (str[i])
    {
        if (isdigit(str[i]))
        {
            numStack[++top] = str[i] - '0';
        }
        else
        {
            int b = numStack[top--];
            int a = numStack[top--];
            numStack[++top] = applyOp(str[i], b, a);
        }
        i++;
    }

    return numStack[top];
}

int main()
{
    char postfix[100];
    printf("Enter a Postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}