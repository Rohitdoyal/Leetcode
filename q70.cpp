#include<bits/stdc++.h> 
using namespace std;


//solution 1
//recursive approach
class Solution {
public:
    int climbStairs(int n) {
        //recursive solution 
        if(n<=3){
            return n; 
        }
        else {
            return climbStairs(n-1)+climbStairs(n-2);
        }
    }
};

//memoziation 
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3){
            return n; 
        }
        int a[n+1];
        a[0]=0;
        a[1]=1;
        a[2]=2;
        a[3]=3;
        
        for(int i =4; i<n+1; i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
};
//can we do it better then this ofcourse 
//using two pointer 
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3){
            return n; 
        } 
        int a1= 2;
        int a2= 3;
        int ans ;
        for(int i =4; i<n+1; i++){
            ans = a1+a2;
            a1=a2;
            a2= ans;
            
        }
        return ans;
    }
};

int main(){
    
    return 0;
}