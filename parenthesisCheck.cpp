class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        vector<char> open;
        for(int i=0; i<x.size(); i++) {
            if(x[i] == ')') {
                if(open.size() == 0 || open.back() != '(')
                    return false;
                open.pop_back();
            }
            else if(x[i] == ']') {
                if(open.size() == 0 || open.back() != '[')
                    return false;
                open.pop_back();
            }
            else if(x[i] == '}') {
                if(open.size() == 0 || open.back() != '{')
                    return false;
                open.pop_back();
            }
            else
                open.push_back(x[i]);
        }
        if(open.size() == 0)
            return true;
        return false;
    }
