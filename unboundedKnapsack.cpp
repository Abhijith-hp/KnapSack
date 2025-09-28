    // User function Template for C++
    
    class Solution {
      public:
      
        int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
            vector<vector<int>> dp(val.size(), vector<int>(capacity + 1, 0));
            vector<int>current(capacity+1,0);
            for(int i=0;i<=capacity;i++)
                current[i] = (i/wt[0]) * val[0];
            
            for(int i=1;i<val.size();i++){
                for(int j=0;j<=capacity;j++){
                   int nonTake = 0+current[j];
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i]+ current[j-wt[i]];
            current[j]=max(take,nonTake); 
                }
            }
            return current[capacity];
            
        }
    };