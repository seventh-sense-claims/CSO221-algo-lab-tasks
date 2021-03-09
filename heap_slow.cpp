#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
const long long INF = 1e18;
const int N = 1e5 + 5;



//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



struct Node {
    int val;
    Node* left;
    Node* right;
};


Node* SLOWHEAP(int a[], int start, int end) 
{
    Node* cur = new Node();

    if (start > end) 
        return cur;

    if (start == end) 
    {
        cur->val = a[start];
        return cur;
    }

    int mn = a[start], l = start;

    for (int i = start; i <= end; i++) 
    {
        if (a[i] <= mn) 
        {
            mn = a[i];
            l = i;
        }
    }

    swap(a[l], a[end]);
    cur->val = a[end];
    int mid = (end - start + 1) / 2; 

    if (mid) 
        cur->left = SLOWHEAP(a, start, start + mid - 1);

    if (start + mid <= end - 1)
        cur->right = SLOWHEAP(a, start + mid, end - 1);
    
    return cur;
}


void printHeap(Node* root, int num)
{
    if (root == NULL) 
        return;

    cout << num << " " << (root->val) << endl;
    printHeap(root->left, 2 * num);
    printHeap(root->right, 2 * num + 1);
}


int main() 
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    Node* root = SLOWHEAP(a, 0, n - 1); 
    printHeap(root, 1);

    cerr << "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
// T(n) = 2*T(n/2) + O(n)