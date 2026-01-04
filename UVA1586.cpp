// Problem: UVA1586 分子量 Molar mass
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA1586
// Create Time: 2025-08-24 21:19:33

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
string s,tmp;
double w['Z'];
double now,tot;
int num;

signed main() {
	r(n);
	w['C']=12.01;
	w['H']=1.008;
	w['O']=16.00;
	w['N']=14.01;
	while (n--) {
		cin>>s;
		s+="KSP";
		tmp="";
		tot=0;
		for (int i=0;i<(int)s.length()-3;i++) {
			if (isalpha(s[i])) tmp+=s[i];
			else continue;
			if (isalpha(s[i+1])) {
				tmp+="01";
			}
			else if (isalpha(s[i+2])) {
				tmp+='0';
				tmp+=s[i+1];
			}
			else {
				tmp+=s[i+1];
				tmp+=s[i+2];
			}
		}
		for (int i=0;i<(int)tmp.length()-2;i+=3) {
			now=w[tmp[i]];
			num=(tmp[i+1]-'0')*10+tmp[i+2]-'0';
			tot+=now*num;
		}
		printf("%.3f\n",tot);
	}
	return 0;
}