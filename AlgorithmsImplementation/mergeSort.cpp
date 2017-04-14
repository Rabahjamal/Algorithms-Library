#include <bits/stdc++.h>
using namespace std;

void Merge(int A[],int left[], int nl, int right[], int nr) {
    int i = 0, j = 0, k = 0;

    while(i < nl && k < nr) {
        if(left[i] <= right[j]) {
            A[k] = left[i];
            k++, i++;
        }
        else {
            A[k] = right[j];
            k++, j++;
        }
    }
    while(i < nl)A[k++] = left[i++];
    while(j < nr)A[k++] = right[j++];
}
void mergeSort(int A[], int n) {

    if(n < 2)
        return;

    int lft[10], rt[10];
    int mid = n / 2;
    for(int i = 0; i < mid; i++) {
        lft[i] = A[i];
    }
    for(int i = mid; i < n; i++){
        rt[i - mid] = A[i];
    }
    mergeSort(lft, mid);
    mergeSort(rt,n - mid);
    Merge(A, lft, mid, rt,n - mid);
}

int main()
{
    int A[9] = {2, 3, 1, 5, 4, 9, 6, 12, 8};
    mergeSort(A, 9);
    return 0;
}
