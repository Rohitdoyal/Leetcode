#include<bits/stdc++.h> 
using namespace std;



//recursive code 
class Solution2 {
public:
    
    bool f(int s, vector<int>&nums,vector<int>&dp, int n){
        
        if(n-s==2){
            if(nums[s]==nums[s+1]){return true;}
            return false;
        }
        
        if(n-s==3){
             if((nums[s]==nums[s+1])&&(nums[s+1]==nums[s+2])){
                return true;
            }
            if((nums[s+1]-nums[s]==1) &&(nums[s+2]-nums[s+1]==1)){
                return true;
            }
            return false;
        }
        if(s>=nums.size()){
            return false;
        }
        if(dp[s]!=-1){
            return dp[s];
        }

        bool check1 =false;
        if(s+1<n && nums[s]==nums[s+1]){
            check1 = f(s+2,nums,dp,n);
        }
        //bool a1 = check1 && (f(s+2,nums,dp));
        
        bool check2= false;
        if((s+2<n)){
            if((nums[s+1]==nums[s] &&(nums[s+2]==nums[s])) ||(nums[s+1]-nums[s]==1 &&(nums[s+2]-nums[s+1]==1))){
                check2 = f(s+3,nums,dp,n);
            }
           
        }
       // bool a2= check2 && f(s+3,nums,dp);
        
        return dp[s] = check1||check2;
    }
    
    bool validPartition(vector<int>& nums) {
        int n  = nums.size();
        vector<int>dp(n+1,-1);
        return f(0,nums,dp,n);
        
    }
};



//solutioon tabulation method 
class Solution {
public:
    
    
    bool validPartition(vector<int>& nums) {
        int n  = nums.size();
        vector<int>dp(n+1,false);
        //f(0,nums,dp,n);
        
        
        if(n==2){
            if(nums[0]==nums[1]){
                return true;
            }
            return false;
        }
        if(n==3){
            if(nums[0]==nums[1] &&(nums[1]==nums[2])){
                return true;
            }
            else if(nums[1]-nums[0]==1 &&(nums[2]-nums[1]==1)){
                return true;
            }
            return false;
        }
        //base case 
        if(nums[n-2]==nums[n-1]){
            dp[n-2]= true;
        }
        
        if((nums[n-3]==nums[n-2] &&(nums[n-2]==nums[n-1])) ||((nums[n-2]-nums[n-3]==1) &&(nums[n-1]-nums[n-2]==1))){
            dp[n-3]= true;
        }
        
        
        for(int s =n-4; s>=0; s--){
            bool check1= false;
            if( nums[s]==nums[s+1]){
                check1 = dp[s+2];
            }
          

            bool check2= false;
            if((nums[s+1]==nums[s] &&(nums[s+2]==nums[s])) ||(nums[s+1]-nums[s]==1 &&(nums[s+2]-nums[s+1]==1))){
                check2 = dp[s+3];
            }
            
            dp[s] =check1 || check2;

        }
        
        
        return dp[0];
        
    }
};

int main(){
    
    return 0;
}