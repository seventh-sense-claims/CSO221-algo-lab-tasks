#include <iostream> 
using namespace std;
#define deb(x) cout << #x << " " << x << " ";
#define debl(x) cout << #x << " " << x << "\n";


//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



void merge(int *a, int l, int m, int h){
    int i = l, j = m+1, k = 0, temp[h-l+1];
    while(i<=m && j<=h){
        if(a[i] < a[j])     temp[k++] = a[i++];
        else                temp[k++] = a[j++];
    }
    
    while(i<=m)             temp[k++] = a[i++];
    while(j<=h)             temp[k++] = a[j++];

    for(int i=l; i<=h; i++)
        a[i] = temp[i-l];
}


void mergeSort(int *a, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}


void SHIV(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
    SHIV();
    return 0;
}