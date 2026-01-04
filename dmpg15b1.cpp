// Problem: B1 - Loner Phoner
// Contest: DMOJ - DMPG '15
// URL: https://dmoj.ca/problem/dmpg15b1
// Create Time: 2025-06-19 22:31:51

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
//#include<unordered_map>
//#define map unordered_map
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
using namespace std;
/*================*/

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int n;
string s;

signed main() {
	r(n);
	while (n--) {
		cin>>s;
		if (s.length()!=10 || (s.substr(0,3)!="416" && s.substr(0,3)!="647")) {
			puts("not a phone number");
			continue;
		}
		else {
			for (auto c:s)
				if (!isdigit(c)) {
					puts("not a phone number");
					continue;
				}
			cout<<"("<<s.substr(0,3)<<")-"<<s.substr(3,3)<<"-"<<s.substr(6,4)<<"\n";
		}
	}
	return 0;
}