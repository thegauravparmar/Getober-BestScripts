class Solution {
public:
    int areaForOneRow(vector<int> heights, int m){
            stack<int>s;
            s.push(-1);
            int k=0;
            int area=0;
            while(k<m){
                if(s.top()==-1 || heights[k]>=heights[s.top()]){
                    s.push(k++);
                }
                else{
                    int top = s.top();
                    s.pop();
                    int temp = heights[top]*(k-s.top()-1);
                    area=max(temp,area);
                }
            }
            while(s.top()!=-1){
                int top = s.top();
                s.pop();
                int temp = heights[top]*(k-s.top()-1);
                area=max(temp,area);
            }
        return area;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!='0') heights[j]+=(matrix[i][j]-'0');
                else heights[j]=0;
            }
            cout<<endl;
            int curr = areaForOneRow(heights,m);
            ans=max(curr,ans);
        }
        return ans;
    }
};
