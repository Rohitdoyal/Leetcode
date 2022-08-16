#include<bits/stdc++.h> 
using namespace std;


void printvec(vector<string>&ans){
    for(int i =0; i<ans.size() ;i++){
        cout<<ans[i]<<" : "<<i+1<<endl;
    }
    cout<<"--------------------------------"<<endl;
}


void swap(string& s, int a , int b){
    char t= s[a];
    s[a]= s[b];
    s[b]= t;

}

void solve(string s, int l , int u , vector<string>& ans){
    if(l>=u){
        ans.push_back(s);
        return;
    }

    //forloop 
    for (int i = l; i <=u; i++)
    {
        /* code */
        //do 
        swap(s,l,i);
        //recure
        solve(s,l+1,u,ans);
        //undo 
        swap(s,l,i);

    }
    

}

int main(){
    string s="ABC";
    vector<string>ans;

    solve(s,0,s.length()-1,ans);
    printvec(ans);

    return 0;
}