#include<iostream>
using namespace std ;

typedef struct node
{
    int a;
    struct node *lt,*rt;
}Node;

Node* create()
{
    Node *n = (Node*)malloc(sizeof(Node));
    cout<<"Enter the data u want \n";
    cin>>n->a;
    n->lt = NULL;
    n->rt = NULL;
    return(n);
}

Node* inserte(Node *root)
{
    Node *m = create();
    if(root == NULL)
    {
        root = m;
    }
    else
    {
        Node *temp = root;
        Node *t ;
        while(temp != NULL)
        {
            t=temp;
            if(temp->a >m->a)
            {
                temp = temp->lt;
            }
            else
                temp = temp->rt;
        }
        if(t->a > m->a)
        {
            t->lt = m;
        }
        else
            t->rt = m;
    }
    return(root);
}

void print(Node *root)
{
    if(root != NULL)
    {
        Node *temp = root;
        print(temp->lt);
        cout<<temp->a<<" ";
        print(temp->rt);
    }
}

int searchh(Node *root,int key)
{
    if(root == NULL || root->a == key)
    {
        return(root->a);
    }
    while(root != NULL)
    {
      if(key>root->a)
      {
        return(searchh(root->rt,key));
      }
      else
      {
        return(searchh(root->lt,key));
      }
    }
}

Node * minval(Node *root)
{
    Node* temp = root;
    while(temp && temp->lt != NULL)
    {
        temp = temp->lt;
    }
    return(temp);
}

Node * deletee(Node *root, int key)
{
    if(root == NULL)
    {
        return(root);
    }
    if(key < root->a)
    {
        root->rt = deletee(root->rt, key);
    }
    else if(root->a <key)
    {
        root->lt = deletee(root->lt,key);
    }
    else
    {
        if(root->lt ==NULL && root -> rt == NULL)
        {
            return(NULL);
        }
        else if(root->lt == NULL)
        {
            Node *temp = root->rt;
            free(root);
            return(temp);
        }
        else if(root->rt == NULL)
        {
            Node *temp = root->lt;
            free(root);
            return(temp);
        }
        Node *t = minval(root->rt);
        root->a = t->a;
        root->rt = deletee(root->rt, t->a);
    }
    return(root);
}

int main()
{
    Node *root = NULL;
    root =inserte(root);
    root =inserte(root);
    root =inserte(root);
    root =inserte(root);
    print(root);
    cout<<"\n";
    //cout<<"SEARCHING \n"<<searchh(root, 6)<<endl;
    root = deletee(root, 4);
    print(root);
    return (0);
}
