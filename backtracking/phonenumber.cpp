#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    void f(int ind,string digits,vector<string>&ans,string temp ,string *m){
        if(ind>=digits.length()){
            ans.push_back(temp);
            return;
        }
        
        //string h= m[ind];
        int k = digits[ind]-'0';
        for(int i =0; i<m[k].length(); i++){
            temp.push_back(m[k][i]);
            f(ind+1,digits,ans,temp,m);
            temp.pop_back();
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        
        string m[] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""};
        
        vector<string>ans;
        string temp ;
        if(digits.size()==0){
            return ans;
        }
        f(0,digits,ans,temp,m);
        return ans;
    }
};
int main(){
    
    return 0;
}