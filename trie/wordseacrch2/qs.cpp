#include<bits/stdc++.h> 
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v[i];
    }
    long long int d;
    cin>>d;

    sort(v.begin(),v.end());

    int sum =0;
    for(int i =0; i<d; i++){
        sum+= v[i];
    }
    cout<<sum<<endl;

    return 0;
}