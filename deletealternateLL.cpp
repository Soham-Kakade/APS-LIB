#include<iostream>
using namespace std;

struct node
{
  int num;
  node *nextptr;
} *stnode;			//node declared

void make (int n);
void alternateDel (node * stnode);
void display ();


int main ()				//main method
{
  int n, num;

  cout << "Enter the number of nodes: ";
  cin >> n;
  make (n);
  cout << "\nLinked list data: \n";
  display ();
  cout << "\nAfter deleting alternate node:\n";
  alternateDel (stnode);
  display ();
  return 0;
}

void make (int n)			//function to create linked list.
{
  struct node *frntNode, *tmp;
  int num, i;

  stnode = (struct node *) malloc (sizeof (struct node));
  if (stnode == NULL)
    {
      cout << " Memory can not be allocated";
    }
  else
    {

      cout << "Enter the data for node 1: ";
      cin >> num;
      stnode->num = num;
      stnode->nextptr = NULL;	//Links the address field to NULL
      tmp = stnode;

      for (i = 2; i <= n; i++)
	{
	  frntNode = (struct node *) malloc (sizeof (struct node));


	  if (frntNode == NULL)	//If frntnode is null no memory cannot be alloted
	    {
	      cout << "Memory can not be allocated";
	      break;
	    }
	  else
	    {
	      cout << "Enter the data for node " << i << ": ";	// Entering data in nodes.
	      cin >> num;
	      frntNode->num = num;
	      frntNode->nextptr = NULL;
	      tmp->nextptr = frntNode;
	      tmp = tmp->nextptr;
	    }
	}
    }
}

void display ()			//function to display linked list
{
  struct node *tmp;
  if (stnode == NULL)
    {
      cout << "List is empty";
    }
  else
    {
      tmp = stnode;
      cout << "Linked List\t";
      while (tmp != NULL)
	{
	  cout << tmp->num << "\t";
	  tmp = tmp->nextptr;
	}
    }
}

void alternateDel (node * stnode)	//function to delete alternate nodes.
{
  if (stnode == NULL)
    return;


  node *prev = stnode;
  node *alt_node = stnode->nextptr;

  while (prev != NULL && alt_node != NULL)
    {

      prev->nextptr = alt_node->nextptr;

      free (alt_node);

      prev = prev->nextptr;
      if (prev != NULL)
	alt_node = prev->nextptr;
    }
}
