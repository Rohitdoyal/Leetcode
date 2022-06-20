#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        map<int,int> m;
    
        while((n!=1) && (m[n]==0)){
            if(m[n]>=1){
                break;
            }
            m[n]+=1;
            
            int k =0;
            while(n!=0){
              
                k=k+(n%10)*(n%10);
                n=n/10;
            }
            n=k; 
        }
        //cout<<" n="<<n<<endl;
        if(n==1){
            return true;
        }
        return false;
        
    }
};

int main(){
    
    return 0;
}