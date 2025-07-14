// Problem: B3851 [GESP202306 四级] 图像压缩
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3851
// Create Time: 2025-07-02 22:34:33

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

int n,len;
char a[25][45];
int lists[20];
int tmp[25][25];
struct node {
	int id,occ;
}clr[260];

int toDec(char x,char y) {
	int ans=0;
	if (isdigit(x)) ans+=16*(x-'0');
	else ans+=16*(x-'A'+10);
	if (isdigit(y)) ans+=y-'0';
	else ans+=y-'A'+10;
	return ans;
}

pair<char,char> toHex(int x) {
	char up,lo;
	int tmp;
	tmp=x/16;
	if (tmp>9) up='A'+tmp-10;
	else up=tmp+'0';
	tmp=x%16;
	if (tmp>9) lo='A'+tmp-10;
	else lo=tmp+'0';
	return {up,lo};
}

char zip(int x) {
	int res,now=0xffff;
	for (int i=0;i<16;i++)
		if (abs(x-lists[i])<now)
			now=abs(x-lists[i]), res=i;
	if (res<10) return '0'+res;
	else return 'A'+res-10;
}

signed main() {
	r(n);
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (int i=0;i<256;i++)
		clr[i].id=i;
	len=strlen(a[1]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=len;j++) {
			tmp[i][j]=toDec(a[i][j],a[i][j+1]);
			clr[tmp[i][j]].occ++;
			j++;
		}
	sort(clr,clr+256,[](node a,node b) {
		if (a.occ==b.occ) return a.id<b.id;
		return a.occ>b.occ;
	});
	for (int i=0;i<16;i++) {
		lists[i]=clr[i].id;
		auto buf=toHex(lists[i]);
		printf("%c%c",buf.first,buf.second);
	}
	putchar('\n');
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=len;j+=2)
			printf("%c",zip(tmp[i][j]));
		putchar('\n');
	}
	return 0;
}