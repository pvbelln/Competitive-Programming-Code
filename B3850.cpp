// Problem: B3850 [GESP202306 四级] 幸运数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3850
// Create Time: 2025-07-02 22:24:02

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

int n,tot;
string s,tmp;

int fun(char c) {
	int now=(c-'0')*7;
	if (now<10) return now;
	while (now>=10) {
		tmp=to_string(now);
		now=0;
		for (auto cc:tmp)
			now+=cc-'0';
	}
//	cerr<<now<<" ";
	return now;
}

signed main() {
	cin>>n;
	while (n--) {
		cin>>s;
		tot=0;
		for (int i=1;i<=s.length();i++) {
			if (i&1) tot+=fun(s[s.length()-i]);
			else tot+=s[s.length()-i]-'0';
		}
		if (tot%8) puts("F");
		else puts("T");
//		cerr<<"\n";
	}
	return 0;
}