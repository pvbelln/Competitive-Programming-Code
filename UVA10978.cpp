// Problem: UVA10978 Let's Play Magic!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10978
// Create Time: 2025-11-27 16:57:44

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

int N;
string ans[60];
bool taken[60];
string suit, str;

signed main() {
	while (1) {
		r(N);
		if (!N) break;
		int idx = 0;
		memset(taken, 0, sizeof taken);
		for (int i = 0; i < N; i++) {
			cin >> suit >> str;
			int cnt = 0;
			while (1) {
				if (!taken[idx]) cnt++;
				if (cnt == (int)str.length()) break;
				idx = (idx + 1) % N;
			}
			ans[idx] = suit;
			taken[idx] = 1;
		}
		for (int i = 0; i < N; i++) {
			cout << ans[i];
			if (i < N - 1)
				cout << " ";
			else
				cout << "\n";
		}
	}
	return 0;
}