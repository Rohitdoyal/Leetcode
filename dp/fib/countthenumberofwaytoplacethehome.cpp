#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    
   
    int countHousePlacements(int n) {
        
        long long int a1=2;
        long long int a2= 3;
        
        if(n==1){
            return a1*a1;
        }
        if(n==2){
            return a2*a2;
        }
        
        
        for(long long  int i =2; i<n; i++){
            a2= (a2+a1)%1000000007;
            a1= (a2-a1)%1000000007;
            
        }
        return (a2%(1000000007))*(a2%(1000000007))%1000000007;
       
    }
};
int main(){
    
    return 0;
}