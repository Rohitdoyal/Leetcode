#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    
    int f(int n , int T, vector<int>&coin,vector<vector<int>>&dp){
        
        //base case
        if(n==0){
            if(T%coin[n]==0){
                return (T/coin[n]);
            }
            return 1e9;
        }
        
        if(dp[n][T]!=-1){
            return dp[n][T];
        }
        
        
        int not_take = f(n-1,T,coin,dp);
        int take =INT_MAX;
        
        if(coin[n]<=T){
            take= 1+f(n,T-coin[n],coin,dp);
        }
        
        return dp[n][T] = min(take,not_take);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
    
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1));
            int ans =f(n-1,amount, coins,dp);
        if(ans==1e9){
            ans =-1;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}