#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data, color; // 0 for red 1 for black
	struct node *left,*right,*parent;
};
typedef struct node node;

int numberOfNodes=0;
void insertion(int,node*);
int uncle_color(node*);
int search(int,node*);
void preorder(node*);
void postorder(node*);
void inorder(node*);

node* allocate()
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->color= 0 ;
    newnode->parent = newnode->left = newnode->right = NULL;
    return newnode;
}

int uncle_check(int n, node *temp)
{
    if (temp == NULL)
        if (numberOfNodes == 0)
        return 0;
    else if (temp->data == n)
    {
        if(temp->parent->left->data==n) return temp->parent->right;
        else return temp->parent->left;
    }
    else
    {
        if (n < temp->data)
            search(n, temp->left);
        else
            search(n, temp->right);
    }
}

node* insert(int n,node* root)
{
	if(root==NULL)
    {
		node* newNode=allocate();
		newNode->data=n;
        newNode->color=0;
		root=newNode;
		numberOfNodes++;
		return newNode;
	}
	if(n<=root->data)
    {
	    root->left=insert(n,root->left);
        root->left->parent=root;
	}
	else
    {
	    root->right=insert(n,root->right);
	}
	return root;
}
int search(int n,node* temp)
{
	if(temp==NULL)
    {
		if(numberOfNodes==0)    printf("The tree is empty!\n");
		return 0;
	}
	else if(temp->data==n)
    {
		return 1;
	}
	else
    {
		if(n<temp->data) search(n,temp->left);
		else search(n,temp->right);
	}		
}
void preorder(node* temp)
{
	if(temp==NULL)
    {
    	if(numberOfNodes==0) printf("The tree is empty!!!\n");
		return;
	}
	else
    {
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(node* temp){
	if(temp==NULL)
    {
		if(numberOfNodes==0) printf("The tree is empty!!!\n");
		return;
	}
		else
        {
				postorder(temp->left);
				postorder(temp->right);
				printf("%d ",temp->data);
		}
}

void inorder(node* temp){
	if(temp==NULL)
    {
			if(numberOfNodes==0) printf("The tree is empty!!!\n");
			return;
	}
	else
    {
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

int main()
{
	node* root=NULL;
	int c, n;
	for(;;){
	printf("\nEnter your choice:\n1.Insert\n2.Search a number\n3.PreOrder\n4.Inorder\n5.Postorder\nPress ctrl+c to stop\n");
		scanf("%d",&c);
			switch(c){
					case 1:
					scanf("%d",&n);
					root=insert(n,root);
					break;
					case 2:
					scanf("%d",&n);
					if(search(n,root))
					printf("%d found \n",n);
					else printf("Not found\n");
					break;
					case 3:
					preorder(root);
					break;
					case 4:
					inorder(root);
					break;
					case 5:
					postorder(root);
					default:
					printf("Invalid choice!\n");
			}
	}
		return 0;
}