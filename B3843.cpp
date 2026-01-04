// Problem: B3843 [GESP202306 三级] 密码合规
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3843
// Create Time: 2025-07-02 10:38:09

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

string s,now;
string dict="!@#$";
int Up,Lo,Di,Te;

void judge() {
	if (now.length()<6 || now.length()>12) return;
	Up=Lo=Di=Te=0;
	for (auto c:now) {
		if (!(isdigit(c) || isalpha(c) || dict.find(c)!=-1)) return;
		if (c>='A' && c<='Z') Up=1;
		if (c>='a' && c<='z') Lo=1;
		if (isdigit(c)) Di=1;
		if (dict.find(c)!=-1) Te=1;
	}
	if (Up+Lo+Di<2 || Te==0) return;
	cout<<now<<"\n";
}

signed main() {
	cin>>s; s+=",";
	for (auto c:s) {
		if (c==',') judge(), now="";
		else now+=c;
	}
	return 0;
}