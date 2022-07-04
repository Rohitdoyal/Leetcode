#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>v(n,1);
		//left to right 
        for(int i =1; i<n; i++){
            if(ratings[i]>ratings[i-1]){ v[i]= max(v[i],v[i-1]+1); }
        }
        
		//right to left 
        for(int i =n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){v[i]= max(v[i],v[i+1]+1);}
        }
        
        int ans =0;
        for(auto x: v){ans+=x; }
        return ans;
    }
};

int main(){
    
    return 0;
}