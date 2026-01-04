<<<<<<< HEAD
#include<iostream>
#include<cmath>
using namespace std;
int m,n;
string s;
signed main() {
	cin>>m;
	while (m--) {
		cin>>s;
		n=0;
		for (auto c:s)
			n+=pow(c-'0',s.length());
		if (n==stoi(s)) puts("T");
		else puts("F");
	}
=======
#include<iostream>
#include<cmath>
using namespace std;
int m,n;
string s;
signed main() {
	cin>>m;
	while (m--) {
		cin>>s;
		n=0;
		for (auto c:s)
			n+=pow(c-'0',s.length());
		if (n==stoi(s)) puts("T");
		else puts("F");
	}
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}