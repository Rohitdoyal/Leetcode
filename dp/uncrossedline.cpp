#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    int f(int i , int j , vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(i==0){
            return 0;
        }    
        if(j==0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(nums1[i-1]==nums2[j-1]){
            return dp[i][j]  = max(1+f(i-1,j-1,nums1,nums2,dp),max(f(i-1,j,nums1,nums2,dp),f(i,j-1,nums1,nums2,dp)));
        }
        
        else{
            return dp[i][j] = max(f(i-1,j,nums1,nums2,dp),f(i,j-1,nums1,nums2,dp));
        }
        
    }
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        //memozation 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
       for(int i=0; i<n+1; i++){
           dp[i][0]=0;
       }
        
        for(int j =0; j<m+1;j++){
            dp[0][j]=0 ;
        }
        
        for(int i =1; i<n+1; i++){
            for(int j =1; j<m+1; j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]  = max(1+dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                }

                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return  dp[n][m];
    }
};
int main(){
    
    return 0;
}