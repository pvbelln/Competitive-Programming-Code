// Problem: Chopping Wood
// Contest: Kattis
// URL: https://open.kattis.com/problems/chopwood?tab=metadata
// Create Time: 2025-12-25 00:00:44

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
int x;
int deg[200005];
vector<int> lst, ans;
priority_queue<int> pq;

signed main() {
	r(n);
	for (int i = 0; i < n; i++) {
		r(x);
		lst.push_back(x);
		deg[x]++;
		if (i == n - 1 && x != n + 1) {
			puts("Error");
			return 0;
		}
	}
	for (int i = 1; i <= n + 1; i++)
		if (!deg[i])
			pq.push(-i);
	for (auto now : lst) {
		if (!pq.size()) {
			puts("Error");
			return 0;
		}
		x = -pq.top();
		pq.pop();
		ans.push_back(x);
		deg[now]--;
		if (!deg[now])
			pq.push(-now);
	}
	for (auto i : ans)
		printf("%d\n", i);
	return 0;
}