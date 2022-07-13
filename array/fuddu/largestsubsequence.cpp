#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        unordered_map<char,vector<int>>m;
        for(int i =0;i<s.length(); i++){
            m[s[i]].push_back(i);
        }
        
        int d= 0;
        for(auto x: m){
            int distance = x.second.back()-x.second[0];
            d= max(d,distance);
        }
        return d-1;
        
        
    }
};

int main(){
    
    return 0;
}