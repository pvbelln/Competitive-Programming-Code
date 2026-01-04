// Problem: P4715 【深基16.例1】淘汰赛
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4715
// Create Time: 2025-11-23 22:40:30

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
struct node {
	int id, x;
	bool operator < (const node &a) const {
		return x < a.x;
	}
};
vector<node> v, tmp;

signed main() {
	r(n);
	for (int _ = 1; _ <= 1 << n; _++)
		v.push_back({_, read()});
	while (v.size() > 2) {
		tmp.clear();
		for (int i = 0; i < 1 << n; i += 2) {
			tmp.push_back(max(v[i], v[i + 1]));
		}
		v = tmp;
		n--;
	}
	printf("%d\n", min(v[0], v[1]).id);
	return 0;
}