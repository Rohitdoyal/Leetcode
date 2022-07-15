#include<bits/stdc++.h> 
using namespace std;

int snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    //easy pesssy 
    
    //let's solve don't make any matrix kind thing we will do it in vector 
    vector<int>v(101,0);
    for(int i =0; i<101; i++){
        v[i]=i;
    }
    
    for(int i =0; i<A.size(); i++){
        v[A[i][0]] = A[i][1]; 
    }
    
    for(int i =0; i<B.size(); i++){
        v[B[i][0]] = B[i][1]; 
    }
    long long int step = 0;
    queue<int>q;
    q.push(1);
    
    while(q.empty()==false){
        int n = q.size();
        step++;
        
        for(int i=0; i<n; i++){
            int t= q.front();
            //cout<<"poped element "<<t<<" step :"<<step<<endl;
            q.pop();
            //now all 6 direction 
            if(t==100){
                return step-1;
            }
            if((t+1<=100)&& (v[t+1]!=-1) ){
                q.push(v[t+1]);
                v[t+1]=-1;
            }
            
            
            if((t+2<=100) && (v[t+2]!=-1) ){
                q.push(v[t+2]);
                v[t+2]=-1;
            }
            if((t+3<=100) && (v[t+3]!=-1) ){
                q.push(v[t+3]);
                v[t+3] = -1;
            }
            if((t+4<=100) && (v[t+4]!=-1) ){
                q.push(v[t+4]);
                v[t+4] =-1;
            }
            if((t+5<=100) && (v[t+5]!=-1 )){
                q.push(v[t+5]);
                v[t+5] = -1;
            }
            if((t+6<=100) && (v[t+6]!=-1) ){
                q.push(v[t+6]);
                v[t+6] = -1;
            }
            
        }
    }
    return -1;

}


int main(){
    
    return 0;
}