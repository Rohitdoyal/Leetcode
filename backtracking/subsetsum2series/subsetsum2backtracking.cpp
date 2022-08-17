#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
    void subsetsum(int i ,vector<int>& nums , vector<int>temp,set<vector<int>>&ans){
        
        if(i>=nums.size()){
            ans.insert(temp);
            return;
        }
        
        subsetsum(i+1,nums,temp,ans);
        temp.push_back(nums[i]);
        subsetsum(i+1,nums,temp,ans);
        return;
        
    }
    
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //method 1 
        //normal subsetsum and then put into the set 
        
        sort(nums.begin(),nums.end());
        set<vector<int>>hold;
        vector<int>temp;
        
        subsetsum(0,nums ,temp,hold);
        vector<vector<int>>ans;
        for(auto& x: hold){
            ans.push_back(x);
        }
        return ans;
          
        
    }
};
int main(){
    
    return 0;
}