// Problem: Alphabet Animals
// Contest: Kattis
// URL: https://open.kattis.com/problems/alphabetanimals
// Create Time: 2025-12-25 11:12:55

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

string pre;
string dic[100005];
int cnt['z' + 1];
int n;

signed main() {
	cin >> pre;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dic[i];
		cnt[dic[i][0]]++;
	}
	for (int i = 0; i < n; i++)
		if (dic[i][0] == pre[(int)pre.size() - 1] && (cnt[dic[i][(int)dic[i].size() - 1]] == 0 || (cnt[dic[i][(int)dic[i].size() - 1]] == 1 && dic[i][(int)dic[i].size() - 1] == dic[i][0]))) {
			cout << dic[i] << "!\n";
			return 0;
		}
	for (int i = 0; i < n; i++)
		if (dic[i][0] == pre[(int)pre.size() - 1]) {
			cout << dic[i] << "\n";
			return 0;
		}
	cout << "?\n";
	return 0;
}