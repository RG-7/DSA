/*
    Write a program to convert an Infix expression into a Postfix expression.
*/

#include <stdio.h>
#include <string.h>

int precedence(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j, k, l, t;
    char stack[50], *temp, symbol;

    temp = strtok(infix, " ");
    k = 0;
    stack[0] = '(';
    l = 1;
    strcpy(postfix, "");

    while (temp != NULL)
    {
        symbol = temp[strlen(temp) - 1];
        if (isalnum(symbol))
            postfix[k++] = symbol;
        else if (symbol == '(')
        {
            stack[l++] = symbol;
        }
        else if (symbol == ')')
        {
            while (stack[l - 1] != '(')
            {
                postfix[k++] = stack[--l];
            }
            --l;
        }
        else
        {
            t = precedence(stack[l - 1]);
            if (precedence(symbol) > t)
            {
                stack[l++] = symbol;
            }
            else
            {
                while (precedence(stack[l - 1]) >= t)
                {
                    postfix[k++] = stack[--l];
                }
                stack[l++] = symbol;
            }
        }
        temp = strtok(NULL, " ");
    }

    while (l > 1)
    {
        postfix[k++] = stack[--l];
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[50], postfix[50];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    return 0;
}