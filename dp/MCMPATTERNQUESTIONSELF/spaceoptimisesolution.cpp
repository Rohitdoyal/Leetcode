#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
 
    
    int numDecodings(string s) {
        int n = s.length();
        int a1 = 1;
        int a2 = 1;
        
        for(int i =n-1; i>=0; i--){
            int count =0;
            if(s[i]!='0'){
                count += a1;
            }

            if((i+1<n) && (s[i]=='1'||(s[i]=='2') && (s[i+1]<='6'))){
                    count += a2;
            }
            a2= a1;
            a1= count;
        }
        return a1;
    }
};
int main(){
    
    return 0;
}