#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



int rep[100005];
vector<int> va;
int edg;
int a[100005];
struct edge
{
    int a, b, c;
} arr[100005];

bool cmp(edge x, edge y)
{
    return x.c < y.c;
}

void makeset(int n)
{
    for (int i = 1; i <= n; i++)
        rep[i] = i;
}

int findr(int x)
{
    if (rep[x] == x)
        return x;
    return rep[x] = findr(rep[x]);
}

int unio(int i, int sum)
{
    int x, y;
    x = findr(arr[i].a);
    y = findr(arr[i].b);
    if (x != y)
    {
        rep[x] = y;
        va.push_back(i);
        sum += arr[i].c;
    }
    return sum;
}

int unio2(int i, int sum)
{
    int x, y;
    x = findr(arr[i].a);
    y = findr(arr[i].b);
    if (x != y)
    {
        rep[x] = y;
        sum += arr[i].c;
        edg++;
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    makeset(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].a = a;
        arr[i].b = b;
        arr[i].c = c;
    }

    sort(arr, arr + m, cmp);

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = unio(i, sum);
    }

    cout << "MST: " << sum << "\n"; //cost

    int sec_best_mst = INT_MAX;

    // cout << "All other spanning trees:\n";

    int sum2 = 0;
    int j;
    for (j = 0; j < va.size(); j++)
    {
        makeset(n);
        edg = 0;
        for (int i = 0; i < m; i++)
        {
            if (i == va[j])
                continue;
            sum2 = unio2(i, sum2);
        }
        if (edg != n - 1)
        {
            sum2 = 0;
            continue;
        }
        // cout << sum2 << "\n";
        if (sec_best_mst > sum2 && sum2!=sum)
            sec_best_mst = sum2;
        sum2 = 0;
    }

    if(sec_best_mst == INT_MAX)
        cout << "Second Best MST does not exist!\n";
    else
        cout << "Second Best MST: " << sec_best_mst << "\n";
}
// O(m log n)