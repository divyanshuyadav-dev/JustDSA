#include <stdio.h>
#include <string.h>

// Global Variable
#define max 50
char stack[max / 2];
int tos = -1;

// Push
void push(char c)
{
    stack[++tos] = c;
}

// Pop
char pop()
{
    return stack[tos--];
}

// Peek
char peek()
{
    return stack[tos];
}

// Precedence Rule
int precedenceRule(char c)
{
    if (c == '(' || c == ')')
        return 4;
    else if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
}

// Associative Rule
int associativeRule(char c)
{
    int a = precedenceRule(c);
    if (a == 1 || a == 2)
    {
        printf("%c", pop());
        push(c);
    }
    else if (a == 3)
        push(c);
}

void operator(char c)
{
    if (tos == -1 || peek() == '(')
        // Rule 2
        push(c);
    else if (c == ')')
    {
        // Rule 3
        char popped;
        while (1)
        {
            popped = pop();
            if (popped != '(')
                printf("%c", popped);
            else
                return;
        }
    }
    else if (c == '$')
        // Rule 7
        while (tos != -1)
            printf("%c", pop());
    else if (precedenceRule(c) > precedenceRule(peek()))
        // Rule 4
        push(c);
    else if (precedenceRule(c) < precedenceRule(peek()))
    {
        // Rule 5
        printf("%c", pop());
        operator(c);
    }
    else if (precedenceRule(c) == precedenceRule(peek()))
        // Rule 6
        associativeRule(c);
}

int main()
{
    printf("\n----- Convert Infix Expression to Postfix Expression -----\n");\

    // Taking String from The User
    char e[max];
    printf("\nEnter The Infix Expression: ");
    scanf("%[^\n]s", e);

    // String Length
    int len = strlen(e);

    // $ -> Expression Ended
    e[len] = '$';
    
    printf("Postfix Expression: ");

    for (int i = 0; i <= len; i++)
    {
        if ((47 < e[i] && e[i] < 58) || (64 < e[i] && e[i] < 91) || (96 < e[i] && e[i] < 123))
            // Rule 1
            printf("%c", e[i]);
        else if (e[i] == '(' || e[i] == ')' || e[i] == '^' || e[i] == '*' || e[i] == '/' || e[i] == '+' || e[i] == '-' || e[i] == '$')
            // Invalid Symbols are Filtered Out
            operator(e[i]);
    }
}