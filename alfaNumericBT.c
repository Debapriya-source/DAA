#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include<math.h>

struct node
{
	char *data;
	struct node *left, *right;
};
typedef struct node node;

int numberOfNodes = 0;
int level=0,currentNumberOfElementsInALevel=0;
void insertion(char*,node*);
void preorder(node*);
void postorder(node*);
void inorder(node*);
 
node *allocate()
{
	return (node *)calloc(1, sizeof(node));
}

//this function inserts any new node in a level order fashion. 
node *insert(char *n, node *root)
{
    if(root==NULL){
        node *newNode = allocate();
		newNode->data = n;
		root = newNode;
		numberOfNodes++;
        currentNumberOfElementsInALevel++;
        if(currentNumberOfElementsInALevel==pow(2,level)){
            level++;
            currentNumberOfElementsInALevel=0;
        }
    }
    else {
        if(currentNumberOfElementsInALevel%2==0) root->left = insert(n,root->left);
        else root->right = insert(n,root->right);
    }

	return root;
}
void preorder(node *root)
{
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!!!\n");
		return;
	}
	else
	{
		printf("%s ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!!!\n");
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%s ", root->data);
	}
}

void inorder(node *root)
{
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!!!\n");
		return;
	}
	else
	{
		inorder(root->left);
		printf("%s ", root->data);
		inorder(root->right);
	}
}

int main()
{
	node *root = NULL;
	int c;

	for (;;)
	{
		char *n = (char *)(calloc(10, sizeof(char)));
		printf("\nEnter your choice:\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Number of current nodes\n6.Level of the tree\nPress ctrl+c to stop\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("Enter the node to be inserted: ");
			scanf("%s", n);
			//printf("%s scanned\n", n);
			root = insert(n, root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			printf("%d\n",numberOfNodes);
			break;
        case 6:
            printf("%d\n",level);
			break;
		default:
			printf("Invalid choice!\n");
		}
	}
	return 0;
}