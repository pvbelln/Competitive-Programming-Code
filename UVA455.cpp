// Problem: UVA455 周期串 Periodic Strings
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA455
// Create Time: 2025-08-25 14:16:21

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

int n,per;
string s;
bool f,subs;

signed main() {
	r(n);
	while (n--) {
		cin>>s;
		for (per=1;per<=s.length();per++) {
			f=1;
			if (s.length()%per!=0) continue;
			if (per==s.length()) break;
			for (int i=0;i<per;i++)
				for (int j=i;j<s.length();j+=per)
					if (s[i]!=s[j]) {
						f=0;
						goto chk;
					}
			chk:
			if (f) break;
			else continue;
		}
		if (subs) printf("\n");
		subs=1;
		printf("%d\n",per);
	}
	return 0;
}