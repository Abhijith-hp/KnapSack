class Solution {
  public:
  
    int compute(int index,int W,vector<int>&val,vector<int>&wt){
        
        if(index==0){
            if(wt[index]<=W) return val[0];
            return 0;
        }
        
        int nonSteal = 0 + compute(index-1,W,val,wt);
        int steal = INT_MIN;
        if(wt[index]<=W) steal = val[index] +compute(index-1,W-wt[index],val,wt);
         return max(steal,nonSteal);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
         return compute(val.size()-1,W,val,wt);
        
    }
};