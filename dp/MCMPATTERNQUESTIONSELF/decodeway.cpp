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
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};