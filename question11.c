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
void preorder(node*);
void postorder(node*);
void inorder(node*);

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
		printf("\nEnter your choice:\n1.Insert\n2.PreOrder\n3.Inorder\n4.Postorder\n5.Number of current nodes\nPress ctrl+c to stop\n");
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
		default:
			printf("Invalid choice!\n");
		}
	}
	return 0;
}