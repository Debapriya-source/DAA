#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct RBnode
{
 	int key;
 	struct RBnode *left; 
 	struct RBnode *right; 
    struct RBnode *parent; 
    int color;  
};
typedef struct RBnode RBnode;

RBnode *allocate();
void makeNIL();
void makeNew(RBnode *x);
RBnode *RB_Insert(RBnode *root,RBnode *z);
RBnode *Left_Rotate(RBnode *root,RBnode *x);
RBnode *Right_Rotate(RBnode *root,RBnode *y);
RBnode *RB_Fix(RBnode *root,RBnode *z);
void preorder (RBnode * temp);
void postorder (RBnode * temp);
void inorder (RBnode * temp);
int search (RBnode *temp, int x);

RBnode *NIL; //NIL node

int n; //total number of nodes 


void main()
{
    NIL = allocate(); 
    makeNIL(); 
    RBnode *root = NIL; 
    int ch;
    int x=0;
	for(;;)
	{
		printf("\n0. Exit program\n1. Insert\n2. Search\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6.Number of nodes\n");
		printf("\nYour choice : \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: printf("\nProgram terminated.\n\n");
					exit(0); 
					break;
			case 1: printf("Enter a number : \n");
					scanf("%d",&x);

                    RBnode *z = allocate(); 
                    z->key=x; 
                    
					root=RB_Insert(root,z); 
                    n++; 
					break;
			case 2: printf("\nEnter a number to be searched : \n");
					scanf("%d",&x);

                    if(search(root,x)>0) 
					    printf("\n%d is FOUND!\n");
					else
					    printf("\n%d is NOT FOUND...\n",x);
					break;
			case 3: printf("\nPreorder Traversal : \n");
					preorder(root);
					break;
			case 4: printf("\nInorder Traversal : \n");
					inorder(root);
					break;
			case 5: printf("\nPostorder Traversal : \n");
					postorder(root);
					break;
            case 6: printf("\nNumber of nodes : %d\n",n);
                    break;
			default: printf("\nInvalid Choice.\n"); 
		}
	}
}

//allocates memory for NIL node
RBnode *allocate()
{
    RBnode *z=calloc(1,sizeof(RBnode));
    return z;
}

//set the members of NIL node appropriately
void makeNIL() 
{
    NIL->color = BLACK;
    NIL->left=NULL;
    NIL->right=NULL;
}

//set the members of new node appropriately
void makeNew(RBnode *x)
{
    x->color = RED;
    x->left=NIL;
    x->right=NIL;
}

RBnode *RB_Insert(RBnode *root,RBnode *z)
{
    RBnode *y = NIL; //for the parent
    RBnode *x = root;

    while (x!=NIL)
    {
        //storing x, so that once x reaches NIL and the loop  
        //condition fails, y will reference the parent of new node
        y=x; 

        //choosing which subtree to traverse, according to 
        //the key of new node, following the rules of a BST    
        if(z->key < x->key)
            x=x->left;
        else
            x=x->right;
    }

    z->parent=y; //parent of new node found
    if (y==NIL) //if RBtree is empty
    {
        root=z; //assign new node as root
        root->parent=NIL; //note that parent of root also references NIL
    }
    //choosing whether the new node will be its parent's left or right child
    else if(z->key < y->key) 
        y->left=z; //in this case, left child
    else
        y->right=z; //and in this case, right child

    makeNew(z); //set the members of new node appropriately
    return RB_Fix(root,z); //fix method called
}

//Left-Rotate a tree about RBnode *x
RBnode *Left_Rotate(RBnode *root,RBnode *x)
{
    RBnode *y = x->right; //initialize y = right subtree of x
    x->right=y->left; //assign y's left subtree to x's right subtree

    if (y->left!=NIL) //if y's left subtree exists (not NIL)
        y->left->parent=x; //make its parent = x

    y->parent = x->parent; //make x's parent as y's parent
    if(x->parent == NIL) //if x is the root
    {
        root=y; //make y the root
        root->parent=NIL; //Note: The root's parent always refers NIL
    }
    else if (x->parent->left == x) //if x is its parent's left child
        x->parent->left = y; //make x's parent's left child = y
    else //if x is its parent right child
        x->parent->right = y; //make x's parent's right child = y
    
    y->left = x; //now x is the left child of y
    x->parent = y; //and y is x's parent
    return root;
}

