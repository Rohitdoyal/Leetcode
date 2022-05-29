#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool t[n][n];
        
        int ans =0;
        for(int i =n; i>=0; i--){
            for(int j = n-1; j>=i; j--){
                if(i==j){
                    t[i][j]= true ;
                    ans++;
                }
                
                else if((j-i==1) &&(s[i]==s[j])){
                    t[i][j]= true;
                    ans++;
                }
                else if((s[i]==s[j]) &&(t[i+1][j-1]==true)){
                    t[i][j] = true;
                    ans++;
                }
                else{
                    t[i][j] = false;
                }  
            }
        }
        
        return ans;
  
    }
};


int main(){
    
    return 0;
}