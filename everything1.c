#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *left;
struct node *right;
};
struct node *first=NULL;
struct node *last=NULL;
struct node *a;

void reverse(struct node **head)
{
    struct node *prev=NULL;
    struct node *current = *head;
    struct node *next=NULL;

    while(current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;


}

void push(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=first;
    first=temp;
}
void pop()
{
    struct node *temp;
    if(first==NULL)
    {
        return;
    }
    temp=first;
    first=first->next;
    free(temp);
}

void print()
{
    struct node *t;
    t=first;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
void enqueue(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(first==NULL)
    {
        first=last=temp;
    }
    last->next=temp;
    last=temp;
}
void dequeue()
{
    struct node *temp = first;
    if(first==NULL)
    {
        return;
    }
    if(first==last)
    {
        first=last=NULL;
    }
    else
    {
        first=first->next;
    }
free(temp);

}
void insert(int data,int n)
{
    struct node *temp1= (struct node*)malloc(sizeof(struct node));
    temp1->data=data;
    temp1->next=NULL;
    int i;

    if(n==1)
    {
        temp1->next=first;
        first=temp1;
        return;
    }

    struct node *temp2=first;

    for(i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }

    temp1->next=temp2->next;
    temp2->next=temp1;
}
void dele(int n)
{   struct node *temp1 = first;
int i;
    if(n==1)
    {
        first=temp1->next;
        free(temp1);
        return;
    }

    for(i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }


    struct node *temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);

}
struct node *getnewnode(int data)
{   struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;

}
struct node *Insert(struct node *root,int data)
{  // struct node *temp=(struct node*)malloc(sizeof(struct node));
    //temp->data=data;
    //temp->left=temp->right=NULL;
    if(root==NULL)
    {
        root=getnewnode(data);
    }
    else if(data<=root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;

}
struct node *Findmax(struct node *root)
{while(root->right!=NULL)
{
 root=root->right;
}
return root;

}
struct node *Findmin(struct node *root)
{
 while(root->left!=NULL)
        root=root->left;

 return root;
}
struct node *delete1(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        delete1(root->left,data);
    }
    else if(data>root->data)
    {
        delete1(root->right,data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }

        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);

        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            struct node *temp = Findmin(root->right);
            root->data=temp->data;
            root->right = delete1(root->right,temp->data);
        }
    }
    return root;
}

int maximum(struct node *root)
{

     struct node *maxx=(struct node*)malloc(sizeof(struct node));
    maxx=Findmax(root);
    int max=maxx->data;

    return max;
}
void check(struct node *root,int min,int max)
{
    int x;
    /*
    struct node *minn=(struct node*)malloc(sizeof(struct node));
    minn=Findmin(root);
    int min=minn->data;
    struct node *maxx=(struct node*)malloc(sizeof(struct node));
    maxx=Findmax(root);
    int max=maxx->data;
*/
    if(root==NULL)
    {
        printf("\nIs a tree");
        return;
    }
    if(root->data<min || root->data>max)
            printf("Not a tree.");


    check(root->left,min,root->data-1);
    check(root->right,root->data+1,max);
    //x=root->data;

    //check(root->left);

}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    //stack
    /*
    push(5);
    push(2);
    push(3);
    print();
    pop();
    print();
*/
//queue
/*
enqueue(7);
enqueue(9);
enqueue(3);
print();
//dequeue();
print();
//reverse(&first);
print();
*/
//regular linked list
/*
first=(struct node*)malloc(sizeof(struct node));
printf("\nEnter 1: ");
scanf("%d",&first->data);
first->next=NULL;
last=first;

a=(struct node*)malloc(sizeof(struct node));
printf("\nEnter 2: ");
scanf("%d",&a->data);
a->next=NULL;
last->next=a;
last=a;

a=(struct node*)malloc(sizeof(struct node));
printf("\nEnter 3: ");
scanf("%d",&a->data);
a->next=NULL;
last->next=a;
last=a;
print();
insert(20,4);
print();
dele(2);
print();
*/
//BST

struct node *root = NULL;
root=Insert(root,6);
root=Insert(root,7);
root=Insert(root,1);
root=Insert(root,20);
root=Insert(root,10);
inorder(root);
printf("\n");
delete1(root,6);
inorder(root);
int min = minimum(root);
int max = maximum(root);
//check(root,min,max);

    return 0;
}

