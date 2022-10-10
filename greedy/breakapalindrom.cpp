#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string s){
        if(s.length()==1){
            return "";
        }
        
        int n = s.length();
        for(int i =0; i<n/2; i++){
            if(s[i]!='a'){
                s[i]='a';
                return s;
            }
        }
        
        s[n-1]='b';
        return s;
        
    }
};
int main(){
    
    return 0;
}