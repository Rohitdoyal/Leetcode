#include<bits/stdc++.h> 
using namespace std;


int f(int i , int j , int *arr,vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1){return dp[i][j];}

    int mini = INT_MAX;
    for(int k =i; k<j; k++){
        int res = arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        
        mini = fmin(res,mini);
    }
    return dp[i][j]= mini;

}


int main(){
    int arr[] = {1,2,3,4,5};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans = f(1,n-1,arr,dp);
    cout<<"MINIMUM NUMBER OF OPERATION :"<<ans<<endl;

    return 0;
}