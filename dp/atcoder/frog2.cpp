#include<bits/stdc++.h> 
using namespace std;

int minof(vector<int>&dp, int k, vector<int>&a,int i){

    int j = k;
   //t--> i-1 to i-k||0;
   //dp[t]+a[i]-a[t];
   int ans = INT_MAX;
   for(int t= i-1; t>=i-k &&(t>=0); t--){
        ans = min(ans, dp[t]+abs(a[i]-a[t]));
   }
    return ans;

}

int main(){
    long long int n, k;
    cin>>n>>k;

    vector<int>a(n);
    for (int i = 0; i < n; i++){cin>>a[i];}

    vector<int>dp(n);
    dp[0]=0;
    dp[1]= dp[0]+abs(a[1]-a[0]);
    for(int i =2; i<n; i++){
        dp[i] = minof(dp,k,a,i);
    }

    cout<<dp[n-1]<<endl;

    return 0;
}