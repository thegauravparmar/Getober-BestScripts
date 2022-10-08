//leetcode palindrome partitioning

class Solution {
public:
    bool ispalindrome(string s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    void palindromepartition(vector<vector<string>>&res, vector<string>&path,string s, int index)
    {
        if(index>=s.length())
        {
            res.push_back(path);
            return;
        }
        
        for(int i=index;i<s.length();i++)
        {
            if(ispalindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                palindromepartition(res,path,s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>res;
        vector<string>path;
        
        palindromepartition(res,path,s,0);
        
        return res;
    }
    
};
