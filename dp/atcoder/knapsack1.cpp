#include<bits/stdc++.h> 
using namespace std;

//recursive code 
//see if wi>w then we will not include 
//else we can include or not 
//first traditional method 


long long int knapsack(long long int *value, long long int *weight, long long int w, long long int n,vector<vector<long long int>>&dp){
    if(w==0 ||n==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(weight[n-1]>w){
        //not include ;
        return dp[n][w] = knapsack(value,weight,w,n-1,dp);
    }
    else{
        return dp[n][w] = max(knapsack(value,weight,w,n-1,dp),value[n-1]+knapsack(value,weight,w-weight[n-1],n-1,dp));
    }
}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    //INTPUT 
    long long int n,w;
    cin>>n>>w;
    vector<vector<long long int>>dp(n+1,vector<long long int>(w+1,-1));

    long long int *value = new long long int[n];
    long long int *weight= new long long int[n];

    for(long long int i =0; i<n; i++){
        cin>>weight[i];
        cin>>value[i];
    }

    // long long int r = knapsack(value,weight,w,n,dp);
    // cout<<"recursive code :"<<r<<endl;

    //let's do it using tabulation form 
    long long int tp[n+1][w+1];
    for(long long int i =0; i<n+1; i++){
        tp[i][0]=0;
    }
    for(long long int i=0; i<w+1; i++){
        tp[0][i]=0;
    }

    for(long long int i =1; i<n+1; i++){
        for(long long int j = 1; j<w+1; j++){
            if(weight[i-1]>j){
                tp[i][j] = tp[i-1][j];
            }
            else{
                tp[i][j] =  max(tp[i-1][j],value[i-1]+tp[i-1][j-weight[i-1]]);
            }
        }
    }

    cout<<tp[n][w];
}