// Problem: Travel the Skies
// Contest: Kattis
// URL: https://open.kattis.com/problems/traveltheskies?tab=metadata
// Create Time: 2025-12-25 10:06:10

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

int k, n, m;
vector<pair<int, int>> g[15][10];  //g[airportID][dayID] -> < nxtID, maxPassenger >
int numPassenger[15], arrive[15][10];  //[airportID][DayID]

signed main() {
	r(k); r(n); r(m);
	while (m--) {
		int u, v, d, z;
		r(u); r(v); r(d); r(z);
		g[u][d].push_back({v, z});
	}
	for (int i = 0; i < k * n; i++) {
		int a, b, c;
		r(a); r(b); r(c);
		arrive[a][b] = c;
	}
	for (int day = 1; day <= n; day++) {
		for (int i = 1; i <= k; i++) {
			numPassenger[i] += arrive[i][day];
			for (auto flight : g[i][day]) {
				if (numPassenger[i] < flight.second)
					goto FAIL;
				numPassenger[i] -= flight.second;
				arrive[flight.first][day + 1] += flight.second;
			}
		}
	}
	puts("optimal");
	return 0;
	
	FAIL:
	
	puts("suboptimal");
	return 0;
}