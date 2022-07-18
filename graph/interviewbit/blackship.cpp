#include<bits/stdc++.h> 
using namespace std;



void dfs(vector<string> &A , int i , int j){
    A[i][j]='O';
    if(i-1>=0 &&(A[i-1][j]=='X')){
        dfs(A,i-1,j);
    }
    
    if((j-1>=0) &&(A[i][j-1]=='X')){
        dfs(A,i,j-1);
    }
    
    if(i+1<A.size() &&(A[i+1][j]=='X')){
        dfs(A,i+1,j);
    }
    
    if(j+1<A[0].size() &&(A[i][j+1]=='X')){
        dfs(A,i,j+1);
    }
    return;
    
}


int black(vector<string> &A) {
    
    int ans =0;
    
    for(int i =0; i<A.size(); i++){
        for(int j =0; j<A[i].size(); j++){
            if(A[i][j]=='X'){
                ans++;
                dfs(A,i,j);
            }
        }
    }  
    return ans;  
    
    
}
int main(){
    
    return 0;
}