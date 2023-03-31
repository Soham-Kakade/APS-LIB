#include <bits/stdc++.h>
using namespace std;
int getMaxXOR(int L, int R){
   int LXR = L ^ R;
   int msbPos = 0;
   while (LXR) {
      msbPos++;
      LXR >>= 1;
   }
   int maxXOR = 0;
   int two = 1;
   while (msbPos--) {
      maxXOR += two;
      two <<= 1;
   }
   return maxXOR;
}
int main(){
   int L = 1;
   int R = 21;
   cout<< getMaxXOR(L, R) << endl;
   return 0;
}
