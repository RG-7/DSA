/*
    Write a program that checks if an expression has balanced parentheses.
*/

#include <stdio.h>
#include <string.h>

int check_balance(char str[])
{
    int top = -1;
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            top++;
            str[top] = str[i];
        }

        if (str[i] == ')')
        {
            if (top == -1)
                return 0;

            if (str[top--] != '(')
                return 0;
        }
    }

    if (top == -1)
        return 1;

    return 0;
}

int main()
{
    char str[] = "(((1 + 2) * (3 + 4)))";
    int balanced = check_balance(str);

    if (balanced == 1)
        printf("The parentheses are balanced.\n");
    else
        printf("The parentheses are not balanced.\n");

    return 0;
}