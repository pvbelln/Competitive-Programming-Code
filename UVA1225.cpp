#include<bits/stdc++.h>
using namespace std;
int n,x;
string s;
int c[15];
int main() {
	cin>>n;
	while (n--) {
		cin>>x;
		s="";
		memset(c,0,sizeof c);
		for (int i=1;i<=x;i++)
			s+=to_string(i);
		for (auto C:s)
			c[C-'0']++;
		for (int i=0;i<=9;i++) {
			cout<<c[i];
			if (i<9) cout<<" ";
		}
		cout<<"\n";
	}
}