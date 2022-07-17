#include<bits/stdc++.h> 
using namespace std;


string Solution::multiple(int A) {
    
    if(A==1){
        return "1";
    }
    
    vector<string>v(A,"#");
    queue<int>q;//it will hold r 
    
    v[1]="1";
    q.push(1);
    while(q.size()>0){
        int r= q.front();
        q.pop();
        
        int r0 = (r*10)%A;
        int r1=  (r*10+1)%A;
        if(r0==0){ return v[r]+"0";}
        if(r1==0){return v[r]+"1";}
        
        if(v[r0]=="#"){v[r0]= v[r]+"0";
        q.push(r0);
        }
        if(v[r1]=="#"){v[r1]= v[r]+"1";
        q.push(r1);
        } 
    }
    
    return "1";


}

int main(){
    
    return 0;
}