#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']= 1;
        m['V']= 5;
        m['X']= 10;
        m['L']= 50;
        m['C']= 100;
        m['D']= 500;
        m['M']= 1000;
        
        int ans = 0;
        int n =s.length();
        vector<int>v(n,0);
        
        for(int i =0; i<n; i++){
            v[i] = m[s[i]];
        }
        //left bigger
        
        int i =0;
        while(i<n-1){
            if(v[i]<v[i+1]){
                ans+= (v[i+1]-v[i]);
                i++;
            }
            
            else{
                ans+=v[i];
            }
            i++;
        }
        
        if(i==n-1){
        ans = ans+v[n-1];}
        return ans;
        
    }
};
int main(){
    
    return 0;
}