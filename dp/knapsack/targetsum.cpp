#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:  
    
      int countSubsets(vector<int>& nums, int n, int M)
    {
        int t[n+1][M+1];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        //t[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][M];  
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int M=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
         return countSubsets(nums, n, M);
    }  
};



//----better recursive approach ----
// class Solution {
// public:  
//     int f(int i , vector<int>&nums, int t){
//         if(i==nums.size()){
//             if(t==0){
//                 return 1;
//             }
//             else{
//                  return 0;
//             }
           
//         }
//         int left = f(i+1,nums,t+nums[i]);
//         int right = f(i+1,nums,t-nums[i]);
//         return left+right;
        
//     } 
   
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return f(0,nums,target);
        
//     }
// };



//recursive approach 
// class Solution {
// public:
    
//     void recur(int &ans, vector<int>&nums, int target,int sum ,int i){
//         if(i==nums.size()){
//             if(sum == target){
//                 ans++;
//             }
//             return ;
//         }
//         else{
//         recur(ans, nums, target, sum+nums[i],i+1);
//         recur(ans, nums, target, sum-nums[i],i+1);
//         return;
//         }
        
        
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int ans =0;
//         int sum =0;
//         int i =0;
        
//         recur(ans,nums,target,sum,i);
//         int ans2 = 0;
//         sum = 0;
//         i=0;
//         recur(ans2,nums,target,sum,i);
        
//         return (ans+ans2)/2;
        
//     }
// };
int main(){
    
    return 0;
}