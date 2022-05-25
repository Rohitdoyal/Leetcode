#include<bits/stdc++.h> 
using namespace std;


//recursive approach 
class Solution {
public:
    
    int ans(vector<int>& cost,int i){
        if(i>=cost.size()){
            return 0;
        }
        else{
            return cost[i]+min(ans(cost,i+1),ans(cost,i+2));
        }
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(ans(cost,0),ans(cost,1));
        
        
    }
};

//dp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i =2; i<cost.size(); i++){
            cost[i]= cost[i]+min(cost[i-1],cost[i-2]);
        }
        int n = cost.size();
        return min(cost[n-1],cost[n-2]);
        
    }
};

int main(){
    
    return 0;
}