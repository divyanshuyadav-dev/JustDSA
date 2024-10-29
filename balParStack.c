#include <stdio.h>
#include <string.h>

// Global Variable
#define max 40
char stack[max];
int tos = -1;

// Push
void push(char c)
{
    stack[++tos] = c;
}

// Pop
void pop()
{
    tos--;
}

int main()
{
    printf("\n----- Check for Balanced Parentheses (With Stack) -----\n");

    // Taking String from The User
    char e[max];
    printf("Enter The Expression: ");
    scanf("%[^\n]s", e);

    // String Length
    int len = strlen(e);

    // Checker
    for (int i = 0; i < len; i++)
    {
        if (e[i] == '(')
            push(e[i]);
        else if (e[i] == ')')
            pop();

        if (tos < -1)
            break;
    }

    if (tos != -1)
        printf("Unbalanced Expression\n");
    else
        printf("Balanced Expression\n");
}