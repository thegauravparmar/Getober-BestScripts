struct comp{
    bool operator()(pair<int,int> a,pair<int,int>b){
        // if capital is same than take greater profit
        if(a.first==b.first) return a.second < b.second;
        return a.first>b.first;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        // It is a max heap in which we will store project which we can take i.e. whose capital is less than net capital
        priority_queue<pair<int,int>>pq;
        
        // It is a min heap in which we will store project which we can not take i.e. whose capital is more than net capital
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>mpq;
        
        int n=profit.size();
        
        for(int i=0;i<n;i++){
            
            if(profit[i]>0){
                
                if(capital[i]>w){
                    //insertig project which has more capital than net capital
                    mpq.push({capital[i],profit[i]});
                }
                
                else{
                    //inserting project which has less or equal capital than net capital
                    pq.push({profit[i],capital[i]});
                }
            }
        }
        // check either k is positive or we have project who have less capital than net capital
        while(k>0 && (!pq.empty())){
            // add the capital with max profit project
            w += pq.top().first;
            pq.pop();
            k--;
            // transfer project which we can now take after updating capital
            while(!mpq.empty() && w>=mpq.top().first){
                pq.push({mpq.top().second,mpq.top().first});
                mpq.pop();
            }
        }
        return w;
        
    }
};
