#include<bits/stdc++.h> 
using namespace std;



int mod(string num, int r, int n, string addstr){
    int f;
    if(addstr=="0"){
        f=0;
    }
    else{
        f=1;
    }
    
    //int f= addstr-"0";
    r=(10*r+(f))%n;
    
    return r;
    
}

string multiple(int A) {
    //what we are going to do we create all binary sequence because it hold only 1 and zero
    // we will just check is it divisiable by A or not that is it 
    
    string a="1";
    if(A==1){
        return a;
    }
    queue<pair<string,int>>q;
    q.push({a,1});
    set<int>st;
    
    while(q.size()>0){
        //cout<<"q is ="<<q.size();
        string h = q.front().first;
        int rg  = q.front().second;
        q.pop();
        
        //process h
        
        if(st.find(rg)==st.end()){
            st.insert(rg);
            int r= mod(h,rg,A,"0");
            if(r==0){
                return h+"0";
            }
            q.push({h+"0",r});
             r= mod(h,rg,A,"1");
            if(r==0){
                return h+"1";
            }
            
            q.push({h+"1",r});
        }
        //then 
        
    }
        
    
    
    return a;
}



// int mod(string num, int n){
    
//     int integer = 0;
//     for(int i =0; i<num.size(); i++){
//         integer = integer*10+(num[i]-'0');
//         integer= integer%n;
//     }
    
//     return integer;
    
// }

// string Solution::multiple(int A) {
//     //what we are going to do we create all binary sequence because it hold only 1 and zero
//     // we will just check is it divisiable by A or not that is it 
    
//     string a="1";
//     queue<string>q;
//     q.push(a);
//     set<int>st;
    
//     while(q.size()>0){
//         //cout<<"q is ="<<q.size();
//         string h = q.front();
//         q.pop();
        
//         //process h
//         int r= mod(h,A);
//         if(r==0){
//             return h;
//         }
//         if(st.find(r)==st.end()){
//             st.insert(r);
//             q.push(h+"0");
//             q.push(h+"1");
//         }
//         //then 
        
//     }
        
    
    
//     return a;
// }

int main(){
    
    return 0;
}