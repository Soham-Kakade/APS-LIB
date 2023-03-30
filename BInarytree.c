#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *lt, *rt;
} * Node;

Node getnode()
{
    Node newNode = (Node)malloc(sizeof(Node));
    if (newNode == NULL) //if memory is not allocated
    {
        printf("Not able to add \n");
        exit(0);
    }
    else
    {
        printf("Enter the Number \n");
        scanf("%d", &newNode->item);
        newNode->rt = NULL;
        newNode->lt = NULL;
    }
    return (newNode);
}

Node insert(Node r)
{
    Node s = getnode();
    if (r == NULL)
    {
        r = s;
    }
    else
    {
        Node t = r;
        Node prev = NULL;
        while (t != NULL)
        {
            prev = t;
            if (s->item < t->item)
            {
                t = t->lt;
            }
            else
            {
                t = t->rt;
            }
        }
        if (prev->item < s->item)
        {
            prev->rt = s;
        }
        else if (prev->item > s->item)
        {
            prev->lt = s;
        }
    }
    return (r);
}

void Pre_traverse(Node r)
{
    if (r != NULL)
    {
        printf("%d \t", r->item);
        Pre_traverse(r->lt);
        Pre_traverse(r->rt);
    }
}

void In_order(Node r)
{
    if (r != NULL)
    {
        In_order(r->lt);
        printf("%d \t", r->item);
        In_order(r->rt);
    }
}

void post_order(Node r)
{
    if (r != NULL)
    {
        post_order(r->lt);
        post_order(r->rt);
        printf("%d \t", r->item);
    }
}

int search(Node r, int key)
{
    if (r == NULL || r->item == key)
    {
        return (r->item);
    }
    while (r != NULL)
    {
        if (key > r->item)
        {
            search(r->rt, key);
        }
        else
        {
            search(r->lt, key);
        }
    }
}

int main()
{
    Node h = NULL;
    int choice;
    int data;
    while (1)
    {
        printf("\n1. To enter a new Item \n");
        printf("2. Display Pre Order Traverse \n");
        printf("3. Display IN order Traverse \n");
        printf("4. Display post Order traversal \n");
        printf("5. Search for Key \n");
        printf("6. Exit \n");
        printf("Enter your Choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            h = insert(h);
            break;

        case 2:
            Pre_traverse(h);
            break;

        case 3:
            In_order(h);
            break;

        case 4:
            post_order(h);
            break;

        case 5:
            printf("Enter the Element you want to search\n");
            scanf("%d", &data);
            int r = search(h, data);
            if (r == data)
            {
                printf("The search was successful \n");
            }
            else
            {
                printf("The search was unsuccessful \n");
            }
            break;

        default:
            exit(0);
        }
    }
    return (1);
}