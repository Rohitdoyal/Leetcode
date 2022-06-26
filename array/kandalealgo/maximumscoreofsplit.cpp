#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    
    int kandale(vector<int>&v){
        int ans =0;
         int sum =0;
        
        for(int i =0; i<v.size(); i++){
            sum+=v[i];
            ans= max(ans,sum);
            if(sum<0){
                sum =0;
            }
        }
        
        return ans;
        
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 = 0; 
        for(auto x: nums1){sum1+=x;}
        for(auto x: nums2){sum2+=x;}
        
        int n1 = nums1.size(); int n2= nums2.size();
        
        vector<int>diff21,diff12;
        for(int i =0; i<n1;i++){
            int a= nums1[i]-nums2[i];
            diff12.push_back(a);
            diff21.push_back(-a);
        }
        
        int result = max(sum1,sum2);
        //kandale algorithm 
        
        int d1= kandale(diff21);
        result = max(result, sum1+d1);
        
        int d2 = kandale(diff12);
        result = max(result, sum2+d2);
        return result;
             
    }
};

int main(){
    
    return 0;
}