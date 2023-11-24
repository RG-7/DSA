/*
 * 4) String Related Programs
 *      (a) Write a program to concatenate one string to another string.
 *      (b) Write a program to reverse a string.
 *      (c) Write a program to delete all the vowels from the string.
 *      (d) Write a program to sort the strings in alphabetical order.
 *      (e) Write a program to convert a character from uppercase to lowercase.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// a.) function for concatenate strings
void concatenateString() {
    printf("\n\ta.) String Concatenation\t\t\n");
    char string1[100], string2[100];
    printf("Enter String 1: ");
    scanf("%s", string1);
    printf("Enter String 2: ");
    scanf("%s", string2);
    
    strcat(string1, " ");
    strcat(string1, string2);
    
    printf("String after concatenation is: %s\n", string1);
}

// b.) function to reverse a String
void reverseString() {
    printf("\n\n\tb.) Reverse String\t\t\n");
    char string[100];
    printf("Enter the String: ");
    scanf("%s", string);
    
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
    
    printf("String after reversing actual String: %s\n", string);
}

// c.) function to delete vowels from the string
void delVowelsString() {
    printf("\n\tDeleting Vowels in String\t\t\n");
    char s[100], ss[100];
    printf("Enter the String: ");
    scanf("%s", s);
    
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!strchr("AEIOUaeiou", s[i])) {
            ss[j++] = s[i];
        }
    }
    ss[j] = '\0';
    
    printf("String after deletion is: %s\n", ss);
}

// d.) function to sort a string in alphabetical order
void sort() {
    printf("\n\tSorting String\t\t\n");
    char s[100];
    printf("Enter the String: ");
    scanf("%s", s);
    
    int length = strlen(s);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    
    printf("New String after sorting: %s\n", s);
}

// e.) function to convert uppercase to lowercase
void u2l() {
    printf("\n\tUpperCase Character to LowerCase\n");
    char c;
    printf("Enter the character: ");
    scanf(" %c", &c);
    
    printf("Char You entered is: %c\n", c);
    if (c >= 'A' && c <= 'Z') {
        c = tolower(c);
        printf("Changed Character is: %c\n", c);
    } else {
        printf("Character is not uppercase.\n");
    }
}

int main() {
    // a.)
    concatenateString();
    // b.)
    reverseString();
    // c.)
    delVowelsString();
    // d.)
    sort();
    // e.)
    u2l();
    
    return 0;
}
