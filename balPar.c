#include <stdio.h>
#include <string.h>

int main()
{
    printf("\n----- Check for Balanced Parentheses (Without Stack) -----\n");

    // Taking String from The User
    char e[40];
    printf("Enter The Expression: ");
    scanf("%[^\n]s", e);

    // String Length
    int len = strlen(e);

    // Counting Semaphores
    int countingSemaphore = 0;

    // Checker
    for (int i = 0; i < len; i++)
    {
        if (e[i] == '(')
            countingSemaphore++;
        else if (e[i] == ')')
            countingSemaphore--;

        if (countingSemaphore < 0)
            break;
    }

    if (countingSemaphore != 0)
        printf("Unbalanced Expression\n");
    else
        printf("Balanced Expression\n");
}