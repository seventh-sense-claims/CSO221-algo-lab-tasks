#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

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



string add(string s1, string s2)
{
	string sum = "";
	int cur = 0;
	int l1 = s1.length()-1, l2 = s2.length()-1;
	while(l1>=0 || l2>=0 || cur)
	{
		cur += ((l1>=0)?s1[l1]-'0':0);
		cur += ((l2>=0)?s2[l2]-'0':0);
		sum = char((cur%2)+'0')+sum;
		cur /= 2;
		l1--;
		l2--;
	}
	return sum;
}


int main()
{
	string x, y;
	cin >> x >> y;
	int lx = x.length();
	int ly = y.length();
	string ans = "0", tp;
	for(int i=lx-1; i>=0; i--)
	{
		if(x[i] == '1') 
		{
			tp = y;
			for(int j=i+1; j<lx; j++) 
                tp += '0';
			ans = add(ans, tp);
            // debl(ans)
		}
	}
	cout << ans << "\n";
}