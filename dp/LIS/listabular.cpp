#include<bits/stdc++.h> 
using namespace std;

// int **dp;

int dp[100][100];


int lis(int index,int prev,vector<int>&arr){
    cout<<"("<<index<<" "<<prev<<")\n";
    //base case simple
    if(index>=arr.size()){
        return dp[index][prev+1]= 0;
    }

    if(dp[index][prev+1]!=-1){
        return dp[index][prev+1];
    }

    int include =0;
    int not_include =0;

    if(prev==-1 ||(arr[index]>arr[prev])){
        include= 1+lis(index+1,index,arr);
    }
    not_include= lis(index+1,prev,arr);
   

    int ans = max(include,not_include);
    return dp[index][prev+1]  = ans;
}


int tabularlis(vector<int>arr){
    int n = arr.size();
    //int t[n][n+1]={0};
    vector<vector<int>>t(n+1,vector<int>(n+1,0));

    for(int i = n-1; i>=0; i--){
        for(int j = i-1; j>=-1; j--){
            int include =0;
            int not_include =0;

            if(j==-1 ||(arr[i]>arr[j])){
                include= 1+t[i+1][i+1];
            }
            not_include= t[i+1][j+1];
            int ans = max(include,not_include);
            t[i][j+1] = ans;
        }
    }

    // for(int i =0; i<t.size(); i++){
    //     for(int j =0; j<t[i].size(); j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return t[0][0];

}


int main(){
    //o(n2) wala soluition 
    vector<int> arr= {4,3,2,5,18,12,108,14};

    //index = 0->n-1 = n element 
    //prev =  -1->n-1 = n+1 element 
     int n = arr.size();
    

    for(int i =0; i<n; i++){
        for (int j = 0; j< n+1; j++)
        {   
            dp[i][j]=-1;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
     

    cout<<"LIS of ARR: "<<lis(0,-1,arr)<<endl;

    cout<<"tabular form ans ="<<tabularlis(arr)<<endl;


    return 0;
}