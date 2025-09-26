class Solution {
  public:
  
    int compute(int index,int W,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
        
        if(index==0){
            if(wt[index]<=W) return val[0];
            return 0;
        }
        if(dp[index][W]!=-1) return dp[index][W];
        
        int nonSteal = 0 + compute(index-1,W,val,wt,dp);
        int steal = INT_MIN;
        if(wt[index]<=W) steal = val[index] +compute(index-1,W-wt[index],val,wt,dp);
         dp[index][W]= max(steal,nonSteal);
         return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int index = val.size();
         vector<vector<int>>dp(index,vector<int>(W+1,-1));
         
         return compute(val.size()-1,W,val,wt,dp);
        
    }
};