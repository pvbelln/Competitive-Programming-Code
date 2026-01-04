<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
double l, c, n, l1;
double getArcAB(double a)
{
    return l*a/(2*sin(a/2));
}
int main() 
{
	while (1) {
		cin >> l >> n >>c;
		if (l<0) break;
		l1 = (1+n*c)*l;
		double left = 0, right = PI, mid;
		while(right - left >= 1e-12)
		{
		    mid = (left + right) / 2;
		    if(getArcAB(mid) < l1)
		       left = mid;
		    else
		       right = mid;
	    }
	    cout << fixed << setprecision(3) << l1/mid*(1-cos(mid/2)) << "\n";
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
double l, c, n, l1;
double getArcAB(double a)
{
    return l*a/(2*sin(a/2));
}
int main() 
{
	while (1) {
		cin >> l >> n >>c;
		if (l<0) break;
		l1 = (1+n*c)*l;
		double left = 0, right = PI, mid;
		while(right - left >= 1e-12)
		{
		    mid = (left + right) / 2;
		    if(getArcAB(mid) < l1)
		       left = mid;
		    else
		       right = mid;
	    }
	    cout << fixed << setprecision(3) << l1/mid*(1-cos(mid/2)) << "\n";
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}