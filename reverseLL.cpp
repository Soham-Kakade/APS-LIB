#include<iostream>
using namespace std;

struct node
{
  int num;
  node *nextptr;
} *stnode;			//node constructed

void listBanao (int n);
void reverse (node * stnode);

int main ()
{
  int n, num, item;

  cout << "Enter the number of nodes: ";
  cin >> n;
  listBanao (n);
  cout << "After reversing\n";
  reverse (stnode);

  return 0;
}

void listBanao (int n)		//function to create linked list.
{
  struct node *frntNode, *tmp;
  int num, i;

  stnode = (struct node *) malloc (sizeof (struct node));
  if (stnode == NULL)
    {
      cout << "Memory can not be allocated";
    }
  else
    {

      cout << "Enter the data for node 1: ";
      cin >> num;
      cout << "\n";
      stnode->num = num;
      stnode->nextptr = NULL;	//Links the address field to NULL
      tmp = stnode;

      for (i = 2; i <= n; i++)
	{
	  frntNode = (struct node *) malloc (sizeof (struct node));


	  if (frntNode == NULL)
	    {
	      cout << "Memory can not be allocated";
	      break;
	    }
	  else
	    {
	      cout << "Enter the data for node " << i << ": ";
	      cin >> num;
	      cout << "\n";
	      frntNode->num = num;
	      frntNode->nextptr = NULL;
	      tmp->nextptr = frntNode;
	      tmp = tmp->nextptr;
	    }
	}
    }
}


void reverse (node * stnode)
{
  if (stnode == NULL)
    return;
  reverse (stnode->nextptr);

  cout << stnode->num << "\t";
}
