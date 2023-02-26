#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lt,*rt;
    int ht;
}node;

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int geth(node *n)
{
    if(n == NULL)
        return 0;

    return n->ht;
}

int getbf(node *n)
{
    if(n == NULL)
        return 0;

    return (geth(n->lt) - geth(n->rt));
}

node *create(int x)
{
    node *n= (node*)malloc(sizeof(node));
    n->data = x;
    n->lt = NULL;
    n->rt = NULL;
    n->ht = 1;

    return(n);
}

node *rightr(node *y)
{
    node *x = y->lt;
    node *T2 = x->rt;

    x->rt = y;
    y->lt = T2;

    x->ht = max(geth(x->lt), geth(x->rt))+1;
    y->ht = max(geth(y->lt), geth(y->rt))+1;

    return x;
}

node *leftr(node *x)
{
    node *y = x->rt;
    node *T2 = y->lt;

    y->lt = x;
    x->rt = T2;

    x->ht = max(geth(x->lt), geth(x->rt))+1;
    y->ht = max(geth(y->lt), geth(y->rt))+1;

    return y;
}

node *in(node *r, int x)
{
    if(r == NULL)
    {
        return create(x);
    }
    if(x>r->data)
    {
        r->rt = in(r->rt, x);
    }
    else if(x<r->data)
    {
        r->lt = in(r->lt, x);
    }
    else
        return r;

    r->ht= max(geth(r->lt), geth(r->rt))+1;
    int bf = getbf(r);

    //left left
    if(bf >1 && x < r->lt->data)
       {return rightr(r);}

    //right right
    if(bf <-1 &&x > r->rt->data)
        {return leftr(r);}

    //left right
    if(bf >1  && x > r->lt->data)
        {r->lt = leftr(r->lt);
        return(rightr(r));}

    //right left
    if(bf <-1  && x < r->rt->data)
        {r->rt = rightr(r->rt);
        return(leftr(r));}

    return r;
}

void pre(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        pre(root->lt);
        pre(root->rt);
    }
}

node *ipres(node *r)
{
    r = r->lt;
    while(r->rt != NULL)
    {
        r = r->rt;
    }
    return(r);
}

node *del(node *r, int x)
{
    if(r == NULL)
    {
        return NULL;
    }
    else if(r->lt == NULL && r->rt == NULL)
    {
        free(r);
        return NULL;
    }

    if(x>r->data)
        r->rt = del(r->rt,x);
    else if(x<r->data)
        r->lt = del(r->lt,x);
    else
    {
        node *ipre = ipres(r);
        r->data = ipre->data;
        r->lt = del(r->lt, ipre->data);
    }
    return r;
}

int main()
{
    node *root = NULL;
    root = in(root, 1);
    root = in(root, 2);
    root = in(root, 3);
    root = in(root, 4);
    root = in(root, 5);
    root = in(root, 6);

    root - del(root, 4);
    cout<<root->data<<endl;
    pre(root);

    return(0);
}
