#include <iostream>
using namespace std;
using ll = long long int;
int tmp[500001] = {0, };
ll n, k, result = -1, cnt = 0;

void merge_sort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int arr[500001] = {0,};
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n-1);
    cout << result;

    return 0;
}

void merge_sort(int arr[], int p, int r) { //p, r은 인덱스
    if(p < r) {
        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r) {
    int i = p;
    int j = q+1;
    int t = 0;

    while (i<=q && j<=r) {
        if(arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        } else {
            tmp[t++] = arr[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = arr[i++];
    }
    while (j <= r) {
        tmp[t++] = arr[j++];
    }

    i = p;
    t = 0;

    while (i <= r) {
        arr[i++] = tmp[t++]; 
        cnt++;
        if(cnt == k) {result = arr[i-1];  return;}
    }
}