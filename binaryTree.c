#include <stdio.h>
#include <stdlib.h>

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
void createTree(btNode* parent)
{
    // Data Var
    int data;

    // Left Child
    printf("Enter The Value for Left Child of %i: ", parent -> data);
    scanf("%i", &data);

    if (data == -1)
        parent -> left = NULL;
    else
    {
        parent -> left = createNode();
        (parent -> left) -> data = data;
        createTree(parent -> left);
    }

    // Right Child
    printf("Enter The Value for Right Child of %i: ", parent -> data);
    scanf("%i", &data);

    if (data == -1)
        parent -> right = NULL;
    else
    {
        parent -> right = createNode();
        (parent -> right) -> data = data;
        createTree(parent -> right);
    }
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

// Initialize Binary Tree
btNode* initBinaryTree()
{
    int data;
    printf("Enter The Value for Root Node: ");
    scanf("%i", &data);

    if (data == -1)
        return NULL;

    // Creating Root Node
    btNode* root = createNode();
    root -> data = data;
    createTree(root);
    return root;
}

int main()
{
    btNode* root = initBinaryTree();
    // Display
    display(root);
}
