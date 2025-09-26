class Solution {
  public:
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
         vector<int>prev(W+1,0);
         vector<int>curr(W+1,0);
         
         for(int i=wt[0];i<=W;i++) prev[i] = val[0];
         
         for(int index=1;index<n;index++){
             for(int weight = 0;weight<=W;weight++){
                 int nonSteal = 0+prev[weight];
                 int steal = INT_MIN;
                 if(wt[index]<=weight) steal = val[index] + prev[weight-wt[index]];
                 curr[weight]=max(steal,nonSteal);
             }
            prev=curr;
         }
         
         
         return prev[W];
        
    }
};