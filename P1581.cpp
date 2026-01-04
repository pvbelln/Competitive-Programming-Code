// Problem: P1581 A+B Problem（升级版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1581
// Create Time: 2025-06-17 19:48:50

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

string s,s1,s2,sss;
int a[10],b[10],c[10];
vector<int> tmp;
bool f;

signed main() {
	cin>>s;
	int pos=s.find('+');
	s1=s.substr(0,pos);
	s2=s.substr(pos+1,s.length()-pos);
	
	stringstream ss(s1);
	while (getline(ss,sss,',')) tmp.push_back(stoi(sss));
	pos=6-tmp.size()+1;
	for (int i=pos;i<=6;i++)
		a[i]=tmp[i-pos];
		
	tmp.clear();
	
	ss.clear();
	ss.str(s2);
	while (getline(ss,sss,',')) tmp.push_back(stoi(sss));
	pos=6-tmp.size()+1;
	for (int i=pos;i<=6;i++)
		b[i]=tmp[i-pos];
	
	c[6]=(a[6]+b[6])%2;
	c[5]=(a[6]+b[6])/2;
	
	c[5]+=(a[5]+b[5]);
	c[4]+=c[5]/3;
	c[5]%=3;
	
	c[4]+=(a[4]+b[4]);
	c[3]+=c[4]/5;
	c[4]%=5;
	
	c[3]+=(a[3]+b[3]);
	c[2]+=c[3]/7;
	c[3]%=7;
	
	c[2]+=(a[2]+b[2]);
	c[1]+=c[2]/11;
	c[2]%=11;
	
	for (int i=1;i<=6;i++) {
		if (c[i]) f=1;
		if (f) {
			if (i!=6) cout<<c[i]<<",";
			else cout<<c[i]<<"\n";
		}
	}
	return 0;
}