#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << " " << x << " ";
#define debl(x) cout << #x << " " << x << "\n";



//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



struct Item
{
    int val, w;

    Item(int val, int w)
    {
        this->val = val;
        this->w = w;
    }
};


bool compare(struct Item a, struct Item b)
{
    double r1 = (double)a.val / (double)a.w;
    double r2 = (double)b.val / (double)b.w;
    return r1 > r2;
}


double solve(int W, struct Item arr[], int n)
{
    // O(n*logn)
    sort(arr, arr + n, compare);
    int cur = 0;
    double res = 0.0; //Result

    for (int i = 0; i < n; i++)
    {
        if (cur + arr[i].w <= W)
        {
            cur += arr[i].w;
            res += arr[i].val;
        }
        else
        {
            int remain = W - cur;
            res += arr[i].val * ((double)remain / (double)arr[i].w);
            break;
        }
    }

    return res;
}


int main()
{
    int W;
    cin >> W; //capacity of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Max Profit: " << solve(W, arr, n) << endl;
    return 0;
}