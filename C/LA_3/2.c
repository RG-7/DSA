/*
    Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push %c\n", c);
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    if (top < 0)
    {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return stack[top--];
}

void reverse_string(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            push(str[i]);
        }
    }
    i = 0;
    while (top >= 0)
    {
        str[i++] = pop();
    }
    str[i] = '\0';
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}