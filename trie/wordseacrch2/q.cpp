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

    vector<int>r;
    for (int i = 0; i <n-1; i++)
    {
        /* code */
        for(int j =i+1; j<n; j++){
            int z= v[j]-v[i];
            cout<<"z is = "<<z<<endl;
            r.push_back(z);
        }
    }
    sort(r.begin(),r.end());

    int sum =0;
    while (d--)
    {
        /* code */
        sum+= r.back();
        r.pop_back();
        
    }
    cout<<"output is ="<<sum<<endl;
    
        
    return 0;
}