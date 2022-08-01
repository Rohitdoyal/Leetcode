#include<bits/stdc++.h> 
using namespace std;

int main(){
    long long int n;
    cin>>n;

    vector<vector<long long int>>v(n,vector<long long int>(3));
    for (long long int i = 0; i <n; i++)
    {
        cin>>v[i][0];
        cin>>v[i][1];
        cin>>v[i][2];
    }
    for(long long int i =n-2;i>=0;i--){
        v[i][0]= v[i][0]+max(v[i+1][1],v[i+1][2]);
        v[i][1]= v[i][1]+max(v[i+1][0],v[i+1][2]);
        v[i][2]= v[i][2]+max(v[i+1][1],v[i+1][0]);

    }

    cout<<max(v[0][2],max(v[0][0],v[0][1]))<<endl;
    


    return 0;
}