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

// Preorder Traversal - Data Left Right
void preOrderTraversal(btNode* parent)
{
    if (parent != NULL)
    {
        printf("%i\t", parent -> data);
        preOrderTraversal(parent -> left);
        preOrderTraversal(parent -> right);
    }
}

// Inorder Traversal - Left Data Right
void inOrderTraversal(btNode* parent)
{
    if (parent != NULL)
    {
        inOrderTraversal(parent -> left);
        printf("%i\t", parent -> data);
        inOrderTraversal(parent -> right);
    }
}

// Postorder Traversal - Left Right Data
void postOrderTraversal(btNode* parent)
{
    if (parent != NULL)
    {
        postOrderTraversal(parent -> left);
        postOrderTraversal(parent -> right);
        printf("%i\t", parent -> data);
    }
}

int main()
{
    btNode* root = initBinaryTree();

    // Preorder Traversal
    printf("\nPreorder Traversal:\n");
    preOrderTraversal(root);

    // Inorder Traversal
    printf("\n\nInorder Traversal:\n");
    inOrderTraversal(root);

    // Postorder Traversal
    printf("\n\nPostorder Traversal:\n");
    postOrderTraversal(root);
}
