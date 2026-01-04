// Problem: UVA947 Master Mind Helper
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA947
// Create Time: 2025-07-12 14:08:25

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
char s[10];
int A,B,l;
char a[10];
int cnts[10],cntb[10];
int ans1,ans2;

int calc(int l,int A,int B) {
	int beg(1), endd, ans(0);
	for (int i=1;i<l;i++)
		beg=beg*10+1;
	endd=pow(10,l)-1;
	memset(cnts,0,sizeof cnts);
//	cerr<<beg<<" "<<endd<<"\n";
	for (int i=0;i<l;i++)
		cnts[s[i]-'0']++;
	for (int now=beg;now<=endd;now++) {
		sprintf(a,"%d",now);
		ans1=ans2=0;
		for (int i=0;i<10;i++)
			cntb[i]=0;
		for (int i=0;i<l;i++) {
			if (s[i]==a[i]) ans1++;
			if (a[i]=='0') goto END;
			cntb[a[i]-'0']++;
		}
		for (int i=0;i<10;i++)
			ans2+=min(cnts[i],cntb[i]);
		if (ans1==A && ans2-ans1==B)
			ans++;
		END:
		;
	}
	return ans;
}

signed main() {
	r(n);
	while (n--) {
		scanf("%s %d %d",s,&A,&B);
		l=strlen(s);
		printf("%d\n",calc(l,A,B));
	}
}

