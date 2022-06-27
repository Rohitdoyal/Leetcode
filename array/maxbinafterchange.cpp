#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        
        int t =0;
        //point at first zero 
        while((t<binary.size()) &&(binary[t]!='0')){
            t++;
        }
        if(t==binary.size()){
            return binary;
        }
        
        //after that how many zero just count it
        int count =0;
        for(int j=t; j<binary.size();j++){
            if(binary[j]=='0'){
                count++;
            }
            
            
        }
        
        for(int r=0; r<count; r++){
            binary[t]='1';
            t++;
        }
        t=t-1;
        binary[t]='0';
        while(t!=binary.length()){
            
            t++;
            binary[t]='1';
        }
        return binary;
        
        
    }
};
int main(){
    
    return 0;
}