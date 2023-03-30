
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* left, *right;
};

int data[100];
int i = 0;

struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;

    return(newnode);
}

int count(struct node *n)
{
    int c = 1;

    if (n == NULL)
        return 0;
    else
    {
        c += count(n->left);
        c += count(n->right);
        return c;
    }
}
void binarytoarray(struct node * root, int data[], int *ptr)
{
    if(root != NULL)
    {
    binarytoarray(root->left, data, ptr);
    data[*ptr] = root->info;
    (*ptr)++;
    binarytoarray(root->right, data, ptr);
    }
}
void arraytobst(int *arr, struct node *root, int *index)
{
    if(root != NULL)
    {
        arraytobst(arr, root->left, index);
        root->info = arr[i++];
        arraytobst(arr, root->right, index);
    }
}

int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

void inorder(struct node *root)
{
    if(root !=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}

void binary_to_bst(struct node *root)
{
    int n, i;

    if (root == NULL)
        return;
    n = count(root);
    i = 0;
    binarytoarray(root, data, &i);
    qsort(&data, n, sizeof(data[0]), compare);
    i = 0;
    arraytobst(data, root, &i);
}


int main()
{
    int flag = 0;
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);


    printf("Inorder traversal of Input Binary Tree is\n");
    inorder(newnode);
    binary_to_bst(newnode);
    printf("\nInorder traversal of the converted Binary Search Tree is\n");
    inorder(newnode);
    return 0;
}

