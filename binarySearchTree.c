#include <stdio.h>
#include <stdlib.h>

#define size 100
int n[size];

// Blueprint of Binary Tree Node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} btNode;

// Create Node -> Create Binary Tree Node
btNode* createNode()
{
    return (btNode*) malloc(sizeof(btNode));
}

// Create Tree -> Expand Binary Tree
void createBinarySearchTree(btNode* parent, int i)
{
    if (i <= parent -> data)
    {
        if (parent -> left == NULL)
        {
            parent -> left = createNode();
            (parent -> left) -> data = i;
            (parent -> left) -> left = (parent -> left) -> right = NULL;
            return;
        }
        else
            createBinarySearchTree(parent -> left, i);
    }
    else
    {
        if (parent -> right == NULL)
        {
            parent -> right = createNode();
            (parent -> right) -> data = i;
            (parent -> right) -> left = (parent -> right) -> right = NULL;
            return;
        }
        else
            createBinarySearchTree(parent -> right, i);
    }
}

// Initialize Binary Tree
btNode* initBinarySearchTree()
{
    for (int i = 0; i < 100; i++)
    {
        printf("Enter %ith Number: ", i);
        scanf("%i", n + i);

        if (*(n + i) == -1)
            break;
    }

    if (n[0] != -1)
    {
        // Creating Root Node
        btNode* root = createNode();
        root -> data = n[0];
        root -> left = root -> right = NULL;

        for (int i = 1; n[i] != -1; i++)
        {
            if (i < size)
                createBinarySearchTree(root, n[i]);
            else
                break;
        }

        return root;
    }
    return NULL;
}

// Display
void display(btNode* parent)
{
    if (parent != NULL)
    {
        printf("\nParent -> %i\n", parent -> data);
        if ((parent -> left) != NULL)
            printf("\tLeft Child -> %i\n", (parent -> left) -> data);
        if ((parent -> right) != NULL)
            printf("\tRight Child -> %i\n", (parent -> right) -> data);
        display(parent -> left);
        display(parent -> right);
    }
}

// Search
int search(btNode* parent, int num)
{
    if (parent == NULL)
        return -1;
    else if (num == parent -> data)
        return parent -> data;
    else if (num < parent -> data)
        search(parent -> left, num);
    else if (parent -> data < num)
        search(parent -> right, num);
}

int main()
{
    btNode* root = initBinarySearchTree();

    // Display
    display(root);

    // Search
    int num;
    printf("Search for Number: ");
    scanf("%i", &num);

    if (search(root, num) == -1)
        printf("%i not found\n", num);
    else
        printf("%i found\n", num);
}