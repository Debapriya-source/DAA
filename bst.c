#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
	struct node *left,*right;
};
typedef struct node node;

int numberOfNodes=0;
void insertion(int,node*);
int search(int,node*);
void preorder(node*);
void postorder(node*);
void inorder(node*);
void ascending_order(node*);
void descending_order(node*);

node* allocate()
{
    return (node*)malloc(sizeof(node));
}
node* insert(int n,node* temp)
{
	if(temp==NULL)
    {
		node* newNode=allocate();
		newNode->data=n;
		temp=newNode;
		numberOfNodes++;
		return newNode;
	}
	if(n<=temp->data)
    {
	    temp->left=insert(n,temp->left);
	}
	else
    {
	    temp->right=insert(n,temp->right);
	}
	return temp;
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

void ascending_order(node* temp)
{
    if(temp==NULL)
    {
        if(numberOfNodes==0) printf("The tree is empty!!!\n");
        return;
    }
    else
    {
        ascending_order(temp->left);
        printf("%d ",temp->data);
        ascending_order(temp->right);
    }
}
void descending_order(node* temp)
{
    if(temp==NULL)
    {
		if(numberOfNodes==0) printf("The tree is empty!!!\n");
        return;
	}
	else
    {
		descending_order(temp->right);
		printf("%d ",temp->data);
		descending_order(temp->left);
	}
}


int main()
{
	node* root=NULL;
	int c, n;
	for(;;){
	printf("\nEnter your choice:\n1.Insert\n2.Search a number\n3.PreOrder\n4.Inorder\n5.Postorder\n6.Ascending order\n7.Descending order\nPress ctrl+c to stop\n");
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
					break;
                    case 6:
                    ascending_order(root);
                    break;
                    case 7:
                    descending_order(root);
                    break;
					default:
					printf("Invalid choice!\n");
			}
	}
		return 0;
}