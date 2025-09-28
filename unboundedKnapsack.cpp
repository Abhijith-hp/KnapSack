// User function Template for C++

class Solution {
  public:
    int selections(int index,int capacity,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
        if(index==0){
            return ((capacity/wt[0]))*val[0];
        }
        if(dp[index][capacity]==-1) return dp[index][capacity];
        
        int nonTake = 0+selections(index-1,capacity,wt,val,dp);
        int take = INT_MIN;
        if(wt[index]<=capacity) take = val[index]+ selections(index,capacity-wt[index],wt,val,dp);
        dp[index][capacity]=max(take,nonTake);
        return dp[index][capacity];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>> dp(val.size(), vector<int>(capacity + 1, 0));
        return selections(val.size()-1,capacity,wt,val,dp);
        
    }
};