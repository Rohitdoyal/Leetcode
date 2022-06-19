#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
    int search(vector<int>&nums, int l, int r){
        if(l==r){
            return l;
        }

        int mid= l-(l-r)/2;
        if(nums[mid]>nums[mid+1]){
            return search(nums,l,mid);
        }
        return search(nums,mid+1,r);
        
    }
    
    int findPeakElement(vector<int>& nums) {
//         //base case is 
//         if(nums.size()==1){
//             return 0;
//         }
//         if(nums[0]>nums[1]){
//             return 0;
//         }
        
//         int n = nums.size();
//         if(nums[n-1]>nums[n-2]){
//             return n-1;
//         }
        
//         for(int i =1; i<n; i++){
//             if(nums[i]>nums[i-1] &&(nums[i]>nums[i+1])){
//                 return i;
//             }
//         }
//         return -1;
        
        return search(nums, 0, nums.size()-1);
    }
};


int main(){
    
    return 0;
}