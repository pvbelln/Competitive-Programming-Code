// Problem: UVA394 Mapmaker
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA394
// Create Time: 2025-11-13 11:23:38

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
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

int N, R;
int B[100], D[100], L[100][15], U[100][15], C[100][15];

map<string, int> mp;

signed main() {
	r(N); r(R);
	for (int i = 1; i <= N; i++) {
		string Name;
		int CD;
		cin >> Name;
		mp[Name] = i;
		r(B[i]); r(CD); r(D[i]);
		C[i][D[i]] = CD;
		for (int j = 1; j <= D[i]; j++) {
			r(L[i][j]); r(U[i][j]);
		}
	}
	while (R--) {
		string Name;
		cin >> Name;
		cout << Name << "[";
		int arrayID = mp[Name];
		for (int j = D[arrayID] - 1; j > 0; j--)
			C[arrayID][j] = C[arrayID][j + 1] * (U[arrayID][j + 1] - L[arrayID][j + 1] + 1);
		C[arrayID][0] = B[arrayID];
		for (int j = 1; j <= D[arrayID]; j++)
			C[arrayID][0] -= C[arrayID][j] * L[arrayID][j];
		int addrAns = C[arrayID][0];
		for (int j = 1; j <= D[arrayID]; j++) {
			int tmp = read();
			addrAns += C[arrayID][j] * tmp;
			printf("%d", tmp);
			if (j < D[arrayID])
				printf(", ");
			else
				printf("] = %d\n", addrAns);
		}
	}
	return 0;
}

// 看懂题目就很简单