#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
      string ans;
        if(t.length()>s.length()){return ans;}
        if(t==s){return s;}
        
        unordered_map<char,int>mt,isit;
        for(auto x: t){
            mt[x]++;
            isit[x]=1;    
        }
        
        int  i = 0;
        int  j = 0;
        int count = 0;
        for(auto x: mt){
            count++;
        }
        
        
        int len =INT_MAX;
        
        while(i!=s.length()-1){
            while(count!=0 &&(j<s.length())){
                if(j>=s.length()){break;}
                if(isit[s[j]]){
                    mt[s[j]]--;
                    if(mt[s[j]]==0){
                        count--;
                    }  
                }
                j++;
            }
            

             if(count==0){
                if(j-i<len){
                    ans = s.substr(i,j-i);
                    len = j-i;
                }   
            }
            
            if(isit[s[i]]){
                mt[s[i]]++;
                if(mt[s[i]]>=1){
                    count++;
                }
            }
            i++;
            
        }
        if(count==0){
            if(j-i<len){
                ans = s.substr(i,j-i);
                len = j-i;}}
        return ans;
    }
};
int main(){
    
    return 0;
}