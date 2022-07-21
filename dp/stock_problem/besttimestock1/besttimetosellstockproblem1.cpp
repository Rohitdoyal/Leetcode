#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //now let's right bottom up --tabular 
        //change the limit 
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        
        for(int i = n-1; i>=0; i--){
            for(int buy =1; buy>=0; buy--){
                if(buy==1){
                   dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);    
                }

                else{
                   dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};
int main(){
    
    return 0;
}

class Solution2 {
public:
    
    int maxProfit(vector<int>& prices) {
        //now let's right bottom up --tabular 
        //change the limit 
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i = n-1; i>=0; i--){
    
                   dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);    
                   dp[i][0]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        
        return dp[0][1];
    }
};