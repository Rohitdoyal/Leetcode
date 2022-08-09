#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    int index(vector<int>& cuts, int i){
        if(i<0){return 0;}
        if(i>=cuts.size()){
            return cuts.back();
        }
        return cuts[i];
    }
    
    int f(int i ,int j,vector<int>& cuts,vector<vector<int>>&dp ){
        //base case 
        if(i>j){return 0;}
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k<=j; k++){
            int len = index(cuts,j+1)-index(cuts,i-1);
            int cost = len+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        
        int j = cuts.size()-2;
        //i: 0 ->n
        vector<vector<int>>dp(j+2,vector<int>(j+2,-1));
        return f(0,j,cuts,dp);
        
    }
};
int main(){
    
    return 0;
}