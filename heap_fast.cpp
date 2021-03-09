#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

#define endl "\n"
#define deb(x)      cout << #x << " " << x << " ";
#define debl(x)     cout << #x << " " << x << "\n";



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


void DOWN_HEAPIFY(Node* cur) 
{
    Node *lt = cur->left, *rt = cur->right;

    if (lt != NULL and rt != NULL) 
    {
        int mn = min(lt->val, rt->val);
        if (cur->val > mn) 
        {
            if (lt->val > rt->val) 
            {
                swap(cur->val, rt->val);
                DOWN_HEAPIFY(rt);
            } 
            
            else 
            {
                swap(cur->val, lt->val);
                DOWN_HEAPIFY(lt);
            }
        } 
    } 
    
    else if (lt != NULL) 
    {
        if (cur->val > lt->val) 
        {
            swap(cur->val, lt->val);
            DOWN_HEAPIFY(lt);
        }
    } 
    
    else if (rt != NULL) 
    {
        if (cur->val > rt->val) {
            swap(cur->val, rt->val);
            DOWN_HEAPIFY(rt);
        }
    }
}


Node* FASTHEAP(int a[], int start, int end) 
{
    Node* cur = new Node();

    if (start > end) 
        return cur;

    if (start == end) 
    {
        cur->val = a[start];
        return cur;
    }

    cur->val = a[end];
    int mid = (end - start + 1) / 2; 

    if (mid) 
        cur->left = FASTHEAP(a, start, start + mid - 1);

    if (start + mid <= end - 1) 
        cur->right = FASTHEAP(a, start + mid, end - 1);
    
    DOWN_HEAPIFY(cur);
    return cur;
}


void printHeap(Node* root, int num) 
{
    if (root == NULL) return;
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
    
    Node* root = FASTHEAP(a, 0, n - 1); 
    printHeap(root, 1);

    cerr << "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
// T(n) = 2* T(n/2) + O(log(n))