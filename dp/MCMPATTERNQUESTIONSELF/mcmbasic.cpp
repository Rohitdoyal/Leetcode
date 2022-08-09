#include<bits/stdc++.h> 
using namespace std;


int f(int i , int j , int *arr){
    if(i==j){
        return 0;
    }


    int mini = INT_MAX;
    for(int k =i; k<j; k++){
        int res = arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr);
        
        mini = fmin(res,mini);
    }
    return mini;

}


int main(){
    int arr[] = {1,2,3,4};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    int ans = f(1,n-1,arr);
    cout<<"MINIMUM NUMBER OF OPERATION :"<<ans<<endl;

    return 0;
}