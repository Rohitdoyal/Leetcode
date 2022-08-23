#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
    int f(int i, string s,vector<int>&dp){
        if(i==s.length()){
            return 1;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int count =0;
        if(s[i]!='0'){
            count += f(i+1,s,dp);
        }
        
        if((i+1<s.length()) && (s[i]=='1'||(s[i]=='2') && (s[i+1]<='6'))){
                count += f(i+2,s,dp);
        }
        return dp[i]=count;
        
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[n]= 1;
        
        for(int i =n-1; i>=0; i--){
            int count =0;
            if(s[i]!='0'){
                count += dp[i+1];
            }

            if((i+1<n) && (s[i]=='1'||(s[i]=='2') && (s[i+1]<='6'))){
                    count += dp[i+2];
            }
            dp[i]=count;
        }
        return dp[0];
    }
};
int main(){
    
    return 0;
}