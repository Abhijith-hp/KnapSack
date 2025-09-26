class Solution {
  public:
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
         vector<vector<int>>dp(n,vector<int>(W+1,0));
         
         for(int i=wt[0];i<=W;i++) dp[0][i] = val[0];
         
         for(int index=1;index<n;index++){
             for(int weight = 0;weight<=W;weight++){
                 int nonSteal = 0+dp[index-1][weight];
                 int steal = INT_MIN;
                 if(wt[index]<=weight) steal = val[index] + dp[index-1][weight-wt[index]];
                 dp[index][weight]=max(steal,nonSteal);
             }
         }
         
         return dp[n-1][W];
        
    }
};