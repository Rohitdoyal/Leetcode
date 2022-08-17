#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    void subset(int i , vector<int>&nums, vector<int>temp,vector<vector<int>>&ans){
       // if(i>=nums.size()){
            ans.push_back(temp);
         //   return;
        //}
        
        //subset(i+1,nums,temp,ans);
        
        for(int j =i; j<nums.size(); j++){
            if(j>i &&(nums[j]==nums[j-1])){
                continue;
            }
           //  subset(j+1,nums,temp,ans);
            temp.push_back(nums[j]);
            subset(j+1,nums,temp,ans);
            temp.pop_back();
        }
      //  return;
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        subset(0,nums,temp,ans);
        return ans;
        
    }
};
int main(){
    
    return 0;
}