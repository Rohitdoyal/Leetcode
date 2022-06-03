#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:    
    int maxProduct(vector<int>& nums) {
        //see there is mention that contiguous profuct 
        //so let's thinks
        //suppose if we multiply all element then it might be max what is problem here 
        // so problem is negetive number 
        //but if two neg number in line then that will not create any issue 
        
        int mx= nums[0];
        int mn= nums[0];
        int ans = nums[0];
        
        for(int i =1; i<nums.size(); i++){
            if(nums[i]<0){
                swap(mx,mn);
            }
            mx= max(nums[i],mx*nums[i]);
            mn= min(nums[i],mn*nums[i]);
            ans = max(ans, mx);
        }
        return ans ;
    }
};


//------------------------------------------------
//.. brute force method ..



class Solution2 {
public:
//     void printvec(vector<vector<int>>&v){
//         for(int i =0; i<v.size(); i++){
//             for(int j =0; j<v[i].size(); j++){
//                 cout<<v[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<"--------------------------\n";
//     }
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> v(n,vector<int>(n,0));
        //printvec(v);
        int ans =INT_MIN;
        for(int i =0; i<n; i++){
            for(int j =i; j<n ; j++){
                if(i==j){
                    v[i][j]= nums[i];
                }
                else{
                    v[i][j]= v[i][j-1]*nums[j];
                }
                ans = max(ans,v[i][j]);
            }
        }
        //printvec(v);
        
        return ans;
        
    }
};




int main(){
    
    return 0;
}