#include <stdio.h>
#include <string.h>

// Global Variable
#define max 50
char stack[max];
int tos = -1;

// Pushing all Chars of String into the Stack
void pushAll(char* c, int len)
{
    for (int i = 0; i < len; i++)
        stack[++tos] = c[i];
}

// Popping all Chars of String out of Stack
void popAll(char* c, int len)
{
    for (int i = 0; i < len; i++)
        c[i] = stack[tos--];
}

// Display
void display(char* c, int len)
{
    for (int i = 0; i < len; i++)
        printf("%c", c[i]);
}

int main()
{
    // char string[max] = "Minions Tonight We Steal the Moon";
    
    // Taking String from The User
    char string[max];
    printf("Enter The String to Reverse: ");
    scanf("%[^\n]s", string);

    // String Length
    int len = strlen(string);

    // Pushing all Chars of String into the Stack
    pushAll(string, len);

    // Popping all Chars of String out of Stack
    popAll(string, len);

    // Display
    display(string, len);
}