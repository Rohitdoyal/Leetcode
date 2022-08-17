#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>hold;
        
        
        //bitmasking simple logic 
        //0^ nums of i 
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        for(int i =0; i<pow(2,n); i++){
            int r= i;
            int j = n-1;
            vector<int>temp;
            while(r){
                if(r&1==1){
                    temp.push_back(nums[j]);
                }
                r=r/2;
                j--;
                
            }
            hold.insert(temp);
        }
        vector<vector<int>>ans;
        for(auto &x:hold){
            ans.push_back(x);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}