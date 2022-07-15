#include<bits/stdc++.h> 
using namespace std;

int exist2(vector<string> &A, string B) {
    //let's do it using bfs
     
    queue<pair<int,int>> q;
     
    int posb=0;
    for(int i =0; i<A.size(); i++){
        for(int j =0; j<A[i].size(); j++){
            if(A[i][j]==B[posb]){
                q.push({i,j});
            }
        }
    }
    
    
    while(q.empty()==false){
        
        int n = q.size();
        posb++;
        //cout<<"----------------level ==--------------"<<n<<endl;
        for(int i =0; i<n; i++){
            int x= q.front().first;
            int y = q.front().second;
        //   cout<<"x ="<<x<<" y="<<y<<endl;
        //   cout<<"string  :: "<<A[x][y]<<endl;
            q.pop();
            
            if(x+1<A.size() &&(A[x+1][y]==B[posb])){
              //  cout<<x+1<<": "<<y<<endl;
                q.push({x+1,y});
            }
            
            if(x-1>=0 &&(A[x-1][y]==B[posb])){
              //  cout<<x-1<<": "<<y<<endl;
                q.push({x-1,y});
            }
            
            if(y+1<A[x].size() &&(A[x][y+1]==B[posb])){
              // cout<<x<<": "<<y+1<<endl;
                q.push({x,y+1});
            }
            if(y-1>=0 &&(A[x][y-1]==B[posb])){
              // cout<<x<<" : "<<y-1<<endl;
                q.push({x,y-1});
            }
        
        }
        if(posb==B.size()){
            return 1;
        }
    }
    return 0;
     
     
}
//-----------------------------------------
bool dfs(vector<string>A,int i,int j,string word,int idx){
    if(i<0 || i>=A.size() || j<0 || j>=A[0].length() || word[idx]!=A[i][j])
    return false;
    if(idx==word.length()-1)
    return true;
    bool res=dfs(A,i+1,j,word,idx+1) ||
    dfs(A,i-1,j,word,idx+1) ||
    dfs(A,i,j+1,word,idx+1) ||
    dfs(A,i,j-1,word,idx+1);
    return res;
}

int exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].length();j++){
            if(A[i][j]==B[0] && dfs(A,i,j,B,0))
            return 1;
        }
    }
return 0;
}

int main(){
    
    return 0;
}