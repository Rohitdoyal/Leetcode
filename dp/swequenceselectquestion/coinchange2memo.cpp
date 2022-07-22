#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
    int f(int i , int amount , vector<int>& coins, vector<vector<int>>&dp){
        if(i==0){
            return (amount%coins[0]==0);
        }
        
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        
        int not_include = f(i-1,amount , coins,dp);
        int include = 0;
        
        if(amount>=coins[i]){
            include  = f(i,amount-coins[i],coins,dp);
        }
        
        return dp[i][amount] = include+not_include;
        
    }
    
    int change(int amount, vector<int>& coins) {
        if(coins.size()==0){
            return 0;
        }
        
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        
        return f(coins.size()-1, amount,coins,dp);
    }
};
int main(){
    
    return 0;
}