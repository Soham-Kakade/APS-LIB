class Solution
{
    public:
    int countSubstring(string S)
    {
        vector<int> a, b;
        int count = 0;
        for(int i=0; i<S.size(); i++) {
            if(97 <= S[i] && S[i] <=122) {
                a.push_back(1);
                b.push_back(0);
                for(int j=0; j<a.size()-1; j++) a[j]++;
            }
            else if(65 <= S[i] && S[i] <=90) {
                a.push_back(0);
                b.push_back(1);
                for(int j=0; j<b.size()-1; j++) b[j]++;
            }
            for(int j=0; j<b.size(); j++) {
                if(a[j] == b[j]) 
                    count++;
            }
        }
        return count;
        // code here
    }
};
