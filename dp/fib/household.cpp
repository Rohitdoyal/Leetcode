#include<bits/stdc++.h> 
using namespace std;




class Solution {
public:

    int robOriginal(vector<int>& nums) {
        int a = 0, b = 0, res = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            res = max(b + nums[i], a);
            b = a;
            a = res;
        }
        
        return res;
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(robOriginal(numsA), robOriginal(numsB));
    }
};

int main(){
    //there is house in arr we need to find out max profit 
    //not choose consecutive 
    // int arr[]= {1,2,3,1};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // int a1 = household(arr,1,n-1);
    // int a2 = household(arr,0,n-2);
    // cout<<max(a1,a2)<<"<=answer";



    return 0;
}