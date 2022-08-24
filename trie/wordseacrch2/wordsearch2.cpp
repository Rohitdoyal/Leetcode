#include<bits/stdc++.h> 
using namespace std;


 bool dfs(vector<vector<char>>& A ,int i,int j,string word,int idx){
        if((i<0) || (i>=A.size()) || (j<0) || (j>=A[0].size()) || (word[idx]!=A[i][j])){
             return false;
        }
       
        if(idx==word.length()-1){
            return true;
        }
        
        char c=A[i][j];
        A[i][j]='#';
        bool res=dfs(A,i+1,j,word,idx+1) ||
        dfs(A,i-1,j,word,idx+1) ||
        dfs(A,i,j+1,word,idx+1) ||
        dfs(A,i,j-1,word,idx+1);
        A[i][j]=c;
        return res;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        
        for(int i =0; i<board.size(); i++){
            for(int j =0; j<board[i].size(); j++){
                if(board[i][j]==word[0] && dfs(board,i,j,word,0)==true){
                        return true;
                    }
                }
            }
        
        return false;
    }
int main(){
    
    return 0;
}