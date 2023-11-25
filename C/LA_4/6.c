/*
    ADDITIONAL QUESTION 1
    Given a number N, write a function that generates and prints all binary numbers with decimal values from 1 to N.
*/

#include <stdio.h>
#include <string.h>

// C program to generate binary numbers from 1 to n
void generatePrintBinary(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char str[20] = "";
        int temp = i;
        int len = 0;
        while (temp)
        {
            str[len++] = temp & 1 ? '1' : '0';
            temp = temp >> 1;
        }
        str[len] = '\0';
        printf("%s\n", str);
    }
}

// Driver code
int main()
{
    int n = 10;

    // Function call
    generatePrintBinary(n);
    return 0;
}