// User function Template for C++

class Solution {
  public:
    int selections(int index,int capacity,vector<int>&wt,vector<int>&val){
        if(index==0){
            return ((capacity/wt[0]))*val[0];
        }
        
        int nonTake = 0+selections(index-1,capacity,wt,val);
        int take = INT_MIN;
        if(wt[index]<=capacity) take = val[index]+ selections(index,capacity-wt[index],wt,val);
        return max(take,nonTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        return selections(val.size()-1,capacity,wt,val);
        
    }
};