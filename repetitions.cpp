#include<iostream>
#include <bits/stdc++.h>
#include<string.h>

using namespace std;
const int maxN = 1e6+5;

char S[maxN];
int N, cnt, maxc;

int main(){
    cin>>S;
    N = (int) strlen(S);
    cnt = maxc = 1;
    for(int i = 1; i < N; i++){
        if(S[i] == S[i-1])  cnt++;
        else                cnt = 1;
        maxc = max(maxc, cnt);
    }
    cout<<maxc;
}
