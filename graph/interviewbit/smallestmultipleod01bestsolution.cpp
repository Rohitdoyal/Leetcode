#include<bits/stdc++.h> 
using namespace std;

string multiple(int A) {
    
    if(A==1){
        return "1";
    }
    
    vector<char>v(A,'#');
    queue<int>q;//it will hold r 
    vector<int>parent(A,-1);
    parent[1]=1;
    
    v[1]='1';
    q.push(1);
    while(q.size()>0){
        int r= q.front();
        q.pop();
        
        int r0 = (r*10)%A;
        int r1=  (r*10+1)%A;
        if(v[r0]=='#'){v[r0]= '0';
        parent[r0]= r;
        q.push(r0);
        }
        if(v[r1]=='#'){v[r1]= '1';
        parent[r1]=r;
        q.push(r1);
        } 
        if(r0==0||r1==0){break;}
        
    }
    
    string ans="";
    ans=ans+v[0];
    
    //0 to 1 path 
    
    int x=0;
    while(x!=1){
        x=parent[x];
        ans = v[x]+ans;
    }
    return ans;
}


int main(){
    
    return 0;
}