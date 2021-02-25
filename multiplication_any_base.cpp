#include<bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

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



int power(int b, int e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}


ll length_equal(string &s, string &d) 
{ 
    ll l1 = s.size() , l2 = d.size(); 
    if (l1 < l2) 
    { 
        for (ll i = 0;i<(l2 - l1);i++) 
            s = '0' + s; 
        return l2; 
    } 
    else if(l2 < l1) 
    { 
        for (ll i = 0;i<(l1 - l2);i++) 
            d = '0' + d; 
    } 
    return l1; 
} 


string add(string a, string b, int base) {
    string res;
    int k = length_equal(a, b);
    int carry = 0;
    for (int i = k - 1; i >= 0; i--) {
        int fb = a[i] - '0', sb = b[i] - '0';
        int z=fb+sb+carry;
        carry=z/base;
        res.push_back(z%base+'0');
    }
    if (carry) res.push_back('0'+carry);
    reverse(res.begin(),res.end());
    return res;
}


ll multiply_1_bit(string a, string b) 
{ 
    ll x=a[0]-'0';
    ll y=b[0]-'0';
    ll z=x*y;

    return z; 
} 


//X  = (base^n/2 * xl) + xr
//Y  = (base^n/2 * yl) + yr
//XY = base^n(xl*yl) + base^(n/2)[(xl+xr)(yl+yr)-xl*yl+xr*yr] + xr*yr;
ll multiply_n_bit(string x, string y, int base) 
{ 

    ll n = length_equal(x, y); 

    if (n == 0) 
        return 0; 
    if (n == 1)
    { 
        ll product = multiply_1_bit(x, y);
        return product; 
    }

    ll left = n/2;  
    ll right = (n-left); 

    string xl = x.substr(0, left); 
    string xr = x.substr(left, right); 
 
    string yl = y.substr(0, left); 
    string yr = y.substr(left, right); 
 
    string s1 = add(xl, xr, base);
    string s2 = add(yl, yr, base);

    ll p1 = multiply_n_bit(xl, yl, base); 
    ll p2 = multiply_n_bit(xr, yr, base); 
    ll p3 = multiply_n_bit(s1, s2, base); 

    ll p = p1*(power(base,(2*right))) + (p3 - p1 - p2)*(power(base,right)) + p2;

    return p; 
} 
 

int main() 
{ 
    int base;
    cin >> base;
    string a,b;
    cin>>a>>b;
    // o/p is in decimal i.e. long long int
    ll ans=multiply_n_bit(a,b,base);
    cout<<ans;
}