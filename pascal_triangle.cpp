#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Pascal(int n)
{
    int row = n;
    int column[n];
    for(int i=0; i<n; i++)
    {
        column[i] = i+1;
    }
    vector<vector<int>> vec(row);
    for(int i = 0; i < row; i++)
    {
        int col = column[i];
        vec[i] = vector<int>(col);
        for(int j = 0; j < col; j++)
        {
            if(j == 0 || j == col-1)
                vec[i][j] = 1;
            else
                vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
        }
    }
    int o = row;
    for(int i = 0; i < row; i++)
    {
        for(int k=0; k<o/2 + 1; k++)
            cout<<" ";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
        o--;
    }
    return vec;
}
int main()
{
    int n;
    cout<<"Enter the number of rows in Pascals triangle \n";
    cin>>n;
    vector<vector<int> > p = Pascal(n);
    return 0;
}
