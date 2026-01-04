#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    double pi=0.0;
    for(int i=0;i<n;i++){
        if(i%2==0) pi+=1.0/(2*i+1);
        else pi-=1.0/(2*i+1);
    }
    pi*=4;
    cout<<fixed<<setprecision(6)<<pi<<endl;
    return 0;
}