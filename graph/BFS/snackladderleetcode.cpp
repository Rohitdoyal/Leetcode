#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int sqn = n*n;
        vector<int>v(sqn+1,0);
        
        int k =1;
        
        
        int m = board[0].size();
        for(int i=n-1; i>=0; i--){
        if(n%2==0){
            if(i%2==0){
                for(int j =m-1;j>=0; j--){
                    if(board[i][j]==-1){
                        v[k] = k;
                    }
                    else{
                        v[k]=board[i][j];
                    }
                    k++;
                }
            }
            else{
                for(int j =0; j<m; j++){
                    if(board[i][j]==-1){
                        v[k] = k;
                    }
                    else{
                        v[k]=board[i][j];
                    }
                    k++;
                }
            }
        }
          
            else{
                if(i%2!=0){
                for(int j =m-1;j>=0; j--){
                    if(board[i][j]==-1){
                        v[k] = k;
                    }
                    else{
                        v[k]=board[i][j];
                    }
                    k++;
                }
            }
            else{
                for(int j =0; j<m; j++){
                    if(board[i][j]==-1){
                        v[k] = k;
                    }
                    else{
                        v[k]=board[i][j];
                    }
                    k++;
                }
            }
            }
            
            
        }
    long long int step = 0;
    queue<int>q;
    q.push(v[1]);
        v[1]=-1;
    
    while(q.empty()==false){
        int ng = q.size();
        step++;
        
        for(int i=0; i<ng; i++){
            int t= q.front();
            //cout<<"poped element "<<t<<" step :"<<step<<endl;
            q.pop();
            //now all 6 direction 
            if(t==sqn){
                return step-1;
            }
            if((t+1<=sqn)&& (v[t+1]!=-1) ){
                q.push(v[t+1]);
                v[t+1]=-1;
            }
            
            
            if((t+2<=sqn) && (v[t+2]!=-1) ){
                q.push(v[t+2]);
                v[t+2]=-1;
            }
            if((t+3<=sqn) && (v[t+3]!=-1) ){
                q.push(v[t+3]);
                v[t+3] = -1;
            }
            if((t+4<=sqn) && (v[t+4]!=-1) ){
                q.push(v[t+4]);
                v[t+4] =-1;
            }
            if((t+5<=sqn) && (v[t+5]!=-1 )){
                q.push(v[t+5]);
                v[t+5] = -1;
            }
            if((t+6<=sqn) && (v[t+6]!=-1) ){
                q.push(v[t+6]);
                v[t+6] = -1;
            }
            
        }
    }
    return -1;
        return 0;
        
        
    }
};

int main(){
    
    return 0;
}