#include<bits/stdc++.h>
using namespace std;
class Tree
{
public:
  int data;
  Tree *left = NULL, *right = NULL;
  // Constructor initialised
    Tree (int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};
void preorder_traversal (Tree * root)
{
  if (root == NULL)
    return;
  // Print the data
  cout << root->data << " ";
  // Visit Left subtree
  preorder_traversal (root->left);
  // Visit right subtree
  preorder_traversal (root->right);
}

void inorder_traversal (Tree * root)
{
  if (root == NULL)
    return;
  // Visit Left subtree
  inorder_traversal (root->left);
  // Print the data
  cout << root->data << " ";
  // Visit right subtree
  inorder_traversal (root->right);
}

void postorder_traversal (Tree * root)
{
  if (root == NULL)
    return;
  // Visit Left subtree
  postorder_traversal (root->left);
  // Visit right subtree
  postorder_traversal (root->right);
  // Print the data
  cout << root->data << " ";
}

int main ()
{
  Tree *root = new Tree (17);
  root->left = new Tree (10);
  root->right = new Tree (11);
  root->left->left = new Tree (7);
  root->right->left = new Tree (27);
  root->right->right = new Tree (9);
  cout << "Preorder => ";
  preorder_traversal (root);
  cout << endl;
  cout << "Inorder => ";
  inorder_traversal (root);
  cout << endl;
  cout << "Postorder => ";
  postorder_traversal (root);
  cout << endl;
  return 0;
}
