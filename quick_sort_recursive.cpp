#include <iostream>
#include <utility>
using namespace std;
#define deb(x) cout << #x << " " << x << " ";
#define debl(x) cout << #x << " " << x << "\n";


//    * * * * *   *       *   *   *       *   * * * * *       *       * * * * *
//    *           *       *   *    *     *    *       *      * *            *
//    * * * * *   * * * * *   *     *   *     * * * * *     *   *           *
//            *   *       *   *      * *      *     *      *  *  *    *     *
//    * * * * *   *       *   *       *       *       *   *       *   * * * *



int partition(int a[], int l, int h){
    int pivot = a[h];
    int i = l-1;

    for(int j=l; j<=h-1; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return i+1;
}


void quickSort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}


void SHIV(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
    SHIV();
    return 0;
}