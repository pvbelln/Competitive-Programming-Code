// Problem: UVA10928 My Dear Neighbours
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10928
// Create Time: 2025-12-25 10:44:37

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
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

int n, p, minn, x;
int deg[1005];
string s;
bool f;

signed main() {
	r(n);
	while (n--) {
		memset(deg, 0, sizeof deg);
		minn = 0x3f3f3f3f;
		f = 0;
		r(p);
		for (int i = 1; i <= p; i++) {
			getline(cin, s);
			stringstream ss(s);
			while (ss >> x)
				deg[i]++;
			minn = min(minn, deg[i]);
		}
		for (int i = 1; i <= p; i++)
			if (deg[i] == minn) {
				if (f) putchar(' ');
				f = 1;
				printf("%d", i);
			}
		putchar('\n');
	}
	return 0;
}