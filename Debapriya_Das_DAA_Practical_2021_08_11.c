#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node node;

node* insert(int, node *);
node *minValueNode(node *);
node *deleteNode(node *, int);
void inorder(node *);

int main()
{
    node *root = NULL;
    int c, n;
    for (;;)
    {
        printf("\nEnter your choice:\n1.Insert\n2.inorder\n3.delete something\nPress ctrl+c to stop\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            scanf("%d", &n);
            root = insert(n, root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            scanf("%d", &n);
            root = deleteNode(root, n);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

node *allocate()
{
    return (node *)calloc(1, sizeof(node));
}
node *minValueNode(node *currNode)
{
    node *current = currNode;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
node *insert(int n, node *root)
{
    if (root == NULL)
    {
        node *newNode = allocate();
        newNode->data = n;
        root = newNode;
        return newNode;
    }
    if (n <= root->data)
    {
        root->left = insert(n, root->left);
    }
    else
    {
        root->right = insert(n, root->right);
    }
    return root;
}

node *deleteNode(node *root, int n)
{
    if (root == NULL)
        return root;
    else if (n == root->data)
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            printf("%d deleted\n", root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    else
    {
        if (n <= root->data)
            root->left = deleteNode(root->left, n);
        else
            root->right = deleteNode(root->right, n);
    }
    return root;
}

void inorder(node *temp)
{
    if (temp == NULL)
        return;
    else
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
