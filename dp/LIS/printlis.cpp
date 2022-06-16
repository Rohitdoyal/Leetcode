#include<bits/stdc++.h> 
using namespace std;

// int **dp;

int dp[100][100];


int lis(int index,int prev,vector<int>&arr,vector<int> &lisarray){
    //cout<<"("<<index<<" "<<prev<<")\n";
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
        lisarray.push_back(arr[index]);
        include= 1+lis(index+1,index,arr,lisarray);
        lisarray.pop_back();
    }
   
     not_include= lis(index+1,prev,arr,lisarray);
   
       
    

    int ans = max(include,not_include);
    return dp[index][prev+1]  = ans;

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
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
        
    }
     vector<int> lisarray;

    cout<<"LIS of ARR: "<<lis(0,-1,arr,lisarray)<<endl;

    cout<<"lis vector is ::\n";
    for (int i = 0; i < lisarray.size();  i++)
    {
        /* code */
        cout<<lisarray[i]<<" ";
    }

    

    


    return 0;
}