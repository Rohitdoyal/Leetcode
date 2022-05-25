#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]); 
        }
        nums[2]= nums[2]+nums[0];
        for(int i =3; i<nums.size(); i++){
            nums[i]= nums[i]+max(nums[i-2],nums[i-3]);
        }
        
        return max(nums[n-1],max(nums[n-2],nums[n-3]));
    }
};

int main(){
    
    return 0;
}