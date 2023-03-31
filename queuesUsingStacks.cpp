#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
  stack < int >s;
  int size;
    Queue ()
  {
    size = 0;
  }
  void Push (int i)
  {
    cout << "Pushing the element : " << i << endl;
    s.push (i);
    size++;
  }
  int pop ()
  {
    if (size == 0)
      {
	cout << "The Queue is empty" << endl;
	return 0;
      }
    int a = s.top ();
    s.pop ();
    if (!s.empty ())
      {
	int b = pop ();
	s.push (a);
	return b;
      }
    else
      {
	cout << "Popping " << a << endl;
	size--;
      }
    return a;

  }
  void display ()
  {
    if (size == 0)
      {
	cout << "The Queue is empty" << endl;
	return;
      }
    int a = s.top ();
    s.pop ();
    if (!s.empty ())
      display ();
    cout << a << " ";
    s.push (a);
  }
  int front ()
  {
    if (size == 0)
      {
	cout << "The Queue is empty" << endl;
      }
    int b, a = s.top ();
    s.pop ();
    if (!s.empty ())
      {
	int b = front ();
	s.push (a);
	return b;
      }
    else
      b = a;
    s.push (a);
    return a;
  }
  bool empty ()
  {
    return size == 0;
  }
};

int main ()
{
  Queue q;
  q.Push (1);
  q.Push (5);
  q.Push (2);
  q.Push (11);
  q.display ();
  cout << endl;
  cout << "The front most value right now is : " << q.front () << endl;
  q.pop ();
  q.pop ();
  q.Push (12);
  q.Push (8);
  cout << "The front most value right now is : " << q.front () << endl;
  q.display ();
  cout << endl;
}
