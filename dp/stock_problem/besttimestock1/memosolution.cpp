#include<bits/stdc++.h> 
using namespace std;

int main(){
    
    return 0;
}


class Solution {
public:
    
    //RECURSIVE SOLUTION 
    int f(int i,  int buy , vector<int>&price,vector<vector<int>>&dp ){
        
        if(i>=price.size()){
            return 0;
        }
        
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==1){
            return dp[i][buy]=max(-price[i]+f(i+1,0,price,dp),
                      f(i+1,1,price,dp));    
        }
        
        else{
            return dp[i][buy]=max(price[i]+f(i+2,1,price,dp),
                      f(i+1,0,price,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};