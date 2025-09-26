class Solution {
  public:
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
         
         vector<int>prev(W+1,0);
       
         
         for(int i=wt[0];i<=W;i++) prev[i] = val[0];
         
         for(int index=1;index<n;index++){
             for(int weight = W;weight>=0;weight--){
                 int nonSteal = 0+prev[weight];
                 int steal = INT_MIN;
                 if(wt[index]<=weight) steal = val[index] + prev[weight-wt[index]];
                 prev[weight]=max(steal,nonSteal);
             }
         
         }
         
         
         return prev[W];
        
    }
};