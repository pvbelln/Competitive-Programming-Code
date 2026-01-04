// Problem: UVA1584 环状序列 Circular Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA1584
// Create Time: 2025-08-23 17:07:25

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
		s+=s;
		string ans=s,now;
		for (int i=0;i<(int)s.length()/2;i++) {
			now="";
			for (int j=i;j<(int)s.length()/2+i;j++)
				now+=s[j];
			ans=min(ans,now);
		}
		cout<<ans<<"\n";
	}
	return 0;
}