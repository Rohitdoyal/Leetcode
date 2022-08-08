#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    //edit distance famous question done 
    
    int f(int i , string s, int j , string t ,vector<vector<int>>&dp){
        if(i==-1){
            return j+1;
        }
        if(j==-1){
            return i+1;
        }
        
        if(dp[i][j]!=-1){return dp[i][j];}
        
        if(s[i]==t[j]){
            return dp[i][j] =f(i-1,s,j-1,t,dp);
        }
        
        else{
            return dp[i][j] = min(1+f(i,s,j-1,t,dp),
                   min(1+f(i-1,s,j,t,dp),
                       1+f(i-1,s,j-1,t,dp)));
        }
        
        
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,word1,m-1,word2,dp);
    }
};



class Solution1 {
public:

//edit distance famous question done 

int f(int i , string s, int j , string t ,vector<vector<int>>&dp){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    
    if(dp[i][j]!=-1){return dp[i][j];}
    
    if(s[i-1]==t[j-1]){
        return dp[i][j] =f(i-1,s,j-1,t,dp);
    }
    
    else{
        return dp[i][j] = min(1+f(i,s,j-1,t,dp),
               min(1+f(i-1,s,j,t,dp),
                   1+f(i-1,s,j-1,t,dp)));
    }
    
    
}

int minDistance(string word1, string word2) {
    
    int n = word1.length();
    int m = word2.length();
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return f(n,word1,m,word2,dp);
}
};





class Solution2 {
public:
    
    //edit distance famous question done 
    
    
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int j =0; j<m+1; j++){
            dp[0][j]= j;
        }
        
        for(int i =0; i<n+1; i++){
            dp[i][0]= i ;
        }
        
        for(int i =1; i<n+1; i++){
            for(int j =1; j<m+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(1+dp[i-1][j],min(1+dp[i-1][j-1],1+dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m];
    }
};
int main(){
    
    return 0;
}