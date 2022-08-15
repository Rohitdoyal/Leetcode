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
