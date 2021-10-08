#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>

struct node
{
	char *data;
	struct node *left, *right;
};
typedef struct node node;

int numberOfNodes = 0;
void insertion(char*,node*);
int search(char*,node*);
void preorder(node*);
void postorder(node*);
void inorder(node*);

void ascending_order(node*);
void descending_order(node*);

int isNumericChar(char x)
{
    return (x >= '0' && x <= '9') ? 1 : 0;
}
//normal atoi() functions converts strings into integers like "12"(string) will converted to 12(int), "31abcd"(string) would converted to 31(int)
//and for the strings that can't be converted returns 0. So we cannot distinguish between a string and an actual 0. So we need some modification.
int modifiedAtoi(char* str)
{
    if (*str == '\0')
        return 0;
 
    // Initialize result
    int res = 0;
 
    // Initialize sign as positive
    int sign = 1;
 
    // Initialize index of first digit
    int i = 0;
 
    // If number is negative,
    // then update sign
    if (str[0] == '-')
    {
        sign = -1;
 
        // Also update index of first digit
        i++;
    }
 
    // Iterate through all digits of
    // input string and update result
    for (; str[i] != '\0'; ++i)
    {
 
        // You may add some lines
        // to write error message
        if (!isNumericChar(str[i]))
            return 0;
 
        // to error stream
        res = res * 10 + str[i] - '0';
    }
    if(res==0) return -INT_MAX; //if the string value is actually zero
    // Return result with sign
    return sign * res;
}
 
node *allocate()
{
	return (node *)calloc(1, sizeof(node));
}
node *insert(char *n, node *root)
{
	//printf("In the insert function, inserting-> %s\n", n);
	if (root == NULL)
	{
		//printf("root==null\n");
		node *newNode = allocate();
		newNode->data = n;
		root = newNode;
		numberOfNodes++;
		return root;
	}
	//if data is string and current node is numeric 
	else if((modifiedAtoi(n)!=0 || modifiedAtoi(n)== -INT_MAX)&& modifiedAtoi(root->data)==0){
		root->left = insert(n, root->left);
	}
	//if data is numeric and current node is string
	else if (modifiedAtoi(n) == 0 && modifiedAtoi(n)!=-INT_MAX && modifiedAtoi(root->data) != 0)
	{
		//printf("inserting at right\n");
		root->right = insert(n, root->right);
	}
	//if data and current node both are numeric 
	else if( (modifiedAtoi(n)!=0 || modifiedAtoi(n)==-INT_MAX) && modifiedAtoi(root->data)!=0 ){
		if (atoi(n) <= modifiedAtoi(root->data)) //we don't want to compare INT_MAX, instead we can use normal atoi()
			root->left = insert(n, root->left);
		else
			root->right = insert(n, root->right);
	}
	//if both are string
	else{
	//printf("root->data => %s\n", root->data);
	if (strcmp(n, root->data) < 0)
	{
		//printf("%s < %s \n", n, root->data);
		root->left = insert(n, root->left);
	}
	else
	{
		//printf("%s > %s \n", n, root->data);
		root->right = insert(n, root->right);
	}
	}
	return root;
}
int search(char *n, node *root)
{
	printf("searching %s\n", n);
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!\n");
		return 0;
	}
	else if (!strcmp(root->data, n))
	{
		//printf("%s == %s \n", n, root->data);
		return 1;
	}
	//if data is string and current node is numeric
	else if ((modifiedAtoi(n) != 0 || modifiedAtoi(n) == -INT_MAX) && modifiedAtoi(root->data) == 0)
	{
		search(n, root->left);
	}
	//if data is numeric and current node is string
	else if (modifiedAtoi(n) == 0 && modifiedAtoi(n) != -INT_MAX && modifiedAtoi(root->data) != 0)
	{
		//printf("inserting at right\n");
		search(n, root->right);
	}
	//if data and current node both are numeric
	else if ((modifiedAtoi(n) != 0 || modifiedAtoi(n) == -INT_MAX) && modifiedAtoi(root->data) != 0)
	{
		if (atoi(n) <= modifiedAtoi(root->data)) //we don't want to compare INT_MAX, instead we can use normal atoi()
			search(n, root->left);
		else
			search(n, root->right);
	}

	else
	{
		if (strcmp(n, root->data) < 0)
			search(n, root->left);
		else
			search(n, root->right);
	}
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

