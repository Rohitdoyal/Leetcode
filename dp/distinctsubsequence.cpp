#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    int f(string s, string t, int i , int j,vector<vector<int>>&dp){
        
        if(j==t.length()){return 1;}
        if(i>=s.length()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int include =0;
        if(s[i]==t[j]){
            include = f(s,t,i+1,j+1,dp);
        }
        int notinclude  = f(s,t,i+1,j,dp);
        
        return dp[i][j] = include+notinclude;
    }
    
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i =0; i<s.length(); i++){
            dp[i][0]=1;
        }
        
        for(int i =1; i<n+1; i++){
            for(int j =1; j<m+1; j++){
                long long int include =0;
                if(s[i-1]==t[j-1]){
                    include = dp[i-1][j-1];
                }
                int notinclude  = dp[i-1][j];

                dp[i][j] = include+notinclude;
            }
        }
        
        return dp[n][m];
    }
};



//memo solution 
// class Solution {
// public:
    
//     int f(string s, string t, int i , int j,vector<vector<int>>&dp){
        
//         if(j==t.length()){return 1;}
//         if(i>=s.length()){
//             return 0;
//         }
        
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int include =0;
//         if(s[i]==t[j]){
//             include = f(s,t,i+1,j+1,dp);
//         }
//         int notinclude  = f(s,t,i+1,j,dp);
        
//         return dp[i][j] = include+notinclude;
//     }
    
    
//     int numDistinct(string s, string t) {
//         int n = s.length();
//         int m = t.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return f(s,t,0,0,dp);
//     }
// };
int main(){
    
    return 0;
}