// Problem: UVA599 The Forrest for the Trees
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA599
// Create Time: 2025-12-18 17:34:51

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

int T;
char s[255];
bool deg['Z' + 5];
int edgeCnt, nodeCnt, acornCnt;

signed main() {
	r(T);
	while (T--) {
		memset(deg, 0, sizeof deg);
		edgeCnt = nodeCnt = acornCnt = 0;
		while (1) {
			scanf("%s", s);
			if (s[0] == '*')
				break;
			edgeCnt++;
			deg[s[1]] = 1;
			deg[s[3]] = 1;
		}
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; i += 2) {
			nodeCnt++;
			if (!deg[s[i]])
				acornCnt++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", nodeCnt - edgeCnt - acornCnt, acornCnt);
	}
	return 0;
}