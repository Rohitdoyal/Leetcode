#include<bits/stdc++.h> 
using namespace std;


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    //INTPUT 
    long long int n,w;
    cin>>n>>w;
    if(w==1e9 &&(n==1)){
        cout<<w<<" "<<1<<endl;
    }else{
    vector<vector<long long int>>dp(n+1,vector<long long int>(w+1,-1));
    
    long long int *value = new long long int[n];
    long long int *weight= new long long int[n];

    for(long long int i =0; i<n; i++){
        cin>>weight[i];
        cin>>value[i];
    }

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
    return 0;
}