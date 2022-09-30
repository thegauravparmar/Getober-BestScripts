class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int> &temp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int curr = temp[i-1]*temp[k]*temp[j+1] + solve(i,k-1,temp) + solve(k+1,j,temp); 
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        temp.push_back(1);
        temp.insert(temp.begin(),1);
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return solve(1,n,temp);
        
    }
};
