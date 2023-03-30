#include <stdio.h>
#include <malloc.h>


struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
};

struct btnode *root = NULL;
int flag;

void in_order_traversal(struct btnode *);
void in_order_search(struct btnode *,int);
struct btnode *newnode(int);

void main()
{
    int search_val;
    root = newnode(50);
    root->l = newnode(20);
    root->r = newnode(30);
    root->l->l = newnode(70);
    root->l->r = newnode(80);
    root->l->l->l = newnode(10);
    root->l->l->r = newnode(40);
    root->l->r->r = newnode(60);

    printf("The elements of Binary tree are:");
    in_order_traversal(root);
    printf("Enter the value to be searched:");
    scanf("%d", &search_val);
    in_order_search(root, search_val);
    if (flag==0)
    {
        printf("Element not present in the binary tree\n");
    }
}

struct btnode* newnode(int value)
{
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = value;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}


void in_order_traversal(struct btnode *p)
{
    if (!p)
    {
        return;
    }
    in_order_traversal(p->l);
    printf("%d->", p->value);
    in_order_traversal(p->r);
}

void in_order_search(struct btnode *p, int val)
{
    if (!p)
    {
        return;
    }
    in_order_search(p->l, val);
    if(p->value == val)
    {
        printf("\nElement present in the binary tree.\n");
        flag = 1;
    }
    in_order_search(p->r, val);
}
