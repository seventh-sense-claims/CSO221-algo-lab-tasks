#include <bits/stdc++.h>
#include <math.h>
#include <limits.h>
using namespace std;

#define endl "\n"
#define deb(x)      cout << #x << " " << x << " ";
#define debl(x)     cout << #x << " " << x << "\n";
#define V 4



//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



int n;


// O(n!)
int TSP(vector<vector<int>> graph,int s,int n)
{
	vector<int> vertex;
	for (int i = 0; i < n; i++)
		if (i != s)
			vertex.push_back(i);

	int min_path = INT_MAX;
	do {

		int current_pathweight = 0;

		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}


int main()
{
int i,j;
int x;
cin >> n;
	vector<vector<int>> g(n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>x;
			g[i].push_back(x);
		}
	}
	int s = 0;
	cout << TSP(g, s,n) << endl;
	return 0;
}
