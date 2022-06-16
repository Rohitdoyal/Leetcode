#include<bits/stdc++.h> 
using namespace std;

int lis(vector<int>&arr){
    int n = arr.size();
    int *dp = new int[n];
    for(int i =0; i<n; i++){
        dp[i]= 1;
    }

    vector<int>hash(n,0);
    int maxi=1;
    int maxindex= 0;

    for(int i =1; i<n; i++){
        hash[i]=i;
        for(int j =0; j<i-1; j++){
            if(arr[j]<arr[i]){

                if(dp[j]+1>dp[i]){
                    dp[i]= dp[j]+1;
                    hash[i]= j;
                }

                if(maxi<dp[i]){
                    maxi = dp[i];
                    maxindex= i;
                }
                //maxi= max(dp[i],maxi);
            }
        }
    }
    cout<<"LIS array Is"<<endl;
    while (hash[maxindex]!=maxindex)
    {
        /* code */
        cout<<arr[maxindex]<<" ";
        maxindex= hash[maxindex];
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