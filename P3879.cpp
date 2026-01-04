// Problem: P3879 [TJOI2010] 阅读理解
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3879
// Create Time: 2025-11-23 23:04:09

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<unordered_map>
#define map unordered_map
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

int N, L;
map<string, set<int>> mp;
string x;

signed main() {
	r(N);
	for (int i = 1; i <= N; i++) {
		r(L);
		while (L--) {
			cin >> x;
			mp[x].insert(i);
		}
	}
	r(N);
	while (N--) {
		cin >> x;
		for (auto& i : mp[x])
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}