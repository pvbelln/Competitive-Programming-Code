// Problem: UVA584 Bowling
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA584
// Create Time: 2025-09-08 22:31:01

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

string s;
char op;
int tot, now, foo;
vector<char> v;
int frames;

signed main() {
	while (1) {
		getline(cin,s);
		if (s[0]=='G') break;
		stringstream ss(s);
		tot=frames=0;
		v.clear();
		while (ss>>op) {
//			if (isdigit(op)) now=op-'0', tot+=now;
//			else if (op=='/') now=10-now, tot+=now, bonus=1;
//			else if (op=='X') tot+=pre=10, bonus=2;
//			if (bonus)
//				tot+=pre, bonus--;
			v.push_back(op);
		}
		for (int i=0;i<(int)v.size();i++) {
			op=v[i];
			if (isdigit(op)) {
				if (frames==10)
					continue;
				tot+=op-'0';
				if (foo)
					frames++, foo=0;
				else
					foo++;
			}
			else if (op=='/') {
				if (frames==10)
					continue;
				tot+=10-(v[i-1]-'0');
				frames++;
				foo=0;
				if (isdigit(v[i+1])) tot+=v[i+1]-'0';
				else tot+=10;
			}
			else if (op=='X') {
				if (frames==10)
					continue;
				frames++;
				foo=0;
				tot+=10;
				if (isdigit(v[i+1])) tot+=v[i+1]-'0';
				else tot+=10;
				if (isdigit(v[i+2])) tot+=v[i+2]-'0';
				else if (v[i+2]=='/') tot+=10-(v[i+1]-'0');
				else tot+=10;
			}
//			cerr<<tot<<" ";
		}
		printf("%d\n",tot);
//		cerr<<"\n";
	}
	return 0;
}