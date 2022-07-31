#include<bits/stdc++.h> 
using namespace std;

int dp[100001];
int f(int i ,int* cost, int n){

    if(i>=n-1){
        return 0;
    }
   
    if(dp[i]!=-1){return dp[i];}

    else{
        return dp[i] =min(abs(cost[i]-cost[i+1])+f(i+1,cost,n),abs(cost[i]-cost[i+2])+f(i+2,cost,n));
    }
}

int main(){
    long long int n ;
    cin>>n;

    int v[n];
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
 
    memset(dp, -1, sizeof(dp));
    cout<<f(0,v,n)<<endl;
    
    return 0;
}