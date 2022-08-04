#include<bits/stdc++.h> 
using namespace std;


//dp[i1][i2][i3]


bool f(string s1, string s2, string s3, int i1,int i2, int i3, int n1, int n2, int n3, vector<vector<int>>&dp){
    if(i3==n3){return true;}

    if(i1==n1){
        int t= n3-i3;
        for (int i = 0; i <t; i++)
        {
            if(s3[i3+i]!=s2[i2+i]){return false;}
        }
        return true;
    }

    if(i2==n2){
        int t= n3-i3;
        for (int i = 0; i <t; i++)
        {
            if(s3[i3+i]!=s1[i1+i]){return false;}
        }
        return true;
    }

    if(dp[i1][i2]!=-1){return dp[i1][i2];}

    if((s1[i1]==s3[i3])&&(s2[i2]!=s3[i3])){
        return dp[i1][i2] = f(s1,s2,s3,i1+1,i2,i3+1,n1,n2,n3,dp);
    }
    if((s2[i2]==s3[i3])&&(s1[i1]!=s3[i3])){
        return dp[i1][i2] = f(s1,s2,s3,i1,i2+1,i3+1,n1,n2,n3,dp);
    }
    if((s1[i1]==s3[i3])&&(s2[i2]==s3[i3])){
        return dp[i1][i2] = (f(s1,s2,s3,i1+1,i2,i3+1,n1,n2,n3,dp)||f(s1,s2,s3,i1,i2+1,i3+1,n1,n2,n3,dp));
    }
    else{return dp[i1][i2] = false;}

}


void solve(string s1,string s2, string s3){
    if(s1.length()+s2.length()!=s3.length()){
        cout<<"NO"<<endl;
    }

    else{
        int n1= s1.length();
        int n2= s2.length();
        int n3= s3.length();

       // int dp[n1+1][n2+1];
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
      //  for(int i =0; i<n1+1; i++){for(int j=0; j<n2+1; j++){dp[i][j]=-1;}}

        bool t= f(s1,s2,s3,0,0,0,n1,n2,n3,dp);
        if(t){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}


int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    solve(s1,s2,s3);
    return 0;
}