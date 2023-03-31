class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            vector<int> b;
            b = a;
            // sort(b.begin(), b.end(), greater<int>());
            // for(int i=0; i<b.size(); i++)   cout<<b[i]<<" ";
            // int f = 1;
            // while(f == 1) {
            //     f = 0;
                for(int i=0; i<b.size()-1; i++){
                    if(((b[i] + b[i+1]) % 2 == 0) && (b[i] < b[i+1])) {
                        int t = b[i];
                        b[i] = b[i+1];
                        b[i+1] = t;
                        for(int j=i; j>0; j--) {
                            if((b[j]+b[j-1]) %2 == 0 && (b[j] > b[j-1])) {
                                t = b[j];
                                b[j] = b[j-1];
                                b[j-1] = t;
                            }
                            else 
                                break;
                        }
                    }
                }
            // }
            return b;
        }
};
