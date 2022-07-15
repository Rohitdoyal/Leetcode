#include<bits/stdc++.h> 
using namespace std;


int fibsum(int A) {
    int a1=1;
    int a2= 1;
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(1);
    
    while(a1<=A){
        int a3= a1+a2;
        fib.push_back(a3);
        a1= a2;
        a2= a3;
    }
    
    int ans =0;
    while(A!=0){
        if(fib.back()>A){
            fib.pop_back();
        }
        else{
            A=A-fib.back();
            ans++;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}