void ascending_order(node *root)
{
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!!!\n");
		return;
	}
	else
	{
		ascending_order(root->left);
		printf("%s ", root->data);
		ascending_order(root->right);
	}
}
void descending_order(node *root)
{
	if (root == NULL)
	{
		if (numberOfNodes == 0)
			printf("The tree is empty!!!\n");
		return;
	}
	else
	{
		descending_order(root->right);
		printf("%s ", root->data);
		descending_order(root->left);
	}
}

node* minValueNode(node* currNode)
{
    node* current = currNode;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree
   and a data, this function
   deletes the data and
   returns the new root */
node *deleteNode(node *root, char *n)
{
	if(root) printf("deleteNode(root->data(%s), n(%s)):\n",root->data,n);
	// base case
	if (root == NULL)
	{
		printf("Root is null\n");
		return root;
	}
	else if (strcmp(n, root->data) == 0)
	{
		// node with only one child or no child
		printf("%s has only one child\n", root->data);
		if (root->left == NULL)
		{
			printf("root->left is null\n");
			node *temp = root->right;
			printf("%s deleted\n", root->data);
			numberOfNodes--;
			free(root);
			if(temp) printf("temp->data = %s\n",temp->data);
			else printf("temp is null\n");
			return temp;
		}
		else if (root->right == NULL)
		{
			printf("root->right is null\n");
			node *temp = root->left;
			printf("%s deleted\n", root->data);
			numberOfNodes--;
			free(root);
			if(temp) printf("temp->data = %s\n",temp->data);
			else printf("temp is null\n");
			return temp;
		}
		printf("%s has two childs\n",root->data);
		// node with two children:
		// Get the inorder successor
		// (smallest in the right subtree)
		node *temp = minValueNode(root->right);

		// Copy the inorder
		// successor's content to this node
		root->data = temp->data;
		if(temp) printf("temp->data = %s\n",temp->data);
		else printf("temp is null\n");
		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}

	//if data is string and current node is numeric
	else if ((modifiedAtoi(n) != 0 || modifiedAtoi(n) == -INT_MAX) && modifiedAtoi(root->data) == 0)
	{
		root->left = deleteNode(root->left, n);
	}
	//if data is numeric and current node is string
	else if (modifiedAtoi(n) == 0 && modifiedAtoi(n) != -INT_MAX && modifiedAtoi(root->data) != 0)
	{
		//printf("inserting at right\n");
		root->right = deleteNode(root->right, n);
	}
	//if data and current node both are numeric
	else if ((modifiedAtoi(n) != 0 || modifiedAtoi(n) == -INT_MAX) && modifiedAtoi(root->data) != 0)
	{
		if (atoi(n) <= modifiedAtoi(root->data)) //we don't want to compare INT_MAX, instead we can use normal atoi()
			root->left = deleteNode(root->left, n);
		else
			root->right = deleteNode(root->right, n);
	}
	else
	{
		//printf("root->data => %s\n", root->data);
		if (strcmp(n, root->data) < 0)
		{
			//printf("%s < %s \n", n, root->data);
			root->left = deleteNode(root->left, n);
		}
		else
		{
			//printf("%s > %s \n", n, root->data);
			root->right = deleteNode(root->right, n);
		}
	}
	// if data is same as root's data,
	// then This is the node
	// to be deleted

	return root;
}

int main()
{
	node *root = NULL;
	int c;

	for (;;)
	{
		char *n = (char *)(calloc(10, sizeof(char)));
		printf("\nEnter your choice:\n1.Insert\n2.Search a number\n3.PreOrder\n4.Inorder\n5.Postorder\n6.Ascending order\n7.Descending order\n8.Delete a node\n9.Number of current nodes\nPress ctrl+c to stop\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("Enter the node to be inserted: ");
			scanf("%s", n);
			printf("%s scanned\n", n);
			root = insert(n, root);
			break;
		case 2:
			scanf("%s", n);
			if (search(n, root))
				printf("%s found \n", n);
			else
				printf("Not found\n");
			break;
		case 3:
			preorder(root);
			break;
		case 4:
			inorder(root);
			break;
		case 5:
			postorder(root);
			break;
		case 6:
			ascending_order(root);
			break;
		case 7:
			descending_order(root);
			break;
		case 8:
			printf("Enter the node to be deleted: ");
			scanf("%s", n);
			root = deleteNode(root,n);
			break;
		case 9:
			printf("%d\n",numberOfNodes);
			break;
		default:
			printf("Invalid choice!\n");
		}
	}
	return 0;
}