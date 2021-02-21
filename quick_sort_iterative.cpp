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
    int stack[high-low+1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0){
        high = stack[top--];
        low = stack[top--];

        int p = partition(a, low, high);

        if(p-1 > low){
            stack[++top] = low;
            stack[++top] = p-1;
        }

        if(p+1 < high){
            stack[++top] = p+1;
            stack[++top] = high;
        }
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