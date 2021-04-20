#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

#define endl "\n"
#define deb(x)      cout << #x << " " << x << " ";
#define debl(x)     cout << #x << " " << x << "\n";



//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



int matrixChainRecursive(int a[], int i, int j)
{
    if(i == j)
        return 0;

    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int temp = matrixChainRecursive(a, i, k) + matrixChainRecursive(a, k+1, j) + a[i-1]*a[k]*a[j];
        ans = min(ans, temp);
    }

    return ans;
}


int matrixChainBottomUpDP(int a[], int n)
{
    int dp[n][n];

    for(int i=1; i<n; i++)
        dp[i][i] = 0;

    for(int L=2; L<n; L++)
    {
        for(int i=1; i<=n-L; i++)
        {
            int j = i+L-1;
            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j]);
        }
    }

    return dp[1][n-1];
}


void SHIV(){
    int n;
    cin >> n;
    int matrix[n];

    for(int i=0; i<n; i++)
        cin >> matrix[i];

    cout << "Recursive: " << matrixChainRecursive(matrix, 1, n-1) << endl;
    cout << "DP       : " << matrixChainBottomUpDP(matrix, n) << endl << endl;
}


int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        SHIV();
    }
    cerr << "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
// Time Complexity : O(n^3)
// Space Complexity: O(n^2)