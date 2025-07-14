// Problem: UVA1103 古代象形符号 Ancient Messages
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA1103
// Create Time: 2025-06-19 17:00:00

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

int h, w, line_l, num, kase;
int a[205][205];
char tmp[205];
int dirx[]={-1,0,1,0};
int diry[]={0,1,0,-1};
int holes[1000];
char names[]={'W','A','K','J','S','D'};
vector<char> ans;

void conv(char c, int x, int y) {
	int base10;
	if (isdigit(c)) base10 = c - '0';
	else base10 = 10 + c - 'a';
	for (int i = 3; i >= 0; i--)
		if (base10 - (1 << i) >= 0) {
			base10 -= (1 << i);
			a[x][y + (3 - i)] = 1;
		}
	return;
}

void decode() {
	//在外面裹一圈 0
	for (int i=1;i<=h;i++) {
		scanf("%s",tmp);
		line_l=w;
		for (int j=0;j<line_l;j++)
			conv(tmp[j],i+1,j*4+2);
	}
	return;
}

void dfs(int x,int y,int rep,int kiss) {
	a[x][y]=rep;
	for (int i=0;i<4;i++) {
		int nx=x+dirx[i];
		int ny=y+diry[i];
		if (nx>0 && ny>0 && nx<h+3 && ny<w*4+3 && a[nx][ny]==kiss)
			dfs(nx,ny,rep,kiss);
	}
	return;
}

void Count() {
	num=1;
	dfs(1,1,-1,0);
	for (int i=1;i<=h+2;i++)
		for (int j=1;j<=w*4+2;j++)
			if (a[i][j]==1) {
				num++;
				dfs(i,j,num,1);
			}
	//这样所有的 0 都被包在图形里
}

void OCR() {
	memset(holes,0,sizeof holes);
	ans.clear();
	for (int i=1;i<=h+1;i++)
		for (int j=1;j<=w*4+1;j++)
			if (a[i][j]==0) {
				dfs(i,j,a[i][j-1],0);
				holes[a[i][j-1]-1]++;
			}
//	for (int i=1;i<num;i++)
//		cout<<holes[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<num;i++)
		ans.push_back(names[holes[i]]);
	sort(ans.begin(),ans.end());
}

void print() {
	printf("Case %d: ",kase);
	for (auto c:ans) printf("%c",c);
	printf("\n");
}

void debug() {
	for (int i=1;i<=h+2;i++) {
		for (int j=1;j<=w*4+2;j++) {
			if (a[i][j]==-1) cout<<' ';
			else cout<<a[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
}

signed main() {
//	freopen("sorain.txt","r",stdin);
//	freopen("sorakawaii.txt","w",stdout);
	while (scanf("%d%d",&h,&w)==2 && h) {
		memset(a,0,sizeof a);
		kase++;
		decode();
		Count();
		OCR();
		print();
		//debug();
	}
	return 0;
}