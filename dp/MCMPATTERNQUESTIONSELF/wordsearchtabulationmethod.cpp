#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    bool f(int i ,string s,unordered_map<string,int>&isit,vector<int>&dp){
        if(i==s.length()){
            return true;
        }
        
        if(dp[i]!=-1){
            return (dp[i]==0)?(false):(true);
        }
        for(int k = i; k<s.length(); k++){
            string r= s.substr(i,k-i+1);
          
            if((isit[r]==1) && (f(k+1,s,isit,dp)==true)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>isit;
        for(auto x: wordDict){isit[x]=1;}
        
        int n = s.length();
        vector<bool>dp(n+1,false);
        
        dp[n]= true;
        for(int i =n-1; i>=0;i--){
            bool flag = false;
            for(int k = i; k<n; k++){
                string r= s.substr(i,k-i+1);
                if((isit[r]==1) && (dp[k+1]==true))
                    {flag = true;
                    break;}
            }
            dp[i] = flag;
        }
        
        return dp[0];
        
    }
};

int main(){
    
    return 0;
}