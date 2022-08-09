#include<bits/stdc++.h> 
using namespace std;


//good solution 


class Solution {
public:
    //s is pattern 
    
    bool f(int i , int j , string &s, string &t,vector<vector<int>>&dp){
        if(i<0 &&(j<0)){return true;}
        
        if((i<0)&&(j>=0)){return false;}
        
        if((j<0)&&(i>=0)){
            for(int ii=0; ii<=i; ii++){
                if(s[ii]!='*'){return false;}
            }
            return true;
        }
        
        if(dp[i][j]!=-1){return dp[i][j];}
        
        if(s[i]==t[j]||(s[i]=='?')){
            return dp[i][j] = f(i-1,j-1,s,t,dp);
        }
        
        if(s[i]=='*'){
            return dp[i][j] =  f(i-1,j,s,t,dp)||f(i,j-1,s,t,dp);
        }
        return dp[i][j] =  false;
        
        
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,p,s,dp);
        
    }
};


//normal not so good but still a solution 
class Solution2 {
public:
    
    bool f(int i , int j , string &s, string &t ,vector<vector<int>>&dp){
        //base case
        if(j==0 && i==0){
            return true;
        }
        
        if(j ==0 &&(i!=0)){
            if(t[0]=='*'){return dp[i][j] =true;}
            return dp[i][j]= false;
        }
        
        if(i==0 &&(j!=0)){
            while(j-1>=0 && t[j-1]=='*'){
                j--;
            }
            if(j==0){return dp[i][j]= true;}
            return dp[i][j]= false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //recurence 
        
        if(s[i-1]==t[j-1] ||(t[j-1]=='?')){
            return dp[i][j]= f(i-1,j-1,s,t,dp);
            
        }
        
        else if(t[j-1]=='*'){
            for(int k =0; k<=i; k++){
                if(f(i-k,j-1,s,t,dp)==true){return dp[i][j]= true;}
            }
            return dp[i][j] = false;
        }
        
        else{
            return dp[i][j] = false;
        }
        
        
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};
int main(){
    
    return 0;
}