//Right-Rotate a tree about RBnode *y
RBnode *Right_Rotate(RBnode *root,RBnode *y)
{
    RBnode *x = y->left; //initialize x = left subtree of y
    y->left=x->right; //assign x's right subtree to y's left subtree  

    if (x->right!=NIL) //if x's right subtree exists (not NIL)
        x->right->parent=y; //make its parent = y

    x->parent = y->parent; //make y's parent as x's parent
    if(y->parent == NIL) //if y is the root
    {
        root=x; //make x the root
        root->parent=NIL; //Note: The root's parent always refers NIL
    }
    else if (y->parent->right == y) //if y is its parent's right child
        y->parent->right = x; //make y's parent's right child = x
    else //if y is its parent's left child 
        y->parent->left = x; //make y's parent's left child = x
    
    x->right = y; //now y is the left child of x
    y->parent = x; //and x is y's parent
    return root;
}

RBnode *RB_Fix(RBnode *root,RBnode *z)
{
    //node to refer uncle node of the current node z
    RBnode *y=NULL; 

    //if parent of current node is RED
    while(z->parent->color == RED)
    {
        //if parent of current node is grandparent's left child
        if(z->parent == z->parent->parent->left)
        {
            y=z->parent->parent->right; //uncle node of current node
            if(y->color==RED) //if uncle node is RED as well
            {
                z->parent->color=BLACK; //change parent to BLACK
                y->color=BLACK; //change uncle to BLACK
                z->parent->parent->color=RED; //change grandparent to RED

                //current node changed to grandparent of current node
                z=z->parent->parent; 
            }

            else
            { 
                //if current node is parent's right child
                if(z==z->parent->right) //true only for L-R structure
                {
                    z=z->parent; //current node changes to parent
                    //perform a left rotation about parent
                    root = Left_Rotate(root,z);
                }
                z->parent->color=BLACK; //change parent to BLACK
                z->parent->parent->color=RED; //change grandparent to RED
                //perform a right rotation about grandparent
                root = Right_Rotate(root,z->parent->parent);
            }
        }

        else //if parent of current node is grandparent's right child
        {
            y=z->parent->parent->left; //uncle node of current node
            if(y->color==RED) //if uncle node is RED as well
            {
                z->parent->color=BLACK; //change parent to BLACK
                y->color=BLACK; //change uncle to BLACK
                z->parent->parent->color=RED; //change grandparent to RED

                //current node changed to grandparent of current node
                z=z->parent->parent; 
            }
            else 
            {
                if(z==z->parent->left) //true only for R-L structure
                {
                    z=z->parent; //current node changes to parent
                    //perform a right rotation about parent
                    root = Right_Rotate(root,z);
                }
                z->parent->color=BLACK; //change parent to BLACK
                z->parent->parent->color=RED; //change grandparent to RED
                //perform a letf rotation about grandparent
                root = Left_Rotate(root,z->parent->parent);
            }
        }
    }
    root->color=BLACK; //Note: Root is always BLACK
    return root;
}

void inorder (RBnode *temp)
{
    if (temp==NIL) 
	{
		if (n==0)
		    printf("\nEMPTY TREE\n");
		return;
	}
    //determining what character to print, according to node colour
    char c = (temp->color == RED)?'R':'B';
	inorder(temp->left);
	printf("%d(%c) ",temp->key,c);
	inorder(temp->right);
}

//preorder traversal of RBtree 
void preorder (RBnode *temp)
{
    if (temp==NIL) 
	{
		if (n==0)
		    printf("\nEMPTY TREE\n");
		return;
	}
    //determining what character to print, according to node colour
    char c = (temp->color == RED)?'R':'B';
	printf("%d(%c) ",temp->key,c);
	preorder(temp->left);	
	preorder(temp->right);
}

//postorder traversal of RBtree 
void postorder (RBnode *temp)
{
    if (temp==NIL) 
	{
		if (n==0)
		    printf("\nEMPTY TREE\n");
		return;
	}
    //determining what character to print, according to node colour
    char c = (temp->color == RED)?'R':'B';
	postorder(temp->left);	
	postorder(temp->right);
	printf("%d(%c) ",temp->key,c);
}

//search for an element in the Red-Black Tree
int search (RBnode *temp, int x)
{
	if (temp==NIL) 
	{
		if (n==0) //for an empty tree 
		    printf("\nEMPTY TREE\n");
		return 0; //for both empty tree or element not found
	}
	else if (temp->key==x) //element found
		return 1;
    else
    {
        if (x < temp->key) //element may reside in left subtree
            search (temp->left,x);
        else //element may reside in right subtree
            search (temp->right,x);
    }
}
