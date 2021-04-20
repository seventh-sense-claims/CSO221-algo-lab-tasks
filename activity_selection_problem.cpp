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



struct Activity
{
    int start, finish;
};


bool compare(Activity a1, Activity a2)
{
    return (a1.finish < a2.finish);
}


void solve(Activity arr[], int n)
{
    sort(arr, arr + n, compare);

    cout << "Selected activities: ";

    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << "), ";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << "," << arr[j].finish << "), ";
            i = j;
        }
    }
}


int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    cout << endl;
    return 0;
}