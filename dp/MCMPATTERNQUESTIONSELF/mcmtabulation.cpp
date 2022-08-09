#include<bits/stdc++.h> 
using namespace std;


// int f(int i , int j , int *arr,vector<vector<int>>&dp){
//     if(i==j){
//         return 0;
//     }

//     if(dp[i][j]!=-1){return dp[i][j];}

//     int mini = INT_MAX;
//     for(int k =i; k<j; k++){
//         int res = arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        
//         mini = fmin(res,mini);
//     }
//     return dp[i][j]= mini;

// }


int main(){
    int arr[] = {1,2,3,4,5};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // int ans = f(1,n-1,arr,dp);
    // cout<<"MINIMUM NUMBER OF OPERATION :"<<ans<<endl;

    //rules are easy ::
    //1. i -> 1->n-1  and j: n-1 to 1; reverse the loop 
    //2. complete base case
    //3. copy the recurese

    for(int i =0; i<n; i++){
        dp[i][i]= 0;
    }

    for(int i = n-1; i>0; i--){
        for(int j = i+1; j<=n-1; j++){
        
            int mini = INT_MAX;
            for(int k =i; k<j; k++){
                int res = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                
                mini = fmin(res,mini);
            }
            dp[i][j]= mini;

        }
    }
    cout<<"output is  = "<<dp[1][n-1];

    return 0;
}