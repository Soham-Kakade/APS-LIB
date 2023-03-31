#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
    TreeNode (int x):val (x), left (NULL), right (NULL)
  { }
};

void bfs (TreeNode * root)
{
  queue q;
  q.push (root);

  while (!q.empty ())
    {
      int num_nodes = q.size ();

      for (int i = 0; i < num_nodes; i++)
	{
	  TreeNode *curr_node = q.front ();
	  q.pop ();

	  cout << curr_node->val << " ";

	  if (curr_node->left)
	    {
	      q.push (curr_node->left);
	    }
	  if (curr_node->right)
	    {
	      q.push (curr_node->right);
	    }
	}
    }
}

int main ()
{
  TreeNode *root = new TreeNode (10);
  root->left = new TreeNode (20);
  root->right = new TreeNode (30);
  root->left->left = new TreeNode (40);
  root->left->right = new TreeNode (50);
  cout<<"BFS Traversal of the tree is : ";
  bfs (root);

  return 0;
}
