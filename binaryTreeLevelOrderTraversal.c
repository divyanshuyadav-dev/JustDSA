#include <stdio.h>
#include <stdlib.h>

// Blueprint of Binary Tree Node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} btNode;

// BluePrint of Single Linked List Node for Linear Queue
typedef struct sllNode {
    btNode* bTreeNode;
    struct sllNode* next;
} lqNode;

// Create Node -> Create Binary Tree Node
btNode* createNode()
{
    return (btNode*) malloc(sizeof(btNode));
}

// Global Variable
lqNode* f, *r;

// Create Single Linked List Node and Returns It's Address
lqNode* getLqNode()
{
    return (lqNode*) malloc(sizeof(lqNode));
}

// is Empty?
int isEmpty()
{
    if (f == NULL)
        // True
        return 1;
    // False
    return 0;
}

// Enqueue
void enqueue(btNode* child)
{
    // Creating qNewNode
    lqNode* qNewNode = getLqNode();

    if (f == NULL)
        // Setting up The Front Pointer for The Very Front Node
        f = qNewNode;
    else
        // Connecting Prev Rear Node with New Rear Node
        r -> next = qNewNode;

    // Setting up The Rear Pointer for The Latest Node
    r = qNewNode;

    // qNewNode Data
    qNewNode -> bTreeNode = child;

    // qNewNode Next
    qNewNode -> next = NULL;
}

// Dequeue
btNode* dequeue()
{
    if (isEmpty())
        return NULL;
    else
    {
        // Fetching Front Most Element
        btNode* root = f -> bTreeNode;

        // Temp Next
        lqNode* tempNext = f -> next;

        // Delete Front Most Node
        free(f);

        // Setting up The Front Pointer for The Very Front Node
        f = tempNext;

        // Setting up The Rear Pointer for The Very Front Node
        if (f == NULL)
            r = NULL;

        return root;
    }
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

// Level Order Traversal
void levelOrderTraversal(btNode* parent)
{
    if (parent == NULL)
        return;

    // Print The Node
    printf("%i\t", parent -> data);

    // Check for Children
    if ((parent -> left) != NULL)
        enqueue(parent -> left);
    if ((parent -> right) != NULL)
        enqueue(parent -> right);

    levelOrderTraversal(dequeue());
}

int main()
{
    btNode* root = initBinaryTree();

    // Level Order Traversal
    printf("\nLevel Order Traversal:\n");
    levelOrderTraversal(root);
}
