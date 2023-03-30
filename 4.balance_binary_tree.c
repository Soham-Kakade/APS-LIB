#include <stdio.h>

    #include <stdlib.h>

    struct btnode

    {

        int value;

        struct btnode *l;

        struct btnode *r;

    };

    typedef struct btnode N;

    N* bst(int arr[], int first, int last);

    N* new(int val);

    void display(N *temp);

    int main()

    {

        int arr[] = {10, 20, 30, 40, 60, 80, 90};

        N *root = (N*)malloc(sizeof(N));

        int n = sizeof(arr) / sizeof(arr[0]), x;

        printf("Given sorted array is\n");

        for (x = 0;x < n;x++)

            printf("%d\t", arr[x]);

        root = bst(arr, 0, n - 1);

        printf("\n The preorder traversal of binary search tree is as follows\n");

        display(root);

        printf("\n");

        return 0;

    }

    N* new(int val)

    {

        N* node = (N*)malloc(sizeof(N));

        node->value = val;

        node->l = NULL;

        node->r  =  NULL;

        return node;

    }

    N* bst(int arr[], int first, int last)

    {

        int mid;

        N* temp = (N*)malloc(sizeof(N));

        if (first > last)

            return NULL;

        mid = (first + last) / 2;

        temp = new(arr[mid]);

        temp->l = bst(arr, first, mid - 1);

        temp->r = bst(arr, mid + 1, last);

        return temp;

    }

    void display(N *temp)

    {

        printf("%d->", temp->value);

        if (temp->l != NULL)

            display(temp->l);

        if (temp->r != NULL)

            display(temp->r);

    }
