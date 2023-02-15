#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int LCS[s1.size()+1][s2.size()+1] = {0};
    for(int i=0; i<s1.size()+1; i++)
    {
        LCS[i][0] = 0;
    }
    for(int i=0; i<s2.size()+1; i++)
    {
        LCS[0][i] = 0;
    }
    for(int i=1; i<s1.size()+1; i++)
    {
        for(int j=1; j<s2.size()+1; j++)
        {
            if(s1[i-1] == s2[j-1])
                LCS[i][j] = LCS[i-1][j-1]+1;
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    cout<<"THE DP TABLE FORMED IS AS FOLLOWS"<<endl;
    for(int i=0; i<s1.size()+1; i++)
    {
        for(int j=0; j<s2.size()+1; j++)
        {
            cout<<LCS[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"THE LENGTH LONGEST COMMON SUBSEQUENCE IS "<<LCS[s1.size()][s2.size()];


    return 0;
}
