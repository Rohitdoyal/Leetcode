#include<bits/stdc++.h> 
using namespace std;

int lis(vector<int>&arr){
    int n = arr.size();
    int *dp = new int[n];
    for(int i =0; i<n; i++){
        dp[i]= 1;
    }
    int maxi=1;

    for(int i =1; i<n; i++){
        for(int j =0; j<i-1; j++){
            if(arr[j]<arr[i]){
                dp[i]= max(dp[i],1+dp[j]);
                maxi= max(dp[i],maxi);
            }
        }
    }

    for(int i =0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return maxi;



}


int main(){
    vector<int> arr= {4,3,2,5,18,12,108,14};

    //index = 0->n-1 = n element 
    //prev =  -1->n-1 = n+1 element 
     int n = arr.size();

    cout<<"LIS of ARR: "<<lis(arr)<<endl;

    return 0;
}