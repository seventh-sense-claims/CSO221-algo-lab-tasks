#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define ll long long int 
#define ull unsigned long long int
#define deb(x) cout << #x << " " << x << " ";
#define debl(x) cout << #x << " " << x << "\n";


//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



string binary(ull num)
{
	string bin = "";
	while(num > 0)
	{
		if(num & 1)     bin = "1"+bin;
		else            bin = "0"+bin;
		num /= 2;
	}
	return bin;
}


int calcBits(string &s1, string &s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	int i;
	if(l2 > l1) 
	{
		for(i=0; i<l2-l1; i++) s1='0'+s1;
		return l2;
	}
	else if(l1 > l2)
	{
		for(i=0; i<l1-l2; i++) s2='0'+s2;
	}	
	return l1; 
}


string add(string s1,string s2)
{
	string res = "";
	int n = calcBits(s1, s2);
	int cur = 0, i;// store carry

	for(i=n-1; i>=0; i--)
	{
		int fb = s1[i]-'0';
		int sb = s2[i]-'0';
		int sum = (fb^sb^cur);
		res = to_string(sum)+res;
		cur = (fb&sb)|(sb&cur)|(fb&cur);
	}

	if(cur) res = "1"+res;
	return res;
}


//XY = 2^n(xl*yl) + 2^(n/2)[(xl+xr)(yl+yr)-xl*yl+xr*yr] + xr*yr;
ull multiply(string s1, string s2)
{
	int n = calcBits(s1, s2);
	if(n == 0) return 0;
	if(n == 1) return (s1[0]-'0')*(s2[0]-'0');

	int f = n/2;                      //first half bits
	int l = n-f;                      //second half bits

	string s1l = s1.substr(0, f);     
	string s1r = s1.substr(f, l);     
	string s2l = s2.substr(0, f);      
	string s2r = s2.substr(f, l);      
    
	ull pr1 = multiply(s1l, s2l);
	ull pr2 = multiply(s2r, s1r);
	ull pr = multiply(add(s1l, s1r), add(s2l, s2r));

	return pr1 * (1<<(2*l)) + (pr-pr2-pr1) * (1<<l) + pr2;
}


int main()
{
	string x, y;
	cin >> x >> y;
	ull ans = multiply(x, y);
	string ans2 = binary(ans);
	cout << ans << "\n";
	return 0;
}
//Time complexity:T(n)=3T(n/2)+O(n) on solving we get O(n^log2(3))