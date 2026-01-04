<<<<<<< HEAD
// Problem: UVA555 Bridge Hands
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA555
// Create Time: 2025-06-26 20:00:57

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
using namespace std;

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

#define cds pair<char,char>  //用两个字符描述一张牌

char Host;
string s,tmp;
vector<cds> a[5];//1234 SWNE
int now;
int ord[129];  //存储相对大小

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ord['D']=1; ord['S']=2; ord['H']=3;
	for (int i='2';i<='9';i++)
		ord[i]=i-'2';
	ord['T']=8; ord['J']=9; ord['Q']=10; ord['K']=11; ord['A']=12;
	while (cin>>Host && Host!='#') {
		switch (Host) {
			case 'S': now=1; break;
			case 'W': now=2; break;
			case 'N': now=3; break;
			case 'E': now=4; break;
		}
		cin>>s>>tmp;
		s+=tmp;  //两行输入合并为一行
		for (int i=1;i<=4;i++) a[i].clear();  //多测清空
		for (int i=0;i<104;i++) {
			now=now%4+1;
			a[now].push_back({s[i],s[++i]});  //模拟发牌
		}
		for (int i=1;i<=4;i++)
			sort(a[i].begin(),a[i].end(),[](cds a,cds b) {
				if (a.first==b.first) return ord[a.second]<ord[b.second];
				return ord[a.first]<ord[b.first];
			});
		cout<<"S:";
		for (auto c:a[1]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"W:";
		for (auto c:a[2]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"N:";
		for (auto c:a[3]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"E:";
		for (auto c:a[4]) cout<<" "<<c.first<<c.second; cout<<"\n";
		//先输出空格可以避免对最后一个元素的特殊处理
	}
	return 0;
}

/*
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
#
=======
// Problem: UVA555 Bridge Hands
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA555
// Create Time: 2025-06-26 20:00:57

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
using namespace std;

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

#define cds pair<char,char>  //用两个字符描述一张牌

char Host;
string s,tmp;
vector<cds> a[5];//1234 SWNE
int now;
int ord[129];  //存储相对大小

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ord['D']=1; ord['S']=2; ord['H']=3;
	for (int i='2';i<='9';i++)
		ord[i]=i-'2';
	ord['T']=8; ord['J']=9; ord['Q']=10; ord['K']=11; ord['A']=12;
	while (cin>>Host && Host!='#') {
		switch (Host) {
			case 'S': now=1; break;
			case 'W': now=2; break;
			case 'N': now=3; break;
			case 'E': now=4; break;
		}
		cin>>s>>tmp;
		s+=tmp;  //两行输入合并为一行
		for (int i=1;i<=4;i++) a[i].clear();  //多测清空
		for (int i=0;i<104;i++) {
			now=now%4+1;
			a[now].push_back({s[i],s[++i]});  //模拟发牌
		}
		for (int i=1;i<=4;i++)
			sort(a[i].begin(),a[i].end(),[](cds a,cds b) {
				if (a.first==b.first) return ord[a.second]<ord[b.second];
				return ord[a.first]<ord[b.first];
			});
		cout<<"S:";
		for (auto c:a[1]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"W:";
		for (auto c:a[2]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"N:";
		for (auto c:a[3]) cout<<" "<<c.first<<c.second; cout<<"\n";
		cout<<"E:";
		for (auto c:a[4]) cout<<" "<<c.first<<c.second; cout<<"\n";
		//先输出空格可以避免对最后一个元素的特殊处理
	}
	return 0;
}

/*
CQDTC4D8S7HTDAH7D2S3D6C6S6D9S4SAD7H2CKH5D3CTS8C9H3C3DQS9SQDJH8HAS2SKD4H4S5C7SJC8DKC5C2CAHQCJSTH6HKH9D5HJ
#
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
*/