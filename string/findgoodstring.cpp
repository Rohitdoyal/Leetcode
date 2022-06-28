#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>m;
        for(int i =0; i<s.length() ; i++){
            m[s[i]]++;
        }
        
        int ans =0;
        int n = s.length();
        unordered_map<int,char>r;
        for(auto x: m){
            char s= x.first;
            int fre= x.second;
            
            if(r[fre]=='\0'){
                r[fre]= s;
            }
            else{
                while(r[fre]!='\0' &&(fre!=0)){
                    ans++;
                    fre--;
                }
                (fre!=0)?(r[fre]=s):(r[fre]='\0');
            }
            
        }
        return ans;
        
        
    }
};

int main(){
    
    return 0;
}