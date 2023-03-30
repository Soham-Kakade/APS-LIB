/*create a class for complex number with data members: int real,imz

and member functions: print()*/

#include<iostream>

using namespace std;

class complexN
{
    private:
      int x;
      int y;
    public:
      void setx(int i,int j)
      {
          x=i;
          y=j;
      }
      void getx()
      {
           cout<<"value of complex number is" <<x<< "+j*" <<y<<endl;
      }
};

int main()
{
    complexN ob1;
    int i,j;
    cin>>i;
    cin>>j;
    ob1.setx(i,j);
    ob1.getx();
}