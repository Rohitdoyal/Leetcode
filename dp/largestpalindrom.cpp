#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        bool t[n][n];
        
        for(int i =n; i>=0; i--){
            for(int j = n-1; j>=i; j--){
                if(i==j){
                    t[i][j]= true ;
                }
                
                else if((j-i==1) &&(s[i]==s[j])){
                    t[i][j]= true;
                }
                else if((s[i]==s[j]) &&(t[i+1][j-1]==true)){
                    t[i][j] = true;
                }
                else{
                    t[i][j] = false;
                }
                
            }
        }
        
        int ans =0;
        int ansi =0;
        int ansj =0;
        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                if(t[i][j]== true){
                    int d= j-i+1;
                    if(ans<d){
                        ans = d;
                        ansi =i;
                        ansj = j;
                    }
                    
                }
            }
        }
        
        string h="";
        for(int i = ansi ; i<=ansj ; i++){
            h = h+s[i];
        }
        return h;
        
        
    }
};

int main(){
    
    return 0;
}